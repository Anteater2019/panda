#include "panda/plugin.h"
#include "panda/plugin_plugin.h"

#include "syscalls2.h"
#include "syscalls2_info.h"

extern bool load_info;
#if {{ arch_conf.get('runner_target', arch_conf.qemu_target) }}
static bool first_load = true;
static syscall_info_t *info;
static syscall_meta_t *meta;
#endif

extern "C" {
#include "syscalls_ext_typedefs.h"
#include "syscall_ppp_extern_return.h"
}

void syscall_return_switch_{{os}}_{{arch}}(CPUState *cpu, target_ptr_t pc, const syscall_ctx_t *ctx) {
#if {{ arch_conf.get('runner_target', arch_conf.qemu_target) }}
	const syscall_info_t *call = NULL;
	syscall_info_t zero = {0};
	// only try this once
	if (first_load){
		first_load = false;
		if (load_info){
			sysinfo_load_profile(ctx->profile, &info, &meta);
		}
	}
	if (meta != NULL && ctx->no <= meta->max_generic) {
	  // If the syscall_info object from dso_info_....c doesn't have an entry
	  // for this syscall, we want to leave it as a NULL pointer
	  if (memcmp(&info[ctx->no], &zero, sizeof(syscall_info_t)) != 0) {
		call = &info[ctx->no];
	  }
	}
	switch (ctx->no) {
		{%- for syscall in syscalls %}
		// {{syscall.nos|join(', ')}} {{syscall.rettype}} {{syscall.name}} {{syscall.args_raw|join(' OR ')}}
		{% for no in syscall.nos %}case {{no}}: {%- endfor %} {
			{%- for arg in syscall.args %}
			{{arg.emit_temp_declaration()}}
			{%- endfor %}
			if (PPP_CHECK_CB(on_{{syscall.name}}_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				{%- for arg in syscall.args %}
				{{arg.emit_memcpy_ptr_to_temp()}}
				{%- endfor %}
			}
			PPP_RUN_CB(on_{{syscall.name}}_return, {{syscall.cargs}}) ;
		}; break;
		{%- endfor %}
		default:
			PPP_RUN_CB(on_unknown_sys_return, cpu, pc, ctx->no);
	}
	PPP_RUN_CB(on_all_sys_return, cpu, pc, ctx->no);
	PPP_RUN_CB(on_all_sys_return2, cpu, pc, call, ctx);
#endif
}

/* vim: set tabstop=4 softtabstop=4 noexpandtab ft=cpp: */
