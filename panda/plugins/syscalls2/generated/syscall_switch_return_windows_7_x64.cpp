#include "panda/plugin.h"
#include "panda/plugin_plugin.h"

#include "syscalls2.h"
#include "syscalls2_info.h"

extern bool load_info;
#if defined(TARGET_X86_64)
static bool first_load = true;
static syscall_info_t *info;
static syscall_meta_t *meta;
#endif

extern "C" {
#include "syscalls_ext_typedefs.h"
#include "syscall_ppp_extern_return.h"
}

void syscall_return_switch_windows_7_x64(CPUState *cpu, target_ptr_t pc, const syscall_ctx_t *ctx) {
#if defined(TARGET_X86_64)
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
		// 0 NTSTATUS NtMapUserPhysicalPagesScatter ['PVOID *VirtualAddresses', 'ULONG_PTR NumberOfPages', 'PULONG_PTR UserPfnArray']
		case 0: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtMapUserPhysicalPagesScatter_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtMapUserPhysicalPagesScatter_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 1 NTSTATUS NtWaitForSingleObject ['HANDLE Handle', 'BOOLEAN Alertable', 'PLARGE_INTEGER Timeout']
		case 1: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtWaitForSingleObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtWaitForSingleObject_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 2 NTSTATUS NtCallbackReturn ['PVOID OutputBuffer', 'ULONG OutputLength', 'NTSTATUS Status']
		case 2: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint32_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtCallbackReturn_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtCallbackReturn_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 3 NTSTATUS NtReadFile ['HANDLE FileHandle', 'HANDLE Event', 'PIO_APC_ROUTINE ApcRoutine', 'PVOID ApcContext', 'PIO_STATUS_BLOCK IoStatusBlock', 'PVOID Buffer', 'ULONG Length', 'PLARGE_INTEGER ByteOffset', 'PULONG Key']
		case 3: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint32_t arg6 = 0;
			uint64_t arg7 = 0;
			uint64_t arg8 = 0;
			if (PPP_CHECK_CB(on_NtReadFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtReadFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) ;
		}; break;
		// 4 NTSTATUS NtDeviceIoControlFile ['HANDLE FileHandle', 'HANDLE Event', 'PIO_APC_ROUTINE ApcRoutine', 'PVOID ApcContext', 'PIO_STATUS_BLOCK IoStatusBlock', 'ULONG IoControlCode', 'PVOID InputBuffer', 'ULONG InputBufferLength', 'PVOID OutputBuffer', 'ULONG OutputBufferLength']
		case 4: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint32_t arg5 = 0;
			uint64_t arg6 = 0;
			uint32_t arg7 = 0;
			uint64_t arg8 = 0;
			uint32_t arg9 = 0;
			if (PPP_CHECK_CB(on_NtDeviceIoControlFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtDeviceIoControlFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) ;
		}; break;
		// 5 NTSTATUS NtWriteFile ['HANDLE FileHandle', 'HANDLE Event', 'PIO_APC_ROUTINE ApcRoutine', 'PVOID ApcContext', 'PIO_STATUS_BLOCK IoStatusBlock', 'PVOID Buffer', 'ULONG Length', 'PLARGE_INTEGER ByteOffset', 'PULONG Key']
		case 5: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint32_t arg6 = 0;
			uint64_t arg7 = 0;
			uint64_t arg8 = 0;
			if (PPP_CHECK_CB(on_NtWriteFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtWriteFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) ;
		}; break;
		// 6 NTSTATUS NtRemoveIoCompletion ['HANDLE IoCompletionHandle', 'PVOID *KeyContext', 'PVOID *ApcContext', 'PIO_STATUS_BLOCK IoStatusBlock', 'PLARGE_INTEGER Timeout']
		case 6: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtRemoveIoCompletion_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtRemoveIoCompletion_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 7 NTSTATUS NtReleaseSemaphore ['HANDLE SemaphoreHandle', 'LONG ReleaseCount', 'PLONG PreviousCount']
		case 7: {
			uint64_t arg0 = 0;
			int32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtReleaseSemaphore_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(int32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtReleaseSemaphore_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 8 NTSTATUS NtReplyWaitReceivePort ['HANDLE PortHandle', 'PVOID *PortContext', 'PPORT_MESSAGE ReplyMessage', 'PPORT_MESSAGE ReceiveMessage']
		case 8: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtReplyWaitReceivePort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtReplyWaitReceivePort_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 9 NTSTATUS NtReplyPort ['HANDLE PortHandle', 'PPORT_MESSAGE ReplyMessage']
		case 9: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtReplyPort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtReplyPort_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 10 NTSTATUS NtSetInformationThread ['HANDLE ThreadHandle', 'THREADINFOCLASS ThreadInformationClass', 'PVOID ThreadInformation', 'ULONG ThreadInformationLength']
		case 10: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtSetInformationThread_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetInformationThread_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 11 NTSTATUS NtSetEvent ['HANDLE EventHandle', 'PLONG PreviousState']
		case 11: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtSetEvent_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetEvent_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 12 NTSTATUS NtClose ['HANDLE Handle']
		case 12: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtClose_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtClose_return, cpu, pc, arg0) ;
		}; break;
		// 13 NTSTATUS NtQueryObject ['HANDLE Handle', 'OBJECT_INFORMATION_CLASS ObjectInformationClass', 'PVOID ObjectInformation', 'ULONG ObjectInformationLength', 'PULONG ReturnLength']
		case 13: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryObject_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 14 NTSTATUS NtQueryInformationFile ['HANDLE FileHandle', 'PIO_STATUS_BLOCK IoStatusBlock', 'PVOID FileInformation', 'ULONG Length', 'FILE_INFORMATION_CLASS FileInformationClass']
		case 14: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint32_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryInformationFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtQueryInformationFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 15 NTSTATUS NtOpenKey ['PHANDLE KeyHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 15: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtOpenKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenKey_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 16 NTSTATUS NtEnumerateValueKey ['HANDLE KeyHandle', 'ULONG Index', 'KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass', 'PVOID KeyValueInformation', 'ULONG Length', 'PULONG ResultLength']
		case 16: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtEnumerateValueKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtEnumerateValueKey_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 17 NTSTATUS NtFindAtom ['PWSTR AtomName', 'ULONG Length', 'PRTL_ATOM Atom']
		case 17: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtFindAtom_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtFindAtom_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 18 NTSTATUS NtQueryDefaultLocale ['BOOLEAN UserProfile', 'PLCID DefaultLocaleId']
		case 18: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtQueryDefaultLocale_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryDefaultLocale_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 19 NTSTATUS NtQueryKey ['HANDLE KeyHandle', 'KEY_INFORMATION_CLASS KeyInformationClass', 'PVOID KeyInformation', 'ULONG Length', 'PULONG ResultLength']
		case 19: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryKey_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 20 NTSTATUS NtQueryValueKey ['HANDLE KeyHandle', 'PUNICODE_STRING ValueName', 'KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass', 'PVOID KeyValueInformation', 'ULONG Length', 'PULONG ResultLength']
		case 20: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtQueryValueKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryValueKey_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 21 NTSTATUS NtAllocateVirtualMemory ['HANDLE ProcessHandle', 'PVOID *BaseAddress', 'ULONG_PTR ZeroBits', 'PSIZE_T RegionSize', 'ULONG AllocationType', 'ULONG Protect']
		case 21: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint32_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtAllocateVirtualMemory_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtAllocateVirtualMemory_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 22 NTSTATUS NtQueryInformationProcess ['HANDLE ProcessHandle', 'PROCESSINFOCLASS ProcessInformationClass', 'PVOID ProcessInformation', 'ULONG ProcessInformationLength', 'PULONG ReturnLength']
		case 22: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryInformationProcess_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryInformationProcess_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 23 NTSTATUS NtWaitForMultipleObjects32 ['ULONG Count', 'LONG Handles[]', 'WAIT_TYPE WaitType', 'BOOLEAN Alertable', 'PLARGE_INTEGER Timeout']
		case 23: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtWaitForMultipleObjects32_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtWaitForMultipleObjects32_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 24 NTSTATUS NtWriteFileGather ['HANDLE FileHandle', 'HANDLE Event', 'PIO_APC_ROUTINE ApcRoutine', 'PVOID ApcContext', 'PIO_STATUS_BLOCK IoStatusBlock', 'PFILE_SEGMENT_ELEMENT SegmentArray', 'ULONG Length', 'PLARGE_INTEGER ByteOffset', 'PULONG Key']
		case 24: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint32_t arg6 = 0;
			uint64_t arg7 = 0;
			uint64_t arg8 = 0;
			if (PPP_CHECK_CB(on_NtWriteFileGather_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtWriteFileGather_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) ;
		}; break;
		// 25 NTSTATUS NtSetInformationProcess ['HANDLE ProcessHandle', 'PROCESSINFOCLASS ProcessInformationClass', 'PVOID ProcessInformation', 'ULONG ProcessInformationLength']
		case 25: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtSetInformationProcess_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetInformationProcess_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 26 NTSTATUS NtCreateKey ['PHANDLE KeyHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'ULONG TitleIndex', 'PUNICODE_STRING Class', 'ULONG CreateOptions', 'PULONG Disposition']
		case 26: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			uint32_t arg5 = 0;
			uint64_t arg6 = 0;
			if (PPP_CHECK_CB(on_NtCreateKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateKey_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6) ;
		}; break;
		// 27 NTSTATUS NtFreeVirtualMemory ['HANDLE ProcessHandle', 'PVOID *BaseAddress', 'PSIZE_T RegionSize', 'ULONG FreeType']
		case 27: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtFreeVirtualMemory_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtFreeVirtualMemory_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 28 NTSTATUS NtImpersonateClientOfPort ['HANDLE PortHandle', 'PPORT_MESSAGE Message']
		case 28: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtImpersonateClientOfPort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtImpersonateClientOfPort_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 29 NTSTATUS NtReleaseMutant ['HANDLE MutantHandle', 'PLONG PreviousCount']
		case 29: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtReleaseMutant_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtReleaseMutant_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 30 NTSTATUS NtQueryInformationToken ['HANDLE TokenHandle', 'TOKEN_INFORMATION_CLASS TokenInformationClass', 'PVOID TokenInformation', 'ULONG TokenInformationLength', 'PULONG ReturnLength']
		case 30: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryInformationToken_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryInformationToken_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 31 NTSTATUS NtRequestWaitReplyPort ['HANDLE PortHandle', 'PPORT_MESSAGE RequestMessage', 'PPORT_MESSAGE ReplyMessage']
		case 31: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtRequestWaitReplyPort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtRequestWaitReplyPort_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 32 NTSTATUS NtQueryVirtualMemory ['HANDLE ProcessHandle', 'PVOID BaseAddress', 'MEMORY_INFORMATION_CLASS MemoryInformationClass', 'PVOID MemoryInformation', 'SIZE_T MemoryInformationLength', 'PSIZE_T ReturnLength']
		case 32: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtQueryVirtualMemory_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryVirtualMemory_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 33 NTSTATUS NtOpenThreadToken ['HANDLE ThreadHandle', 'ACCESS_MASK DesiredAccess', 'BOOLEAN OpenAsSelf', 'PHANDLE TokenHandle']
		case 33: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtOpenThreadToken_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenThreadToken_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 34 NTSTATUS NtQueryInformationThread ['HANDLE ThreadHandle', 'THREADINFOCLASS ThreadInformationClass', 'PVOID ThreadInformation', 'ULONG ThreadInformationLength', 'PULONG ReturnLength']
		case 34: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryInformationThread_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryInformationThread_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 35 NTSTATUS NtOpenProcess ['PHANDLE ProcessHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'PCLIENT_ID ClientId']
		case 35: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtOpenProcess_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenProcess_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 36 NTSTATUS NtSetInformationFile ['HANDLE FileHandle', 'PIO_STATUS_BLOCK IoStatusBlock', 'PVOID FileInformation', 'ULONG Length', 'FILE_INFORMATION_CLASS FileInformationClass']
		case 36: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint32_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtSetInformationFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetInformationFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 37 NTSTATUS NtMapViewOfSection ['HANDLE SectionHandle', 'HANDLE ProcessHandle', 'PVOID *BaseAddress', 'ULONG_PTR ZeroBits', 'SIZE_T CommitSize', 'PLARGE_INTEGER SectionOffset', 'PSIZE_T ViewSize', 'SECTION_INHERIT InheritDisposition', 'ULONG AllocationType', 'WIN32_PROTECTION_MASK Win32Protect']
		case 37: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint64_t arg6 = 0;
			uint32_t arg7 = 0;
			uint32_t arg8 = 0;
			uint32_t arg9 = 0;
			if (PPP_CHECK_CB(on_NtMapViewOfSection_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint32_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtMapViewOfSection_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) ;
		}; break;
		// 38 NTSTATUS NtAccessCheckAndAuditAlarm ['PUNICODE_STRING SubsystemName', 'PVOID HandleId', 'PUNICODE_STRING ObjectTypeName', 'PUNICODE_STRING ObjectName', 'PSECURITY_DESCRIPTOR SecurityDescriptor', 'ACCESS_MASK DesiredAccess', 'PGENERIC_MAPPING GenericMapping', 'BOOLEAN ObjectCreation', 'PACCESS_MASK GrantedAccess', 'PNTSTATUS AccessStatus', 'PBOOLEAN GenerateOnClose']
		case 38: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint32_t arg5 = 0;
			uint64_t arg6 = 0;
			uint32_t arg7 = 0;
			uint64_t arg8 = 0;
			uint64_t arg9 = 0;
			uint64_t arg10 = 0;
			if (PPP_CHECK_CB(on_NtAccessCheckAndAuditAlarm_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint64_t));
				memcpy(&arg10, ctx->args[10], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAccessCheckAndAuditAlarm_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) ;
		}; break;
		// 39 NTSTATUS NtUnmapViewOfSection ['HANDLE ProcessHandle', 'PVOID BaseAddress']
		case 39: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtUnmapViewOfSection_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtUnmapViewOfSection_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 40 NTSTATUS NtReplyWaitReceivePortEx ['HANDLE PortHandle', 'PVOID *PortContext', 'PPORT_MESSAGE ReplyMessage', 'PPORT_MESSAGE ReceiveMessage', 'PLARGE_INTEGER Timeout']
		case 40: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtReplyWaitReceivePortEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtReplyWaitReceivePortEx_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 41 NTSTATUS NtTerminateProcess ['HANDLE ProcessHandle', 'NTSTATUS ExitStatus']
		case 41: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtTerminateProcess_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtTerminateProcess_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 42 NTSTATUS NtSetEventBoostPriority ['HANDLE EventHandle']
		case 42: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtSetEventBoostPriority_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetEventBoostPriority_return, cpu, pc, arg0) ;
		}; break;
		// 43 NTSTATUS NtReadFileScatter ['HANDLE FileHandle', 'HANDLE Event', 'PIO_APC_ROUTINE ApcRoutine', 'PVOID ApcContext', 'PIO_STATUS_BLOCK IoStatusBlock', 'PFILE_SEGMENT_ELEMENT SegmentArray', 'ULONG Length', 'PLARGE_INTEGER ByteOffset', 'PULONG Key']
		case 43: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint32_t arg6 = 0;
			uint64_t arg7 = 0;
			uint64_t arg8 = 0;
			if (PPP_CHECK_CB(on_NtReadFileScatter_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtReadFileScatter_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) ;
		}; break;
		// 44 NTSTATUS NtOpenThreadTokenEx ['HANDLE ThreadHandle', 'ACCESS_MASK DesiredAccess', 'BOOLEAN OpenAsSelf', 'ULONG HandleAttributes', 'PHANDLE TokenHandle']
		case 44: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint32_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtOpenThreadTokenEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenThreadTokenEx_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 45 NTSTATUS NtOpenProcessTokenEx ['HANDLE ProcessHandle', 'ACCESS_MASK DesiredAccess', 'ULONG HandleAttributes', 'PHANDLE TokenHandle']
		case 45: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtOpenProcessTokenEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenProcessTokenEx_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 46 NTSTATUS NtQueryPerformanceCounter ['PLARGE_INTEGER PerformanceCounter', 'PLARGE_INTEGER PerformanceFrequency']
		case 46: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtQueryPerformanceCounter_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryPerformanceCounter_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 47 NTSTATUS NtEnumerateKey ['HANDLE KeyHandle', 'ULONG Index', 'KEY_INFORMATION_CLASS KeyInformationClass', 'PVOID KeyInformation', 'ULONG Length', 'PULONG ResultLength']
		case 47: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtEnumerateKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtEnumerateKey_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 48 NTSTATUS NtOpenFile ['PHANDLE FileHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'PIO_STATUS_BLOCK IoStatusBlock', 'ULONG ShareAccess', 'ULONG OpenOptions']
		case 48: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint32_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtOpenFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtOpenFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 49 NTSTATUS NtDelayExecution ['BOOLEAN Alertable', 'PLARGE_INTEGER DelayInterval']
		case 49: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtDelayExecution_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtDelayExecution_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 50 NTSTATUS NtQueryDirectoryFile ['HANDLE FileHandle', 'HANDLE Event', 'PIO_APC_ROUTINE ApcRoutine', 'PVOID ApcContext', 'PIO_STATUS_BLOCK IoStatusBlock', 'PVOID FileInformation', 'ULONG Length', 'FILE_INFORMATION_CLASS FileInformationClass', 'BOOLEAN ReturnSingleEntry', 'PUNICODE_STRING FileName', 'BOOLEAN RestartScan']
		case 50: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint32_t arg6 = 0;
			uint32_t arg7 = 0;
			uint32_t arg8 = 0;
			uint64_t arg9 = 0;
			uint32_t arg10 = 0;
			if (PPP_CHECK_CB(on_NtQueryDirectoryFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint32_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint64_t));
				memcpy(&arg10, ctx->args[10], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtQueryDirectoryFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) ;
		}; break;
		// 51 NTSTATUS NtQuerySystemInformation ['SYSTEM_INFORMATION_CLASS SystemInformationClass', 'PVOID SystemInformation', 'ULONG SystemInformationLength', 'PULONG ReturnLength']
		case 51: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtQuerySystemInformation_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQuerySystemInformation_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 52 NTSTATUS NtOpenSection ['PHANDLE SectionHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 52: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtOpenSection_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenSection_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 53 NTSTATUS NtQueryTimer ['HANDLE TimerHandle', 'TIMER_INFORMATION_CLASS TimerInformationClass', 'PVOID TimerInformation', 'ULONG TimerInformationLength', 'PULONG ReturnLength']
		case 53: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryTimer_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryTimer_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 54 NTSTATUS NtFsControlFile ['HANDLE FileHandle', 'HANDLE Event', 'PIO_APC_ROUTINE ApcRoutine', 'PVOID ApcContext', 'PIO_STATUS_BLOCK IoStatusBlock', 'ULONG IoControlCode', 'PVOID InputBuffer', 'ULONG InputBufferLength', 'PVOID OutputBuffer', 'ULONG OutputBufferLength']
		case 54: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint32_t arg5 = 0;
			uint64_t arg6 = 0;
			uint32_t arg7 = 0;
			uint64_t arg8 = 0;
			uint32_t arg9 = 0;
			if (PPP_CHECK_CB(on_NtFsControlFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtFsControlFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) ;
		}; break;
		// 55 NTSTATUS NtWriteVirtualMemory ['HANDLE ProcessHandle', 'PVOID BaseAddress', 'PVOID Buffer', 'SIZE_T BufferSize', 'PSIZE_T NumberOfBytesWritten']
		case 55: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtWriteVirtualMemory_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtWriteVirtualMemory_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 56 NTSTATUS NtCloseObjectAuditAlarm ['PUNICODE_STRING SubsystemName', 'PVOID HandleId', 'BOOLEAN GenerateOnClose']
		case 56: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtCloseObjectAuditAlarm_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtCloseObjectAuditAlarm_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 57 NTSTATUS NtDuplicateObject ['HANDLE SourceProcessHandle', 'HANDLE SourceHandle', 'HANDLE TargetProcessHandle', 'PHANDLE TargetHandle', 'ACCESS_MASK DesiredAccess', 'ULONG HandleAttributes', 'ULONG Options']
		case 57: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint32_t arg5 = 0;
			uint32_t arg6 = 0;
			if (PPP_CHECK_CB(on_NtDuplicateObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtDuplicateObject_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6) ;
		}; break;
		// 58 NTSTATUS NtQueryAttributesFile ['POBJECT_ATTRIBUTES ObjectAttributes', 'PFILE_BASIC_INFORMATION FileInformation']
		case 58: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtQueryAttributesFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryAttributesFile_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 59 NTSTATUS NtClearEvent ['HANDLE EventHandle']
		case 59: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtClearEvent_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtClearEvent_return, cpu, pc, arg0) ;
		}; break;
		// 60 NTSTATUS NtReadVirtualMemory ['HANDLE ProcessHandle', 'PVOID BaseAddress', 'PVOID Buffer', 'SIZE_T BufferSize', 'PSIZE_T NumberOfBytesRead']
		case 60: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtReadVirtualMemory_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtReadVirtualMemory_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 61 NTSTATUS NtOpenEvent ['PHANDLE EventHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 61: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtOpenEvent_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenEvent_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 62 NTSTATUS NtAdjustPrivilegesToken ['HANDLE TokenHandle', 'BOOLEAN DisableAllPrivileges', 'PTOKEN_PRIVILEGES NewState', 'ULONG BufferLength', 'PTOKEN_PRIVILEGES PreviousState', 'PULONG ReturnLength']
		case 62: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtAdjustPrivilegesToken_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAdjustPrivilegesToken_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 63 NTSTATUS NtDuplicateToken ['HANDLE ExistingTokenHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'BOOLEAN EffectiveOnly', 'TOKEN_TYPE TokenType', 'PHANDLE NewTokenHandle']
		case 63: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtDuplicateToken_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtDuplicateToken_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 64 NTSTATUS NtContinue ['PCONTEXT ContextRecord', 'BOOLEAN TestAlert']
		case 64: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtContinue_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtContinue_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 65 NTSTATUS NtQueryDefaultUILanguage ['LANGID *DefaultUILanguageId']
		case 65: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtQueryDefaultUILanguage_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryDefaultUILanguage_return, cpu, pc, arg0) ;
		}; break;
		// 66 NTSTATUS NtQueueApcThread ['HANDLE ThreadHandle', 'PPS_APC_ROUTINE ApcRoutine', 'PVOID ApcArgument1', 'PVOID ApcArgument2', 'PVOID ApcArgument3']
		case 66: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueueApcThread_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueueApcThread_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 67 NTSTATUS NtYieldExecution ['']
		case 67: {
			if (PPP_CHECK_CB(on_NtYieldExecution_return) || PPP_CHECK_CB(on_all_sys_return2)) {
			}
			PPP_RUN_CB(on_NtYieldExecution_return, cpu, pc) ;
		}; break;
		// 68 NTSTATUS NtAddAtom ['PWSTR AtomName', 'ULONG Length', 'PRTL_ATOM Atom']
		case 68: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtAddAtom_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAddAtom_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 69 NTSTATUS NtCreateEvent ['PHANDLE EventHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'EVENT_TYPE EventType', 'BOOLEAN InitialState']
		case 69: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint32_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtCreateEvent_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtCreateEvent_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 70 NTSTATUS NtQueryVolumeInformationFile ['HANDLE FileHandle', 'PIO_STATUS_BLOCK IoStatusBlock', 'PVOID FsInformation', 'ULONG Length', 'FS_INFORMATION_CLASS FsInformationClass']
		case 70: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint32_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryVolumeInformationFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtQueryVolumeInformationFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 71 NTSTATUS NtCreateSection ['PHANDLE SectionHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'PLARGE_INTEGER MaximumSize', 'ULONG SectionPageProtection', 'ULONG AllocationAttributes', 'HANDLE FileHandle']
		case 71: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint32_t arg5 = 0;
			uint64_t arg6 = 0;
			if (PPP_CHECK_CB(on_NtCreateSection_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateSection_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6) ;
		}; break;
		// 72 NTSTATUS NtFlushBuffersFile ['HANDLE FileHandle', 'PIO_STATUS_BLOCK IoStatusBlock']
		case 72: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtFlushBuffersFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtFlushBuffersFile_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 73 NTSTATUS NtApphelpCacheControl ['APPHELPCOMMAND type', 'PVOID buf']
		case 73: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtApphelpCacheControl_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtApphelpCacheControl_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 74 NTSTATUS NtCreateProcessEx ['PHANDLE ProcessHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'HANDLE ParentProcess', 'ULONG Flags', 'HANDLE SectionHandle', 'HANDLE DebugPort', 'HANDLE ExceptionPort', 'ULONG JobMemberLevel']
		case 74: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			uint64_t arg6 = 0;
			uint64_t arg7 = 0;
			uint32_t arg8 = 0;
			if (PPP_CHECK_CB(on_NtCreateProcessEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtCreateProcessEx_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) ;
		}; break;
		// 75 NTSTATUS NtCreateThread ['PHANDLE ThreadHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'HANDLE ProcessHandle', 'PCLIENT_ID ClientId', 'PCONTEXT ThreadContext', 'PINITIAL_TEB InitialTeb', 'BOOLEAN CreateSuspended']
		case 75: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint64_t arg6 = 0;
			uint32_t arg7 = 0;
			if (PPP_CHECK_CB(on_NtCreateThread_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtCreateThread_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7) ;
		}; break;
		// 76 NTSTATUS NtIsProcessInJob ['HANDLE ProcessHandle', 'HANDLE JobHandle']
		case 76: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtIsProcessInJob_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtIsProcessInJob_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 77 NTSTATUS NtProtectVirtualMemory ['HANDLE ProcessHandle', 'PVOID *BaseAddress', 'PSIZE_T RegionSize', 'WIN32_PROTECTION_MASK NewProtectWin32', 'PULONG OldProtect']
		case 77: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtProtectVirtualMemory_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtProtectVirtualMemory_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 78 NTSTATUS NtQuerySection ['HANDLE SectionHandle', 'SECTION_INFORMATION_CLASS SectionInformationClass', 'PVOID SectionInformation', 'SIZE_T SectionInformationLength', 'PSIZE_T ReturnLength']
		case 78: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQuerySection_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQuerySection_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 79 NTSTATUS NtResumeThread ['HANDLE ThreadHandle', 'PULONG PreviousSuspendCount']
		case 79: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtResumeThread_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtResumeThread_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 80 NTSTATUS NtTerminateThread ['HANDLE ThreadHandle', 'NTSTATUS ExitStatus']
		case 80: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtTerminateThread_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtTerminateThread_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 81 NTSTATUS NtReadRequestData ['HANDLE PortHandle', 'PPORT_MESSAGE Message', 'ULONG DataEntryIndex', 'PVOID Buffer', 'SIZE_T BufferSize', 'PSIZE_T NumberOfBytesRead']
		case 81: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtReadRequestData_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtReadRequestData_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 82 NTSTATUS NtCreateFile ['PHANDLE FileHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'PIO_STATUS_BLOCK IoStatusBlock', 'PLARGE_INTEGER AllocationSize', 'ULONG FileAttributes', 'ULONG ShareAccess', 'ULONG CreateDisposition', 'ULONG CreateOptions', 'PVOID EaBuffer', 'ULONG EaLength']
		case 82: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint32_t arg5 = 0;
			uint32_t arg6 = 0;
			uint32_t arg7 = 0;
			uint32_t arg8 = 0;
			uint64_t arg9 = 0;
			uint32_t arg10 = 0;
			if (PPP_CHECK_CB(on_NtCreateFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint32_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint64_t));
				memcpy(&arg10, ctx->args[10], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtCreateFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) ;
		}; break;
		// 83 NTSTATUS NtQueryEvent ['HANDLE EventHandle', 'EVENT_INFORMATION_CLASS EventInformationClass', 'PVOID EventInformation', 'ULONG EventInformationLength', 'PULONG ReturnLength']
		case 83: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryEvent_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryEvent_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 84 NTSTATUS NtWriteRequestData ['HANDLE PortHandle', 'PPORT_MESSAGE Message', 'ULONG DataEntryIndex', 'PVOID Buffer', 'SIZE_T BufferSize', 'PSIZE_T NumberOfBytesWritten']
		case 84: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtWriteRequestData_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtWriteRequestData_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 85 NTSTATUS NtOpenDirectoryObject ['PHANDLE DirectoryHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 85: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtOpenDirectoryObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenDirectoryObject_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 86 NTSTATUS NtAccessCheckByTypeAndAuditAlarm ['PUNICODE_STRING SubsystemName', 'PVOID HandleId', 'PUNICODE_STRING ObjectTypeName', 'PUNICODE_STRING ObjectName', 'PSECURITY_DESCRIPTOR SecurityDescriptor', 'PSID PrincipalSelfSid', 'ACCESS_MASK DesiredAccess', 'AUDIT_EVENT_TYPE AuditType', 'ULONG Flags', 'POBJECT_TYPE_LIST ObjectTypeList', 'ULONG ObjectTypeListLength', 'PGENERIC_MAPPING GenericMapping', 'BOOLEAN ObjectCreation', 'PACCESS_MASK GrantedAccess', 'PNTSTATUS AccessStatus', 'PBOOLEAN GenerateOnClose']
		case 86: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint32_t arg6 = 0;
			uint32_t arg7 = 0;
			uint32_t arg8 = 0;
			uint64_t arg9 = 0;
			uint32_t arg10 = 0;
			uint64_t arg11 = 0;
			uint32_t arg12 = 0;
			uint64_t arg13 = 0;
			uint64_t arg14 = 0;
			uint64_t arg15 = 0;
			if (PPP_CHECK_CB(on_NtAccessCheckByTypeAndAuditAlarm_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint32_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint64_t));
				memcpy(&arg10, ctx->args[10], sizeof(uint32_t));
				memcpy(&arg11, ctx->args[11], sizeof(uint64_t));
				memcpy(&arg12, ctx->args[12], sizeof(uint32_t));
				memcpy(&arg13, ctx->args[13], sizeof(uint64_t));
				memcpy(&arg14, ctx->args[14], sizeof(uint64_t));
				memcpy(&arg15, ctx->args[15], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAccessCheckByTypeAndAuditAlarm_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15) ;
		}; break;
		// 87 NTSTATUS NtQuerySystemTime ['PLARGE_INTEGER SystemTime']
		case 87: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtQuerySystemTime_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQuerySystemTime_return, cpu, pc, arg0) ;
		}; break;
		// 88 NTSTATUS NtWaitForMultipleObjects ['ULONG Count', 'HANDLE Handles[]', 'WAIT_TYPE WaitType', 'BOOLEAN Alertable', 'PLARGE_INTEGER Timeout']
		case 88: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtWaitForMultipleObjects_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtWaitForMultipleObjects_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 89 NTSTATUS NtSetInformationObject ['HANDLE Handle', 'OBJECT_INFORMATION_CLASS ObjectInformationClass', 'PVOID ObjectInformation', 'ULONG ObjectInformationLength']
		case 89: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtSetInformationObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetInformationObject_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 90 NTSTATUS NtCancelIoFile ['HANDLE FileHandle', 'PIO_STATUS_BLOCK IoStatusBlock']
		case 90: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtCancelIoFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCancelIoFile_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 91 NTSTATUS NtTraceEvent ['HANDLE TraceHandle', 'ULONG Flags', 'ULONG FieldSize', 'PVOID Fields']
		case 91: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtTraceEvent_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtTraceEvent_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 92 NTSTATUS NtPowerInformation ['POWER_INFORMATION_LEVEL InformationLevel', 'PVOID InputBuffer', 'ULONG InputBufferLength', 'PVOID OutputBuffer', 'ULONG OutputBufferLength']
		case 92: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtPowerInformation_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtPowerInformation_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 93 NTSTATUS NtSetValueKey ['HANDLE KeyHandle', 'PUNICODE_STRING ValueName', 'ULONG TitleIndex', 'ULONG Type', 'PVOID Data', 'ULONG DataSize']
		case 93: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			uint32_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtSetValueKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetValueKey_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 94 NTSTATUS NtCancelTimer ['HANDLE TimerHandle', 'PBOOLEAN CurrentState']
		case 94: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtCancelTimer_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCancelTimer_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 95 NTSTATUS NtSetTimer ['HANDLE TimerHandle', 'PLARGE_INTEGER DueTime', 'PTIMER_APC_ROUTINE TimerApcRoutine', 'PVOID TimerContext', 'BOOLEAN WakeTimer', 'LONG Period', 'PBOOLEAN PreviousState']
		case 95: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			int32_t arg5 = 0;
			uint64_t arg6 = 0;
			if (PPP_CHECK_CB(on_NtSetTimer_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(int32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetTimer_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6) ;
		}; break;
		// 96 NTSTATUS NtAcceptConnectPort ['PHANDLE PortHandle', 'PVOID PortContext', 'PPORT_MESSAGE ConnectionRequest', 'BOOLEAN AcceptConnection', 'PPORT_VIEW ServerView', 'PREMOTE_PORT_VIEW ClientView']
		case 96: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtAcceptConnectPort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAcceptConnectPort_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 97 NTSTATUS NtAccessCheck ['PSECURITY_DESCRIPTOR SecurityDescriptor', 'HANDLE ClientToken', 'ACCESS_MASK DesiredAccess', 'PGENERIC_MAPPING GenericMapping', 'PPRIVILEGE_SET PrivilegeSet', 'PULONG PrivilegeSetLength', 'PACCESS_MASK GrantedAccess', 'PNTSTATUS AccessStatus']
		case 97: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint64_t arg6 = 0;
			uint64_t arg7 = 0;
			if (PPP_CHECK_CB(on_NtAccessCheck_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAccessCheck_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7) ;
		}; break;
		// 98 NTSTATUS NtAccessCheckByType ['PSECURITY_DESCRIPTOR SecurityDescriptor', 'PSID PrincipalSelfSid', 'HANDLE ClientToken', 'ACCESS_MASK DesiredAccess', 'POBJECT_TYPE_LIST ObjectTypeList', 'ULONG ObjectTypeListLength', 'PGENERIC_MAPPING GenericMapping', 'PPRIVILEGE_SET PrivilegeSet', 'PULONG PrivilegeSetLength', 'PACCESS_MASK GrantedAccess', 'PNTSTATUS AccessStatus']
		case 98: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			uint32_t arg5 = 0;
			uint64_t arg6 = 0;
			uint64_t arg7 = 0;
			uint64_t arg8 = 0;
			uint64_t arg9 = 0;
			uint64_t arg10 = 0;
			if (PPP_CHECK_CB(on_NtAccessCheckByType_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint64_t));
				memcpy(&arg10, ctx->args[10], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAccessCheckByType_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) ;
		}; break;
		// 99 NTSTATUS NtAccessCheckByTypeResultList ['PSECURITY_DESCRIPTOR SecurityDescriptor', 'PSID PrincipalSelfSid', 'HANDLE ClientToken', 'ACCESS_MASK DesiredAccess', 'POBJECT_TYPE_LIST ObjectTypeList', 'ULONG ObjectTypeListLength', 'PGENERIC_MAPPING GenericMapping', 'PPRIVILEGE_SET PrivilegeSet', 'PULONG PrivilegeSetLength', 'PACCESS_MASK GrantedAccess', 'PNTSTATUS AccessStatus']
		case 99: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			uint32_t arg5 = 0;
			uint64_t arg6 = 0;
			uint64_t arg7 = 0;
			uint64_t arg8 = 0;
			uint64_t arg9 = 0;
			uint64_t arg10 = 0;
			if (PPP_CHECK_CB(on_NtAccessCheckByTypeResultList_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint64_t));
				memcpy(&arg10, ctx->args[10], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAccessCheckByTypeResultList_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) ;
		}; break;
		// 100 NTSTATUS NtAccessCheckByTypeResultListAndAuditAlarm ['PUNICODE_STRING SubsystemName', 'PVOID HandleId', 'PUNICODE_STRING ObjectTypeName', 'PUNICODE_STRING ObjectName', 'PSECURITY_DESCRIPTOR SecurityDescriptor', 'PSID PrincipalSelfSid', 'ACCESS_MASK DesiredAccess', 'AUDIT_EVENT_TYPE AuditType', 'ULONG Flags', 'POBJECT_TYPE_LIST ObjectTypeList', 'ULONG ObjectTypeListLength', 'PGENERIC_MAPPING GenericMapping', 'BOOLEAN ObjectCreation', 'PACCESS_MASK GrantedAccess', 'PNTSTATUS AccessStatus', 'PBOOLEAN GenerateOnClose']
		case 100: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint32_t arg6 = 0;
			uint32_t arg7 = 0;
			uint32_t arg8 = 0;
			uint64_t arg9 = 0;
			uint32_t arg10 = 0;
			uint64_t arg11 = 0;
			uint32_t arg12 = 0;
			uint64_t arg13 = 0;
			uint64_t arg14 = 0;
			uint64_t arg15 = 0;
			if (PPP_CHECK_CB(on_NtAccessCheckByTypeResultListAndAuditAlarm_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint32_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint64_t));
				memcpy(&arg10, ctx->args[10], sizeof(uint32_t));
				memcpy(&arg11, ctx->args[11], sizeof(uint64_t));
				memcpy(&arg12, ctx->args[12], sizeof(uint32_t));
				memcpy(&arg13, ctx->args[13], sizeof(uint64_t));
				memcpy(&arg14, ctx->args[14], sizeof(uint64_t));
				memcpy(&arg15, ctx->args[15], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAccessCheckByTypeResultListAndAuditAlarm_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15) ;
		}; break;
		// 101 NTSTATUS NtAccessCheckByTypeResultListAndAuditAlarmByHandle ['PUNICODE_STRING SubsystemName', 'PVOID HandleId', 'HANDLE ClientToken', 'PUNICODE_STRING ObjectTypeName', 'PUNICODE_STRING ObjectName', 'PSECURITY_DESCRIPTOR SecurityDescriptor', 'PSID PrincipalSelfSid', 'ACCESS_MASK DesiredAccess', 'AUDIT_EVENT_TYPE AuditType', 'ULONG Flags', 'POBJECT_TYPE_LIST ObjectTypeList', 'ULONG ObjectTypeListLength', 'PGENERIC_MAPPING GenericMapping', 'BOOLEAN ObjectCreation', 'PACCESS_MASK GrantedAccess', 'PNTSTATUS AccessStatus', 'PBOOLEAN GenerateOnClose']
		case 101: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint64_t arg6 = 0;
			uint32_t arg7 = 0;
			uint32_t arg8 = 0;
			uint32_t arg9 = 0;
			uint64_t arg10 = 0;
			uint32_t arg11 = 0;
			uint64_t arg12 = 0;
			uint32_t arg13 = 0;
			uint64_t arg14 = 0;
			uint64_t arg15 = 0;
			uint64_t arg16 = 0;
			if (PPP_CHECK_CB(on_NtAccessCheckByTypeResultListAndAuditAlarmByHandle_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint32_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint32_t));
				memcpy(&arg10, ctx->args[10], sizeof(uint64_t));
				memcpy(&arg11, ctx->args[11], sizeof(uint32_t));
				memcpy(&arg12, ctx->args[12], sizeof(uint64_t));
				memcpy(&arg13, ctx->args[13], sizeof(uint32_t));
				memcpy(&arg14, ctx->args[14], sizeof(uint64_t));
				memcpy(&arg15, ctx->args[15], sizeof(uint64_t));
				memcpy(&arg16, ctx->args[16], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAccessCheckByTypeResultListAndAuditAlarmByHandle_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16) ;
		}; break;
		// 102 NTSTATUS NtAddBootEntry ['PBOOT_ENTRY BootEntry', 'PULONG Id']
		case 102: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtAddBootEntry_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAddBootEntry_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 103 NTSTATUS NtAddDriverEntry ['PEFI_DRIVER_ENTRY DriverEntry', 'PULONG Id']
		case 103: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtAddDriverEntry_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAddDriverEntry_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 104 NTSTATUS NtAdjustGroupsToken ['HANDLE TokenHandle', 'BOOLEAN ResetToDefault', 'PTOKEN_GROUPS NewState', 'ULONG BufferLength', 'PTOKEN_GROUPS PreviousState', 'PULONG ReturnLength']
		case 104: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtAdjustGroupsToken_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAdjustGroupsToken_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 105 NTSTATUS NtAlertResumeThread ['HANDLE ThreadHandle', 'PULONG PreviousSuspendCount']
		case 105: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtAlertResumeThread_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlertResumeThread_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 106 NTSTATUS NtAlertThread ['HANDLE ThreadHandle']
		case 106: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtAlertThread_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlertThread_return, cpu, pc, arg0) ;
		}; break;
		// 107 NTSTATUS NtAllocateLocallyUniqueId ['PLUID Luid']
		case 107: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtAllocateLocallyUniqueId_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAllocateLocallyUniqueId_return, cpu, pc, arg0) ;
		}; break;
		// 108 NTSTATUS NtAllocateReserveObject ['PHANDLE MemoryReserveHandle', 'POBJECT_ATTRIBUTES ObjectAttributes', 'MEMORY_RESERVE_TYPE Type']
		case 108: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtAllocateReserveObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtAllocateReserveObject_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 109 NTSTATUS NtAllocateUserPhysicalPages ['HANDLE ProcessHandle', 'PULONG_PTR NumberOfPages', 'PULONG_PTR UserPfnArray']
		case 109: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtAllocateUserPhysicalPages_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAllocateUserPhysicalPages_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 110 NTSTATUS NtAllocateUuids ['PULARGE_INTEGER Time', 'PULONG Range', 'PULONG Sequence', 'PCHAR Seed']
		case 110: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtAllocateUuids_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAllocateUuids_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 111 NTSTATUS NtAlpcAcceptConnectPort ['PHANDLE PortHandle', 'HANDLE ConnectionPortHandle', 'ULONG Flags', 'POBJECT_ATTRIBUTES ObjectAttributes', 'PALPC_PORT_ATTRIBUTES PortAttributes', 'PVOID PortContext', 'PPORT_MESSAGE ConnectionRequest', 'PALPC_MESSAGE_ATTRIBUTES ConnectionMessageAttributes', 'BOOLEAN AcceptConnection']
		case 111: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint64_t arg6 = 0;
			uint64_t arg7 = 0;
			uint32_t arg8 = 0;
			if (PPP_CHECK_CB(on_NtAlpcAcceptConnectPort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtAlpcAcceptConnectPort_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) ;
		}; break;
		// 112 NTSTATUS NtAlpcCancelMessage ['HANDLE PortHandle', 'ULONG Flags', 'PALPC_CONTEXT_ATTR MessageContext']
		case 112: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtAlpcCancelMessage_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcCancelMessage_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 113 NTSTATUS NtAlpcConnectPort ['PHANDLE PortHandle', 'PUNICODE_STRING PortName', 'POBJECT_ATTRIBUTES ObjectAttributes', 'PALPC_PORT_ATTRIBUTES PortAttributes', 'ULONG Flags', 'PSID RequiredServerSid', 'PPORT_MESSAGE ConnectionMessage', 'PULONG BufferLength', 'PALPC_MESSAGE_ATTRIBUTES OutMessageAttributes', 'PALPC_MESSAGE_ATTRIBUTES InMessageAttributes', 'PLARGE_INTEGER Timeout']
		case 113: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			uint64_t arg6 = 0;
			uint64_t arg7 = 0;
			uint64_t arg8 = 0;
			uint64_t arg9 = 0;
			uint64_t arg10 = 0;
			if (PPP_CHECK_CB(on_NtAlpcConnectPort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint64_t));
				memcpy(&arg10, ctx->args[10], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcConnectPort_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) ;
		}; break;
		// 114 NTSTATUS NtAlpcCreatePort ['PHANDLE PortHandle', 'POBJECT_ATTRIBUTES ObjectAttributes', 'PALPC_PORT_ATTRIBUTES PortAttributes']
		case 114: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtAlpcCreatePort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcCreatePort_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 115 NTSTATUS NtAlpcCreatePortSection ['HANDLE PortHandle', 'ULONG Flags', 'HANDLE SectionHandle', 'SIZE_T SectionSize', 'PALPC_HANDLE AlpcSectionHandle', 'PSIZE_T ActualSectionSize']
		case 115: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtAlpcCreatePortSection_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcCreatePortSection_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 116 NTSTATUS NtAlpcCreateResourceReserve ['HANDLE PortHandle', 'ULONG Flags', 'SIZE_T MessageSize', 'PALPC_HANDLE ResourceId']
		case 116: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtAlpcCreateResourceReserve_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcCreateResourceReserve_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 117 NTSTATUS NtAlpcCreateSectionView ['HANDLE PortHandle', 'ULONG Flags', 'PALPC_DATA_VIEW_ATTR ViewAttributes']
		case 117: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtAlpcCreateSectionView_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcCreateSectionView_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 118 NTSTATUS NtAlpcCreateSecurityContext ['HANDLE PortHandle', 'ULONG Flags', 'PALPC_SECURITY_ATTR SecurityAttribute']
		case 118: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtAlpcCreateSecurityContext_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcCreateSecurityContext_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 119 NTSTATUS NtAlpcDeletePortSection ['HANDLE PortHandle', 'ULONG Flags', 'ALPC_HANDLE SectionHandle']
		case 119: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtAlpcDeletePortSection_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcDeletePortSection_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 120 NTSTATUS NtAlpcDeleteResourceReserve ['HANDLE PortHandle', 'ULONG Flags', 'ALPC_HANDLE ResourceId']
		case 120: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtAlpcDeleteResourceReserve_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcDeleteResourceReserve_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 121 NTSTATUS NtAlpcDeleteSectionView ['HANDLE PortHandle', 'ULONG Flags', 'PVOID ViewBase']
		case 121: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtAlpcDeleteSectionView_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcDeleteSectionView_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 122 NTSTATUS NtAlpcDeleteSecurityContext ['HANDLE PortHandle', 'ULONG Flags', 'ALPC_HANDLE ContextHandle']
		case 122: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtAlpcDeleteSecurityContext_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcDeleteSecurityContext_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 123 NTSTATUS NtAlpcDisconnectPort ['HANDLE PortHandle', 'ULONG Flags']
		case 123: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtAlpcDisconnectPort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtAlpcDisconnectPort_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 124 NTSTATUS NtAlpcImpersonateClientOfPort ['HANDLE PortHandle', 'PPORT_MESSAGE PortMessage', 'PVOID Reserved']
		case 124: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtAlpcImpersonateClientOfPort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcImpersonateClientOfPort_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 125 NTSTATUS NtAlpcOpenSenderProcess ['PHANDLE ProcessHandle', 'HANDLE PortHandle', 'PPORT_MESSAGE PortMessage', 'ULONG Flags', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 125: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtAlpcOpenSenderProcess_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcOpenSenderProcess_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 126 NTSTATUS NtAlpcOpenSenderThread ['PHANDLE ThreadHandle', 'HANDLE PortHandle', 'PPORT_MESSAGE PortMessage', 'ULONG Flags', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 126: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtAlpcOpenSenderThread_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcOpenSenderThread_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 127 NTSTATUS NtAlpcQueryInformation ['HANDLE PortHandle', 'ALPC_PORT_INFORMATION_CLASS PortInformationClass', 'PVOID PortInformation', 'ULONG Length', 'PULONG ReturnLength']
		case 127: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtAlpcQueryInformation_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcQueryInformation_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 128 NTSTATUS NtAlpcQueryInformationMessage ['HANDLE PortHandle', 'PPORT_MESSAGE PortMessage', 'ALPC_MESSAGE_INFORMATION_CLASS MessageInformationClass', 'PVOID MessageInformation', 'ULONG Length', 'PULONG ReturnLength']
		case 128: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtAlpcQueryInformationMessage_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcQueryInformationMessage_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 129 NTSTATUS NtAlpcRevokeSecurityContext ['HANDLE PortHandle', 'ULONG Flags', 'ALPC_HANDLE ContextHandle']
		case 129: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtAlpcRevokeSecurityContext_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcRevokeSecurityContext_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 130 NTSTATUS NtAlpcSendWaitReceivePort ['HANDLE PortHandle', 'ULONG Flags', 'PPORT_MESSAGE SendMessage', 'PALPC_MESSAGE_ATTRIBUTES SendMessageAttributes', 'PPORT_MESSAGE ReceiveMessage', 'PULONG BufferLength', 'PALPC_MESSAGE_ATTRIBUTES ReceiveMessageAttributes', 'PLARGE_INTEGER Timeout']
		case 130: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint64_t arg6 = 0;
			uint64_t arg7 = 0;
			if (PPP_CHECK_CB(on_NtAlpcSendWaitReceivePort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAlpcSendWaitReceivePort_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7) ;
		}; break;
		// 131 NTSTATUS NtAlpcSetInformation ['HANDLE PortHandle', 'ALPC_PORT_INFORMATION_CLASS PortInformationClass', 'PVOID PortInformation', 'ULONG Length']
		case 131: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtAlpcSetInformation_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtAlpcSetInformation_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 132 NTSTATUS NtAreMappedFilesTheSame ['PVOID File1MappedAsAnImage', 'PVOID File2MappedAsFile']
		case 132: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtAreMappedFilesTheSame_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAreMappedFilesTheSame_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 133 NTSTATUS NtAssignProcessToJobObject ['HANDLE JobHandle', 'HANDLE ProcessHandle']
		case 133: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtAssignProcessToJobObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtAssignProcessToJobObject_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 134 NTSTATUS NtCancelIoFileEx ['HANDLE FileHandle', 'PIO_STATUS_BLOCK IoRequestToCancel', 'PIO_STATUS_BLOCK IoStatusBlock']
		case 134: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtCancelIoFileEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCancelIoFileEx_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 135 NTSTATUS NtCancelSynchronousIoFile ['HANDLE ThreadHandle', 'PIO_STATUS_BLOCK IoRequestToCancel', 'PIO_STATUS_BLOCK IoStatusBlock']
		case 135: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtCancelSynchronousIoFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCancelSynchronousIoFile_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 136 NTSTATUS NtCommitComplete ['HANDLE EnlistmentHandle', 'PLARGE_INTEGER TmVirtualClock']
		case 136: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtCommitComplete_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCommitComplete_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 137 NTSTATUS NtCommitEnlistment ['HANDLE EnlistmentHandle', 'PLARGE_INTEGER TmVirtualClock']
		case 137: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtCommitEnlistment_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCommitEnlistment_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 138 NTSTATUS NtCommitTransaction ['HANDLE TransactionHandle', 'BOOLEAN Wait']
		case 138: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtCommitTransaction_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtCommitTransaction_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 139 NTSTATUS NtCompactKeys ['ULONG Count', 'HANDLE KeyArray[]']
		case 139: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtCompactKeys_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCompactKeys_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 140 NTSTATUS NtCompareTokens ['HANDLE FirstTokenHandle', 'HANDLE SecondTokenHandle', 'PBOOLEAN Equal']
		case 140: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtCompareTokens_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCompareTokens_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 141 NTSTATUS NtCompleteConnectPort ['HANDLE PortHandle']
		case 141: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtCompleteConnectPort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCompleteConnectPort_return, cpu, pc, arg0) ;
		}; break;
		// 142 NTSTATUS NtCompressKey ['HANDLE Key']
		case 142: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtCompressKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCompressKey_return, cpu, pc, arg0) ;
		}; break;
		// 143 NTSTATUS NtConnectPort ['PHANDLE PortHandle', 'PUNICODE_STRING PortName', 'PSECURITY_QUALITY_OF_SERVICE SecurityQos', 'PPORT_VIEW ClientView', 'PREMOTE_PORT_VIEW ServerView', 'PULONG MaxMessageLength', 'PVOID ConnectionInformation', 'PULONG ConnectionInformationLength']
		case 143: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint64_t arg6 = 0;
			uint64_t arg7 = 0;
			if (PPP_CHECK_CB(on_NtConnectPort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtConnectPort_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7) ;
		}; break;
		// 144 NTSTATUS NtCreateDebugObject ['PHANDLE DebugObjectHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'ULONG Flags']
		case 144: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtCreateDebugObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtCreateDebugObject_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 145 NTSTATUS NtCreateDirectoryObject ['PHANDLE DirectoryHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 145: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtCreateDirectoryObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateDirectoryObject_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 146 NTSTATUS NtCreateEnlistment ['PHANDLE EnlistmentHandle', 'ACCESS_MASK DesiredAccess', 'HANDLE ResourceManagerHandle', 'HANDLE TransactionHandle', 'POBJECT_ATTRIBUTES ObjectAttributes', 'ULONG CreateOptions', 'NOTIFICATION_MASK NotificationMask', 'PVOID EnlistmentKey']
		case 146: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint32_t arg5 = 0;
			uint32_t arg6 = 0;
			uint64_t arg7 = 0;
			if (PPP_CHECK_CB(on_NtCreateEnlistment_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateEnlistment_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7) ;
		}; break;
		// 147 NTSTATUS NtCreateEventPair ['PHANDLE EventPairHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 147: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtCreateEventPair_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateEventPair_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 148 NTSTATUS NtCreateIoCompletion ['PHANDLE IoCompletionHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'ULONG Count']
		case 148: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtCreateIoCompletion_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtCreateIoCompletion_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 149 NTSTATUS NtCreateJobObject ['PHANDLE JobHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 149: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtCreateJobObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateJobObject_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 150 NTSTATUS NtCreateJobSet ['ULONG NumJob', 'PJOB_SET_ARRAY UserJobSet', 'ULONG Flags']
		case 150: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtCreateJobSet_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtCreateJobSet_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 151 NTSTATUS NtCreateKeyTransacted ['PHANDLE KeyHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'ULONG TitleIndex', 'PUNICODE_STRING Class', 'ULONG CreateOptions', 'HANDLE TransactionHandle', 'PULONG Disposition']
		case 151: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			uint32_t arg5 = 0;
			uint64_t arg6 = 0;
			uint64_t arg7 = 0;
			if (PPP_CHECK_CB(on_NtCreateKeyTransacted_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateKeyTransacted_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7) ;
		}; break;
		// 152 NTSTATUS NtCreateKeyedEvent ['PHANDLE KeyedEventHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'ULONG Flags']
		case 152: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtCreateKeyedEvent_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtCreateKeyedEvent_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 153 NTSTATUS NtCreateMailslotFile ['PHANDLE FileHandle', 'ULONG DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'PIO_STATUS_BLOCK IoStatusBlock', 'ULONG CreateOptions', 'ULONG MailslotQuota', 'ULONG MaximumMessageSize', 'PLARGE_INTEGER ReadTimeout']
		case 153: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint32_t arg5 = 0;
			uint32_t arg6 = 0;
			uint64_t arg7 = 0;
			if (PPP_CHECK_CB(on_NtCreateMailslotFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateMailslotFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7) ;
		}; break;
		// 154 NTSTATUS NtCreateMutant ['PHANDLE MutantHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'BOOLEAN InitialOwner']
		case 154: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtCreateMutant_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtCreateMutant_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 155 NTSTATUS NtCreateNamedPipeFile ['PHANDLE FileHandle', 'ULONG DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'PIO_STATUS_BLOCK IoStatusBlock', 'ULONG ShareAccess', 'ULONG CreateDisposition', 'ULONG CreateOptions', 'ULONG NamedPipeType', 'ULONG ReadMode', 'ULONG CompletionMode', 'ULONG MaximumInstances', 'ULONG InboundQuota', 'ULONG OutboundQuota', 'PLARGE_INTEGER DefaultTimeout']
		case 155: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint32_t arg5 = 0;
			uint32_t arg6 = 0;
			uint32_t arg7 = 0;
			uint32_t arg8 = 0;
			uint32_t arg9 = 0;
			uint32_t arg10 = 0;
			uint32_t arg11 = 0;
			uint32_t arg12 = 0;
			uint64_t arg13 = 0;
			if (PPP_CHECK_CB(on_NtCreateNamedPipeFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint32_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint32_t));
				memcpy(&arg10, ctx->args[10], sizeof(uint32_t));
				memcpy(&arg11, ctx->args[11], sizeof(uint32_t));
				memcpy(&arg12, ctx->args[12], sizeof(uint32_t));
				memcpy(&arg13, ctx->args[13], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateNamedPipeFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13) ;
		}; break;
		// 156 NTSTATUS NtCreatePagingFile ['PUNICODE_STRING PageFileName', 'PLARGE_INTEGER MinimumSize', 'PLARGE_INTEGER MaximumSize', 'ULONG Priority']
		case 156: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtCreatePagingFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtCreatePagingFile_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 157 NTSTATUS NtCreatePort ['PHANDLE PortHandle', 'POBJECT_ATTRIBUTES ObjectAttributes', 'ULONG MaxConnectionInfoLength', 'ULONG MaxMessageLength', 'ULONG MaxPoolUsage']
		case 157: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint32_t arg3 = 0;
			uint32_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtCreatePort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtCreatePort_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 158 NTSTATUS NtCreatePrivateNamespace ['PHANDLE NamespaceHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'PVOID BoundaryDescriptor']
		case 158: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtCreatePrivateNamespace_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreatePrivateNamespace_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 159 NTSTATUS NtCreateProcess ['PHANDLE ProcessHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'HANDLE ParentProcess', 'BOOLEAN InheritObjectTable', 'HANDLE SectionHandle', 'HANDLE DebugPort', 'HANDLE ExceptionPort']
		case 159: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			uint64_t arg6 = 0;
			uint64_t arg7 = 0;
			if (PPP_CHECK_CB(on_NtCreateProcess_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateProcess_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7) ;
		}; break;
		// 160 NTSTATUS NtCreateProfile ['PHANDLE ProfileHandle', 'HANDLE Process', 'PVOID RangeBase', 'SIZE_T RangeSize', 'ULONG BucketSize', 'PULONG Buffer', 'ULONG BufferSize', 'KPROFILE_SOURCE ProfileSource', 'KAFFINITY Affinity']
		case 160: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			uint32_t arg6 = 0;
			uint32_t arg7 = 0;
			uint64_t arg8 = 0;
			if (PPP_CHECK_CB(on_NtCreateProfile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateProfile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) ;
		}; break;
		// 161 NTSTATUS NtCreateProfileEx ['PHANDLE ProfileHandle', 'HANDLE Process', 'PVOID ProfileBase', 'SIZE_T ProfileSize', 'ULONG BucketSize', 'PULONG Buffer', 'ULONG BufferSize', 'KPROFILE_SOURCE ProfileSource', 'ULONG GroupAffinityCount', 'PGROUP_AFFINITY GroupAffinity']
		case 161: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			uint32_t arg6 = 0;
			uint32_t arg7 = 0;
			uint32_t arg8 = 0;
			uint64_t arg9 = 0;
			if (PPP_CHECK_CB(on_NtCreateProfileEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint32_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateProfileEx_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) ;
		}; break;
		// 162 NTSTATUS NtCreateResourceManager ['PHANDLE ResourceManagerHandle', 'ACCESS_MASK DesiredAccess', 'HANDLE TmHandle', 'LPGUID RmGuid', 'POBJECT_ATTRIBUTES ObjectAttributes', 'ULONG CreateOptions', 'PUNICODE_STRING Description']
		case 162: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint32_t arg5 = 0;
			uint64_t arg6 = 0;
			if (PPP_CHECK_CB(on_NtCreateResourceManager_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateResourceManager_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6) ;
		}; break;
		// 163 NTSTATUS NtCreateSemaphore ['PHANDLE SemaphoreHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'LONG InitialCount', 'LONG MaximumCount']
		case 163: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			int32_t arg3 = 0;
			int32_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtCreateSemaphore_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(int32_t));
				memcpy(&arg4, ctx->args[4], sizeof(int32_t));
			}
			PPP_RUN_CB(on_NtCreateSemaphore_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 164 NTSTATUS NtCreateSymbolicLinkObject ['PHANDLE LinkHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'PUNICODE_STRING LinkTarget']
		case 164: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtCreateSymbolicLinkObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateSymbolicLinkObject_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 165 NTSTATUS NtCreateThreadEx ['PHANDLE ThreadHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'HANDLE ProcessHandle', 'PVOID StartRoutine', 'PVOID Argument', 'ULONG CreateFlags', 'ULONG_PTR ZeroBits', 'SIZE_T StackSize', 'SIZE_T MaximumStackSize', 'PPS_ATTRIBUTE_LIST AttributeList']
		case 165: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint32_t arg6 = 0;
			uint64_t arg7 = 0;
			uint64_t arg8 = 0;
			uint64_t arg9 = 0;
			uint64_t arg10 = 0;
			if (PPP_CHECK_CB(on_NtCreateThreadEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint64_t));
				memcpy(&arg10, ctx->args[10], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateThreadEx_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) ;
		}; break;
		// 166 NTSTATUS NtCreateTimer ['PHANDLE TimerHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'TIMER_TYPE TimerType']
		case 166: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtCreateTimer_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtCreateTimer_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 167 NTSTATUS NtCreateToken ['PHANDLE TokenHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'TOKEN_TYPE TokenType', 'PLUID AuthenticationId', 'PLARGE_INTEGER ExpirationTime', 'PTOKEN_USER User', 'PTOKEN_GROUPS Groups', 'PTOKEN_PRIVILEGES Privileges', 'PTOKEN_OWNER Owner', 'PTOKEN_PRIMARY_GROUP PrimaryGroup', 'PTOKEN_DEFAULT_DACL DefaultDacl', 'PTOKEN_SOURCE TokenSource']
		case 167: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint64_t arg6 = 0;
			uint64_t arg7 = 0;
			uint64_t arg8 = 0;
			uint64_t arg9 = 0;
			uint64_t arg10 = 0;
			uint64_t arg11 = 0;
			uint64_t arg12 = 0;
			if (PPP_CHECK_CB(on_NtCreateToken_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint64_t));
				memcpy(&arg10, ctx->args[10], sizeof(uint64_t));
				memcpy(&arg11, ctx->args[11], sizeof(uint64_t));
				memcpy(&arg12, ctx->args[12], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateToken_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12) ;
		}; break;
		// 168 NTSTATUS NtCreateTransaction ['PHANDLE TransactionHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'LPGUID Uow', 'HANDLE TmHandle', 'ULONG CreateOptions', 'ULONG IsolationLevel', 'ULONG IsolationFlags', 'PLARGE_INTEGER Timeout', 'PUNICODE_STRING Description']
		case 168: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint32_t arg5 = 0;
			uint32_t arg6 = 0;
			uint32_t arg7 = 0;
			uint64_t arg8 = 0;
			uint64_t arg9 = 0;
			if (PPP_CHECK_CB(on_NtCreateTransaction_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateTransaction_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) ;
		}; break;
		// 169 NTSTATUS NtCreateTransactionManager ['PHANDLE TmHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'PUNICODE_STRING LogFileName', 'ULONG CreateOptions', 'ULONG CommitStrength']
		case 169: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint32_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtCreateTransactionManager_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtCreateTransactionManager_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 170 NTSTATUS NtCreateUserProcess ['PHANDLE ProcessHandle', 'PHANDLE ThreadHandle', 'ACCESS_MASK ProcessDesiredAccess', 'ACCESS_MASK ThreadDesiredAccess', 'POBJECT_ATTRIBUTES ProcessObjectAttributes', 'POBJECT_ATTRIBUTES ThreadObjectAttributes', 'ULONG ProcessFlags', 'ULONG ThreadFlags', 'PRTL_USER_PROCESS_PARAMETERS ProcessParameters', 'PPROCESS_CREATE_INFO CreateInfo', 'PPROCESS_ATTRIBUTE_LIST AttributeList']
		case 170: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint32_t arg6 = 0;
			uint32_t arg7 = 0;
			uint64_t arg8 = 0;
			uint64_t arg9 = 0;
			uint64_t arg10 = 0;
			if (PPP_CHECK_CB(on_NtCreateUserProcess_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint64_t));
				memcpy(&arg10, ctx->args[10], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateUserProcess_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) ;
		}; break;
		// 171 NTSTATUS NtCreateWaitablePort ['PHANDLE PortHandle', 'POBJECT_ATTRIBUTES ObjectAttributes', 'ULONG MaxConnectionInfoLength', 'ULONG MaxMessageLength', 'ULONG MaxPoolUsage']
		case 171: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint32_t arg3 = 0;
			uint32_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtCreateWaitablePort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtCreateWaitablePort_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 172 NTSTATUS NtCreateWorkerFactory ['PHANDLE WorkerFactoryHandleReturn', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'HANDLE CompletionPortHandle', 'HANDLE WorkerProcessHandle', 'PVOID StartRoutine', 'PVOID StartParameter', 'ULONG MaxThreadCount', 'SIZE_T StackReserve', 'SIZE_T StackCommit']
		case 172: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint64_t arg6 = 0;
			uint32_t arg7 = 0;
			uint64_t arg8 = 0;
			uint64_t arg9 = 0;
			if (PPP_CHECK_CB(on_NtCreateWorkerFactory_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtCreateWorkerFactory_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) ;
		}; break;
		// 173 NTSTATUS NtDebugActiveProcess ['HANDLE ProcessHandle', 'HANDLE DebugObjectHandle']
		case 173: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtDebugActiveProcess_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtDebugActiveProcess_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 174 NTSTATUS NtDebugContinue ['HANDLE DebugObjectHandle', 'PCLIENT_ID ClientId', 'NTSTATUS ContinueStatus']
		case 174: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtDebugContinue_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtDebugContinue_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 175 NTSTATUS NtDeleteAtom ['RTL_ATOM Atom']
		case 175: {
			uint32_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtDeleteAtom_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtDeleteAtom_return, cpu, pc, arg0) ;
		}; break;
		// 176 NTSTATUS NtDeleteBootEntry ['ULONG Id']
		case 176: {
			uint32_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtDeleteBootEntry_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtDeleteBootEntry_return, cpu, pc, arg0) ;
		}; break;
		// 177 NTSTATUS NtDeleteDriverEntry ['ULONG Id']
		case 177: {
			uint32_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtDeleteDriverEntry_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtDeleteDriverEntry_return, cpu, pc, arg0) ;
		}; break;
		// 178 NTSTATUS NtDeleteFile ['POBJECT_ATTRIBUTES ObjectAttributes']
		case 178: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtDeleteFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtDeleteFile_return, cpu, pc, arg0) ;
		}; break;
		// 179 NTSTATUS NtDeleteKey ['HANDLE KeyHandle']
		case 179: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtDeleteKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtDeleteKey_return, cpu, pc, arg0) ;
		}; break;
		// 180 NTSTATUS NtDeleteObjectAuditAlarm ['PUNICODE_STRING SubsystemName', 'PVOID HandleId', 'BOOLEAN GenerateOnClose']
		case 180: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtDeleteObjectAuditAlarm_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtDeleteObjectAuditAlarm_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 181 NTSTATUS NtDeletePrivateNamespace ['HANDLE NamespaceHandle']
		case 181: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtDeletePrivateNamespace_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtDeletePrivateNamespace_return, cpu, pc, arg0) ;
		}; break;
		// 182 NTSTATUS NtDeleteValueKey ['HANDLE KeyHandle', 'PUNICODE_STRING ValueName']
		case 182: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtDeleteValueKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtDeleteValueKey_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 183 NTSTATUS NtDisableLastKnownGood ['']
		case 183: {
			if (PPP_CHECK_CB(on_NtDisableLastKnownGood_return) || PPP_CHECK_CB(on_all_sys_return2)) {
			}
			PPP_RUN_CB(on_NtDisableLastKnownGood_return, cpu, pc) ;
		}; break;
		// 184 NTSTATUS NtDisplayString ['PUNICODE_STRING String']
		case 184: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtDisplayString_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtDisplayString_return, cpu, pc, arg0) ;
		}; break;
		// 185 NTSTATUS NtDrawText ['PUNICODE_STRING Text']
		case 185: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtDrawText_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtDrawText_return, cpu, pc, arg0) ;
		}; break;
		// 186 NTSTATUS NtEnableLastKnownGood ['']
		case 186: {
			if (PPP_CHECK_CB(on_NtEnableLastKnownGood_return) || PPP_CHECK_CB(on_all_sys_return2)) {
			}
			PPP_RUN_CB(on_NtEnableLastKnownGood_return, cpu, pc) ;
		}; break;
		// 187 NTSTATUS NtEnumerateBootEntries ['PVOID Buffer', 'PULONG BufferLength']
		case 187: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtEnumerateBootEntries_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtEnumerateBootEntries_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 188 NTSTATUS NtEnumerateDriverEntries ['PVOID Buffer', 'PULONG BufferLength']
		case 188: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtEnumerateDriverEntries_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtEnumerateDriverEntries_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 189 NTSTATUS NtEnumerateSystemEnvironmentValuesEx ['ULONG InformationClass', 'PVOID Buffer', 'PULONG BufferLength']
		case 189: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtEnumerateSystemEnvironmentValuesEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtEnumerateSystemEnvironmentValuesEx_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 190 NTSTATUS NtEnumerateTransactionObject ['HANDLE RootObjectHandle', 'KTMOBJECT_TYPE QueryType', 'PKTMOBJECT_CURSOR ObjectCursor', 'ULONG ObjectCursorLength', 'PULONG ReturnLength']
		case 190: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtEnumerateTransactionObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtEnumerateTransactionObject_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 191 NTSTATUS NtExtendSection ['HANDLE SectionHandle', 'PLARGE_INTEGER NewSectionSize']
		case 191: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtExtendSection_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtExtendSection_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 192 NTSTATUS NtFilterToken ['HANDLE ExistingTokenHandle', 'ULONG Flags', 'PTOKEN_GROUPS SidsToDisable', 'PTOKEN_PRIVILEGES PrivilegesToDelete', 'PTOKEN_GROUPS RestrictedSids', 'PHANDLE NewTokenHandle']
		case 192: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtFilterToken_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtFilterToken_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 193 NTSTATUS NtFlushInstallUILanguage ['LANGID InstallUILanguage', 'ULONG SetComittedFlag']
		case 193: {
			uint32_t arg0 = 0;
			uint32_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtFlushInstallUILanguage_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtFlushInstallUILanguage_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 194 NTSTATUS NtFlushInstructionCache ['HANDLE ProcessHandle', 'PVOID BaseAddress', 'SIZE_T Length']
		case 194: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtFlushInstructionCache_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtFlushInstructionCache_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 195 NTSTATUS NtFlushKey ['HANDLE KeyHandle']
		case 195: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtFlushKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtFlushKey_return, cpu, pc, arg0) ;
		}; break;
		// 196 VOID NtFlushProcessWriteBuffers ['']
		case 196: {
			if (PPP_CHECK_CB(on_NtFlushProcessWriteBuffers_return) || PPP_CHECK_CB(on_all_sys_return2)) {
			}
			PPP_RUN_CB(on_NtFlushProcessWriteBuffers_return, cpu, pc) ;
		}; break;
		// 197 NTSTATUS NtFlushVirtualMemory ['HANDLE ProcessHandle', 'PVOID *BaseAddress', 'PSIZE_T RegionSize', 'PIO_STATUS_BLOCK IoStatus']
		case 197: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtFlushVirtualMemory_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtFlushVirtualMemory_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 198 NTSTATUS NtFlushWriteBuffer ['']
		case 198: {
			if (PPP_CHECK_CB(on_NtFlushWriteBuffer_return) || PPP_CHECK_CB(on_all_sys_return2)) {
			}
			PPP_RUN_CB(on_NtFlushWriteBuffer_return, cpu, pc) ;
		}; break;
		// 199 NTSTATUS NtFreeUserPhysicalPages ['HANDLE ProcessHandle', 'PULONG_PTR NumberOfPages', 'PULONG_PTR UserPfnArray']
		case 199: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtFreeUserPhysicalPages_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtFreeUserPhysicalPages_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 200 NTSTATUS NtFreezeRegistry ['ULONG TimeOutInSeconds']
		case 200: {
			uint32_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtFreezeRegistry_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtFreezeRegistry_return, cpu, pc, arg0) ;
		}; break;
		// 201 NTSTATUS NtFreezeTransactions ['PLARGE_INTEGER FreezeTimeout', 'PLARGE_INTEGER ThawTimeout']
		case 201: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtFreezeTransactions_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtFreezeTransactions_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 202 NTSTATUS NtGetContextThread ['HANDLE ThreadHandle', 'PCONTEXT ThreadContext']
		case 202: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtGetContextThread_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtGetContextThread_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 203 ULONG NtGetCurrentProcessorNumber ['']
		case 203: {
			if (PPP_CHECK_CB(on_NtGetCurrentProcessorNumber_return) || PPP_CHECK_CB(on_all_sys_return2)) {
			}
			PPP_RUN_CB(on_NtGetCurrentProcessorNumber_return, cpu, pc) ;
		}; break;
		// 204 NTSTATUS NtGetDevicePowerState ['HANDLE Device', 'DEVICE_POWER_STATE *State']
		case 204: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtGetDevicePowerState_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtGetDevicePowerState_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 205 NTSTATUS NtGetMUIRegistryInfo ['ULONG Flags', 'PULONG DataSize', 'PVOID Data']
		case 205: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtGetMUIRegistryInfo_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtGetMUIRegistryInfo_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 206 NTSTATUS NtGetNextProcess ['HANDLE ProcessHandle', 'ACCESS_MASK DesiredAccess', 'ULONG HandleAttributes', 'ULONG Flags', 'PHANDLE NewProcessHandle']
		case 206: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint32_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtGetNextProcess_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtGetNextProcess_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 207 NTSTATUS NtGetNextThread ['HANDLE ProcessHandle', 'HANDLE ThreadHandle', 'ACCESS_MASK DesiredAccess', 'ULONG HandleAttributes', 'ULONG Flags', 'PHANDLE NewThreadHandle']
		case 207: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint32_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtGetNextThread_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtGetNextThread_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 208 NTSTATUS NtGetNlsSectionPtr ['ULONG SectionType', 'ULONG SectionData', 'PVOID ContextData', 'PVOID *SectionPointer', 'PULONG SectionSize']
		case 208: {
			uint32_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtGetNlsSectionPtr_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtGetNlsSectionPtr_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 209 NTSTATUS NtGetNotificationResourceManager ['HANDLE ResourceManagerHandle', 'PTRANSACTION_NOTIFICATION TransactionNotification', 'ULONG NotificationLength', 'PLARGE_INTEGER Timeout', 'PULONG ReturnLength', 'ULONG Asynchronous', 'ULONG_PTR AsynchronousContext']
		case 209: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint32_t arg5 = 0;
			uint64_t arg6 = 0;
			if (PPP_CHECK_CB(on_NtGetNotificationResourceManager_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtGetNotificationResourceManager_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6) ;
		}; break;
		// 210 NTSTATUS NtGetPlugPlayEvent ['HANDLE EventHandle', 'PVOID Context', 'PPLUGPLAY_EVENT_BLOCK EventBlock', 'ULONG EventBufferSize']
		case 210: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtGetPlugPlayEvent_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtGetPlugPlayEvent_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 211 NTSTATUS NtGetWriteWatch ['HANDLE ProcessHandle', 'ULONG Flags', 'PVOID BaseAddress', 'SIZE_T RegionSize', 'PVOID *UserAddressArray', 'PULONG_PTR EntriesInUserAddressArray', 'PULONG Granularity']
		case 211: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint64_t arg6 = 0;
			if (PPP_CHECK_CB(on_NtGetWriteWatch_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtGetWriteWatch_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6) ;
		}; break;
		// 212 NTSTATUS NtImpersonateAnonymousToken ['HANDLE ThreadHandle']
		case 212: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtImpersonateAnonymousToken_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtImpersonateAnonymousToken_return, cpu, pc, arg0) ;
		}; break;
		// 213 NTSTATUS NtImpersonateThread ['HANDLE ServerThreadHandle', 'HANDLE ClientThreadHandle', 'PSECURITY_QUALITY_OF_SERVICE SecurityQos']
		case 213: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtImpersonateThread_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtImpersonateThread_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 214 NTSTATUS NtInitializeNlsFiles ['PVOID *BaseAddress', 'PLCID DefaultLocaleId', 'PLARGE_INTEGER DefaultCasingTableSize']
		case 214: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtInitializeNlsFiles_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtInitializeNlsFiles_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 215 NTSTATUS NtInitializeRegistry ['USHORT BootCondition']
		case 215: {
			uint32_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtInitializeRegistry_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtInitializeRegistry_return, cpu, pc, arg0) ;
		}; break;
		// 216 NTSTATUS NtInitiatePowerAction ['POWER_ACTION SystemAction', 'SYSTEM_POWER_STATE MinSystemState', 'ULONG Flags', 'BOOLEAN Asynchronous']
		case 216: {
			uint32_t arg0 = 0;
			uint32_t arg1 = 0;
			uint32_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtInitiatePowerAction_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtInitiatePowerAction_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 217 BOOLEAN NtIsSystemResumeAutomatic ['']
		case 217: {
			if (PPP_CHECK_CB(on_NtIsSystemResumeAutomatic_return) || PPP_CHECK_CB(on_all_sys_return2)) {
			}
			PPP_RUN_CB(on_NtIsSystemResumeAutomatic_return, cpu, pc) ;
		}; break;
		// 218 NTSTATUS NtIsUILanguageComitted ['']
		case 218: {
			if (PPP_CHECK_CB(on_NtIsUILanguageComitted_return) || PPP_CHECK_CB(on_all_sys_return2)) {
			}
			PPP_RUN_CB(on_NtIsUILanguageComitted_return, cpu, pc) ;
		}; break;
		// 219 NTSTATUS NtListenPort ['HANDLE PortHandle', 'PPORT_MESSAGE ConnectionRequest']
		case 219: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtListenPort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtListenPort_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 220 NTSTATUS NtLoadDriver ['PUNICODE_STRING DriverServiceName']
		case 220: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtLoadDriver_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtLoadDriver_return, cpu, pc, arg0) ;
		}; break;
		// 221 NTSTATUS NtLoadKey ['POBJECT_ATTRIBUTES TargetKey', 'POBJECT_ATTRIBUTES SourceFile']
		case 221: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtLoadKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtLoadKey_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 222 NTSTATUS NtLoadKey2 ['POBJECT_ATTRIBUTES TargetKey', 'POBJECT_ATTRIBUTES SourceFile', 'ULONG Flags']
		case 222: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtLoadKey2_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtLoadKey2_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 223 NTSTATUS NtLoadKeyEx ['POBJECT_ATTRIBUTES TargetKey', 'POBJECT_ATTRIBUTES SourceFile', 'ULONG Flags', 'HANDLE TrustClassKey']
		case 223: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtLoadKeyEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtLoadKeyEx_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 224 NTSTATUS NtLockFile ['HANDLE FileHandle', 'HANDLE Event', 'PIO_APC_ROUTINE ApcRoutine', 'PVOID ApcContext', 'PIO_STATUS_BLOCK IoStatusBlock', 'PLARGE_INTEGER ByteOffset', 'PLARGE_INTEGER Length', 'ULONG Key', 'BOOLEAN FailImmediately', 'BOOLEAN ExclusiveLock']
		case 224: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint64_t arg6 = 0;
			uint32_t arg7 = 0;
			uint32_t arg8 = 0;
			uint32_t arg9 = 0;
			if (PPP_CHECK_CB(on_NtLockFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint32_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtLockFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) ;
		}; break;
		// 225 NTSTATUS NtLockProductActivationKeys ['ULONG *pPrivateVer', 'ULONG *pSafeMode']
		case 225: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtLockProductActivationKeys_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtLockProductActivationKeys_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 226 NTSTATUS NtLockRegistryKey ['HANDLE KeyHandle']
		case 226: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtLockRegistryKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtLockRegistryKey_return, cpu, pc, arg0) ;
		}; break;
		// 227 NTSTATUS NtLockVirtualMemory ['HANDLE ProcessHandle', 'PVOID *BaseAddress', 'PSIZE_T RegionSize', 'ULONG MapType']
		case 227: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtLockVirtualMemory_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtLockVirtualMemory_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 228 NTSTATUS NtMakePermanentObject ['HANDLE Handle']
		case 228: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtMakePermanentObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtMakePermanentObject_return, cpu, pc, arg0) ;
		}; break;
		// 229 NTSTATUS NtMakeTemporaryObject ['HANDLE Handle']
		case 229: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtMakeTemporaryObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtMakeTemporaryObject_return, cpu, pc, arg0) ;
		}; break;
		// 230 NTSTATUS NtMapCMFModule ['ULONG What', 'ULONG Index', 'PULONG CacheIndexOut', 'PULONG CacheFlagsOut', 'PULONG ViewSizeOut', 'PVOID *BaseAddress']
		case 230: {
			uint32_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtMapCMFModule_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtMapCMFModule_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 231 NTSTATUS NtMapUserPhysicalPages ['PVOID VirtualAddress', 'ULONG_PTR NumberOfPages', 'PULONG_PTR UserPfnArray']
		case 231: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtMapUserPhysicalPages_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtMapUserPhysicalPages_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 232 NTSTATUS NtModifyBootEntry ['PBOOT_ENTRY BootEntry']
		case 232: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtModifyBootEntry_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtModifyBootEntry_return, cpu, pc, arg0) ;
		}; break;
		// 233 NTSTATUS NtModifyDriverEntry ['PEFI_DRIVER_ENTRY DriverEntry']
		case 233: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtModifyDriverEntry_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtModifyDriverEntry_return, cpu, pc, arg0) ;
		}; break;
		// 234 NTSTATUS NtNotifyChangeDirectoryFile ['HANDLE FileHandle', 'HANDLE Event', 'PIO_APC_ROUTINE ApcRoutine', 'PVOID ApcContext', 'PIO_STATUS_BLOCK IoStatusBlock', 'PVOID Buffer', 'ULONG Length', 'ULONG CompletionFilter', 'BOOLEAN WatchTree']
		case 234: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint32_t arg6 = 0;
			uint32_t arg7 = 0;
			uint32_t arg8 = 0;
			if (PPP_CHECK_CB(on_NtNotifyChangeDirectoryFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtNotifyChangeDirectoryFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) ;
		}; break;
		// 235 NTSTATUS NtNotifyChangeKey ['HANDLE KeyHandle', 'HANDLE Event', 'PIO_APC_ROUTINE ApcRoutine', 'PVOID ApcContext', 'PIO_STATUS_BLOCK IoStatusBlock', 'ULONG CompletionFilter', 'BOOLEAN WatchTree', 'PVOID Buffer', 'ULONG BufferSize', 'BOOLEAN Asynchronous']
		case 235: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint32_t arg5 = 0;
			uint32_t arg6 = 0;
			uint64_t arg7 = 0;
			uint32_t arg8 = 0;
			uint32_t arg9 = 0;
			if (PPP_CHECK_CB(on_NtNotifyChangeKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint32_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtNotifyChangeKey_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) ;
		}; break;
		// 236 NTSTATUS NtNotifyChangeMultipleKeys ['HANDLE MasterKeyHandle', 'ULONG Count', 'OBJECT_ATTRIBUTES SlaveObjects[]', 'HANDLE Event', 'PIO_APC_ROUTINE ApcRoutine', 'PVOID ApcContext', 'PIO_STATUS_BLOCK IoStatusBlock', 'ULONG CompletionFilter', 'BOOLEAN WatchTree', 'PVOID Buffer', 'ULONG BufferSize', 'BOOLEAN Asynchronous']
		case 236: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint64_t arg6 = 0;
			uint32_t arg7 = 0;
			uint32_t arg8 = 0;
			uint64_t arg9 = 0;
			uint32_t arg10 = 0;
			uint32_t arg11 = 0;
			if (PPP_CHECK_CB(on_NtNotifyChangeMultipleKeys_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint32_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint64_t));
				memcpy(&arg10, ctx->args[10], sizeof(uint32_t));
				memcpy(&arg11, ctx->args[11], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtNotifyChangeMultipleKeys_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11) ;
		}; break;
		// 237 NTSTATUS NtNotifyChangeSession ['HANDLE Session', 'ULONG IoStateSequence', 'PVOID Reserved', 'ULONG Action', 'IO_SESSION_STATE IoState', 'IO_SESSION_STATE IoState2', 'PVOID Buffer', 'ULONG BufferSize']
		case 237: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint32_t arg4 = 0;
			uint32_t arg5 = 0;
			uint64_t arg6 = 0;
			uint32_t arg7 = 0;
			if (PPP_CHECK_CB(on_NtNotifyChangeSession_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtNotifyChangeSession_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7) ;
		}; break;
		// 238 NTSTATUS NtOpenEnlistment ['PHANDLE EnlistmentHandle', 'ACCESS_MASK DesiredAccess', 'HANDLE ResourceManagerHandle', 'LPGUID EnlistmentGuid', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 238: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtOpenEnlistment_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenEnlistment_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 239 NTSTATUS NtOpenEventPair ['PHANDLE EventPairHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 239: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtOpenEventPair_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenEventPair_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 240 NTSTATUS NtOpenIoCompletion ['PHANDLE IoCompletionHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 240: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtOpenIoCompletion_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenIoCompletion_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 241 NTSTATUS NtOpenJobObject ['PHANDLE JobHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 241: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtOpenJobObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenJobObject_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 242 NTSTATUS NtOpenKeyEx ['PHANDLE KeyHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'ULONG OpenOptions']
		case 242: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtOpenKeyEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtOpenKeyEx_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 243 NTSTATUS NtOpenKeyTransacted ['PHANDLE KeyHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'HANDLE TransactionHandle']
		case 243: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtOpenKeyTransacted_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenKeyTransacted_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 244 NTSTATUS NtOpenKeyTransactedEx ['PHANDLE KeyHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'ULONG OpenOptions', 'HANDLE TransactionHandle']
		case 244: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtOpenKeyTransactedEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenKeyTransactedEx_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 245 NTSTATUS NtOpenKeyedEvent ['PHANDLE KeyedEventHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 245: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtOpenKeyedEvent_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenKeyedEvent_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 246 NTSTATUS NtOpenMutant ['PHANDLE MutantHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 246: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtOpenMutant_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenMutant_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 247 NTSTATUS NtOpenObjectAuditAlarm ['PUNICODE_STRING SubsystemName', 'PVOID HandleId', 'PUNICODE_STRING ObjectTypeName', 'PUNICODE_STRING ObjectName', 'PSECURITY_DESCRIPTOR SecurityDescriptor', 'HANDLE ClientToken', 'ACCESS_MASK DesiredAccess', 'ACCESS_MASK GrantedAccess', 'PPRIVILEGE_SET Privileges', 'BOOLEAN ObjectCreation', 'BOOLEAN AccessGranted', 'PBOOLEAN GenerateOnClose']
		case 247: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint32_t arg6 = 0;
			uint32_t arg7 = 0;
			uint64_t arg8 = 0;
			uint32_t arg9 = 0;
			uint32_t arg10 = 0;
			uint64_t arg11 = 0;
			if (PPP_CHECK_CB(on_NtOpenObjectAuditAlarm_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint32_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
				memcpy(&arg9, ctx->args[9], sizeof(uint32_t));
				memcpy(&arg10, ctx->args[10], sizeof(uint32_t));
				memcpy(&arg11, ctx->args[11], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenObjectAuditAlarm_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11) ;
		}; break;
		// 248 NTSTATUS NtOpenPrivateNamespace ['PHANDLE NamespaceHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'PVOID BoundaryDescriptor']
		case 248: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtOpenPrivateNamespace_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenPrivateNamespace_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 249 NTSTATUS NtOpenProcessToken ['HANDLE ProcessHandle', 'ACCESS_MASK DesiredAccess', 'PHANDLE TokenHandle']
		case 249: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtOpenProcessToken_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenProcessToken_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 250 NTSTATUS NtOpenResourceManager ['PHANDLE ResourceManagerHandle', 'ACCESS_MASK DesiredAccess', 'HANDLE TmHandle', 'LPGUID ResourceManagerGuid', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 250: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtOpenResourceManager_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenResourceManager_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 251 NTSTATUS NtOpenSemaphore ['PHANDLE SemaphoreHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 251: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtOpenSemaphore_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenSemaphore_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 252 NTSTATUS NtOpenSession ['PHANDLE SessionHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 252: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtOpenSession_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenSession_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 253 NTSTATUS NtOpenSymbolicLinkObject ['PHANDLE LinkHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 253: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtOpenSymbolicLinkObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenSymbolicLinkObject_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 254 NTSTATUS NtOpenThread ['PHANDLE ThreadHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'PCLIENT_ID ClientId']
		case 254: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtOpenThread_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenThread_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 255 NTSTATUS NtOpenTimer ['PHANDLE TimerHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes']
		case 255: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtOpenTimer_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenTimer_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 256 NTSTATUS NtOpenTransaction ['PHANDLE TransactionHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'LPGUID Uow', 'HANDLE TmHandle']
		case 256: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtOpenTransaction_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtOpenTransaction_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 257 NTSTATUS NtOpenTransactionManager ['PHANDLE TmHandle', 'ACCESS_MASK DesiredAccess', 'POBJECT_ATTRIBUTES ObjectAttributes', 'PUNICODE_STRING LogFileName', 'LPGUID TmIdentity', 'ULONG OpenOptions']
		case 257: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint32_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtOpenTransactionManager_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtOpenTransactionManager_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 258 NTSTATUS NtPlugPlayControl ['PLUGPLAY_CONTROL_CLASS PnPControlClass', 'PVOID PnPControlData', 'ULONG PnPControlDataLength']
		case 258: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtPlugPlayControl_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtPlugPlayControl_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 259 NTSTATUS NtPrePrepareComplete ['HANDLE EnlistmentHandle', 'PLARGE_INTEGER TmVirtualClock']
		case 259: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtPrePrepareComplete_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtPrePrepareComplete_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 260 NTSTATUS NtPrePrepareEnlistment ['HANDLE EnlistmentHandle', 'PLARGE_INTEGER TmVirtualClock']
		case 260: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtPrePrepareEnlistment_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtPrePrepareEnlistment_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 261 NTSTATUS NtPrepareComplete ['HANDLE EnlistmentHandle', 'PLARGE_INTEGER TmVirtualClock']
		case 261: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtPrepareComplete_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtPrepareComplete_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 262 NTSTATUS NtPrepareEnlistment ['HANDLE EnlistmentHandle', 'PLARGE_INTEGER TmVirtualClock']
		case 262: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtPrepareEnlistment_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtPrepareEnlistment_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 263 NTSTATUS NtPrivilegeCheck ['HANDLE ClientToken', 'PPRIVILEGE_SET RequiredPrivileges', 'PBOOLEAN Result']
		case 263: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtPrivilegeCheck_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtPrivilegeCheck_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 264 NTSTATUS NtPrivilegeObjectAuditAlarm ['PUNICODE_STRING SubsystemName', 'PVOID HandleId', 'HANDLE ClientToken', 'ACCESS_MASK DesiredAccess', 'PPRIVILEGE_SET Privileges', 'BOOLEAN AccessGranted']
		case 264: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			uint32_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtPrivilegeObjectAuditAlarm_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtPrivilegeObjectAuditAlarm_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 265 NTSTATUS NtPrivilegedServiceAuditAlarm ['PUNICODE_STRING SubsystemName', 'PUNICODE_STRING ServiceName', 'HANDLE ClientToken', 'PPRIVILEGE_SET Privileges', 'BOOLEAN AccessGranted']
		case 265: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtPrivilegedServiceAuditAlarm_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtPrivilegedServiceAuditAlarm_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 266 NTSTATUS NtPropagationComplete ['HANDLE ResourceManagerHandle', 'ULONG RequestCookie', 'ULONG BufferLength', 'PVOID Buffer']
		case 266: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtPropagationComplete_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtPropagationComplete_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 267 NTSTATUS NtPropagationFailed ['HANDLE ResourceManagerHandle', 'ULONG RequestCookie', 'NTSTATUS PropStatus']
		case 267: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint32_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtPropagationFailed_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtPropagationFailed_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 268 NTSTATUS NtPulseEvent ['HANDLE EventHandle', 'PLONG PreviousState']
		case 268: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtPulseEvent_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtPulseEvent_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 269 NTSTATUS NtQueryBootEntryOrder ['PULONG Ids', 'PULONG Count']
		case 269: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtQueryBootEntryOrder_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryBootEntryOrder_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 270 NTSTATUS NtQueryBootOptions ['PBOOT_OPTIONS BootOptions', 'PULONG BootOptionsLength']
		case 270: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtQueryBootOptions_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryBootOptions_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 271 NTSTATUS NtQueryDebugFilterState ['ULONG ComponentId', 'ULONG Level']
		case 271: {
			uint32_t arg0 = 0;
			uint32_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtQueryDebugFilterState_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtQueryDebugFilterState_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 272 NTSTATUS NtQueryDirectoryObject ['HANDLE DirectoryHandle', 'PVOID Buffer', 'ULONG Length', 'BOOLEAN ReturnSingleEntry', 'BOOLEAN RestartScan', 'PULONG Context', 'PULONG ReturnLength']
		case 272: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint32_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			uint64_t arg6 = 0;
			if (PPP_CHECK_CB(on_NtQueryDirectoryObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryDirectoryObject_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6) ;
		}; break;
		// 273 NTSTATUS NtQueryDriverEntryOrder ['PULONG Ids', 'PULONG Count']
		case 273: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtQueryDriverEntryOrder_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryDriverEntryOrder_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 274 NTSTATUS NtQueryEaFile ['HANDLE FileHandle', 'PIO_STATUS_BLOCK IoStatusBlock', 'PVOID Buffer', 'ULONG Length', 'BOOLEAN ReturnSingleEntry', 'PVOID EaList', 'ULONG EaListLength', 'PULONG EaIndex', 'BOOLEAN RestartScan']
		case 274: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			uint32_t arg6 = 0;
			uint64_t arg7 = 0;
			uint32_t arg8 = 0;
			if (PPP_CHECK_CB(on_NtQueryEaFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtQueryEaFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) ;
		}; break;
		// 275 NTSTATUS NtQueryFullAttributesFile ['POBJECT_ATTRIBUTES ObjectAttributes', 'PFILE_NETWORK_OPEN_INFORMATION FileInformation']
		case 275: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtQueryFullAttributesFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryFullAttributesFile_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 276 NTSTATUS NtQueryInformationAtom ['RTL_ATOM Atom', 'ATOM_INFORMATION_CLASS InformationClass', 'PVOID AtomInformation', 'ULONG AtomInformationLength', 'PULONG ReturnLength']
		case 276: {
			uint32_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryInformationAtom_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryInformationAtom_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 277 NTSTATUS NtQueryInformationEnlistment ['HANDLE EnlistmentHandle', 'ENLISTMENT_INFORMATION_CLASS EnlistmentInformationClass', 'PVOID EnlistmentInformation', 'ULONG EnlistmentInformationLength', 'PULONG ReturnLength']
		case 277: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryInformationEnlistment_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryInformationEnlistment_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 278 NTSTATUS NtQueryInformationJobObject ['HANDLE JobHandle', 'JOBOBJECTINFOCLASS JobObjectInformationClass', 'PVOID JobObjectInformation', 'ULONG JobObjectInformationLength', 'PULONG ReturnLength']
		case 278: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryInformationJobObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryInformationJobObject_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 279 NTSTATUS NtQueryInformationPort ['HANDLE PortHandle', 'PORT_INFORMATION_CLASS PortInformationClass', 'PVOID PortInformation', 'ULONG Length', 'PULONG ReturnLength']
		case 279: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryInformationPort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryInformationPort_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 280 NTSTATUS NtQueryInformationResourceManager ['HANDLE ResourceManagerHandle', 'RESOURCEMANAGER_INFORMATION_CLASS ResourceManagerInformationClass', 'PVOID ResourceManagerInformation', 'ULONG ResourceManagerInformationLength', 'PULONG ReturnLength']
		case 280: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryInformationResourceManager_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryInformationResourceManager_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 281 NTSTATUS NtQueryInformationTransaction ['HANDLE TransactionHandle', 'TRANSACTION_INFORMATION_CLASS TransactionInformationClass', 'PVOID TransactionInformation', 'ULONG TransactionInformationLength', 'PULONG ReturnLength']
		case 281: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryInformationTransaction_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryInformationTransaction_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 282 NTSTATUS NtQueryInformationTransactionManager ['HANDLE TransactionManagerHandle', 'TRANSACTIONMANAGER_INFORMATION_CLASS TransactionManagerInformationClass', 'PVOID TransactionManagerInformation', 'ULONG TransactionManagerInformationLength', 'PULONG ReturnLength']
		case 282: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryInformationTransactionManager_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryInformationTransactionManager_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 283 NTSTATUS NtQueryInformationWorkerFactory ['HANDLE WorkerFactoryHandle', 'WORKERFACTORYINFOCLASS WorkerFactoryInformationClass', 'PVOID WorkerFactoryInformation', 'ULONG WorkerFactoryInformationLength', 'PULONG ReturnLength']
		case 283: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryInformationWorkerFactory_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryInformationWorkerFactory_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 284 NTSTATUS NtQueryInstallUILanguage ['LANGID *InstallUILanguageId']
		case 284: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtQueryInstallUILanguage_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryInstallUILanguage_return, cpu, pc, arg0) ;
		}; break;
		// 285 NTSTATUS NtQueryIntervalProfile ['KPROFILE_SOURCE ProfileSource', 'PULONG Interval']
		case 285: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtQueryIntervalProfile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryIntervalProfile_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 286 NTSTATUS NtQueryIoCompletion ['HANDLE IoCompletionHandle', 'IO_COMPLETION_INFORMATION_CLASS IoCompletionInformationClass', 'PVOID IoCompletionInformation', 'ULONG IoCompletionInformationLength', 'PULONG ReturnLength']
		case 286: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryIoCompletion_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryIoCompletion_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 287 NTSTATUS NtQueryLicenseValue ['PUNICODE_STRING Name', 'PULONG Type', 'PVOID Buffer', 'ULONG Length', 'PULONG ReturnedLength']
		case 287: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryLicenseValue_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryLicenseValue_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 288 NTSTATUS NtQueryMultipleValueKey ['HANDLE KeyHandle', 'PKEY_VALUE_ENTRY ValueEntries', 'ULONG EntryCount', 'PVOID ValueBuffer', 'PULONG BufferLength', 'PULONG RequiredBufferLength']
		case 288: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtQueryMultipleValueKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryMultipleValueKey_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 289 NTSTATUS NtQueryMutant ['HANDLE MutantHandle', 'MUTANT_INFORMATION_CLASS MutantInformationClass', 'PVOID MutantInformation', 'ULONG MutantInformationLength', 'PULONG ReturnLength']
		case 289: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQueryMutant_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryMutant_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 290 NTSTATUS NtQueryOpenSubKeys ['POBJECT_ATTRIBUTES TargetKey', 'PULONG HandleCount']
		case 290: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtQueryOpenSubKeys_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryOpenSubKeys_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 291 NTSTATUS NtQueryOpenSubKeysEx ['POBJECT_ATTRIBUTES TargetKey', 'ULONG BufferLength', 'PVOID Buffer', 'PULONG RequiredSize']
		case 291: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtQueryOpenSubKeysEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryOpenSubKeysEx_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 292 NTSTATUS NtQueryPortInformationProcess ['']
		case 292: {
			if (PPP_CHECK_CB(on_NtQueryPortInformationProcess_return) || PPP_CHECK_CB(on_all_sys_return2)) {
			}
			PPP_RUN_CB(on_NtQueryPortInformationProcess_return, cpu, pc) ;
		}; break;
		// 293 NTSTATUS NtQueryQuotaInformationFile ['HANDLE FileHandle', 'PIO_STATUS_BLOCK IoStatusBlock', 'PVOID Buffer', 'ULONG Length', 'BOOLEAN ReturnSingleEntry', 'PVOID SidList', 'ULONG SidListLength', 'PULONG StartSid', 'BOOLEAN RestartScan']
		case 293: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			uint32_t arg6 = 0;
			uint64_t arg7 = 0;
			uint32_t arg8 = 0;
			if (PPP_CHECK_CB(on_NtQueryQuotaInformationFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint32_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtQueryQuotaInformationFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) ;
		}; break;
		// 294 NTSTATUS NtQuerySecurityAttributesToken ['HANDLE TokenHandle', 'PUNICODE_STRING Attributes', 'ULONG NumberOfAttributes', 'PVOID Buffer', 'ULONG Length', 'PULONG ReturnLength']
		case 294: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtQuerySecurityAttributesToken_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQuerySecurityAttributesToken_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 295 NTSTATUS NtQuerySecurityObject ['HANDLE Handle', 'SECURITY_INFORMATION SecurityInformation', 'PSECURITY_DESCRIPTOR SecurityDescriptor', 'ULONG Length', 'PULONG LengthNeeded']
		case 295: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQuerySecurityObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQuerySecurityObject_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 296 NTSTATUS NtQuerySemaphore ['HANDLE SemaphoreHandle', 'SEMAPHORE_INFORMATION_CLASS SemaphoreInformationClass', 'PVOID SemaphoreInformation', 'ULONG SemaphoreInformationLength', 'PULONG ReturnLength']
		case 296: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQuerySemaphore_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQuerySemaphore_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 297 NTSTATUS NtQuerySymbolicLinkObject ['HANDLE LinkHandle', 'PUNICODE_STRING LinkTarget', 'PULONG ReturnedLength']
		case 297: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtQuerySymbolicLinkObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQuerySymbolicLinkObject_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 298 NTSTATUS NtQuerySystemEnvironmentValue ['PUNICODE_STRING VariableName', 'PWSTR VariableValue', 'USHORT ValueLength', 'PUSHORT ReturnLength']
		case 298: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtQuerySystemEnvironmentValue_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQuerySystemEnvironmentValue_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 299 NTSTATUS NtQuerySystemEnvironmentValueEx ['PUNICODE_STRING VariableName', 'LPGUID VendorGuid', 'PVOID Value', 'PULONG ValueLength', 'PULONG Attributes']
		case 299: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtQuerySystemEnvironmentValueEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQuerySystemEnvironmentValueEx_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 300 NTSTATUS NtQuerySystemInformationEx ['SYSTEM_INFORMATION_CLASS SystemInformationClass', 'PVOID QueryInformation', 'ULONG QueryInformationLength', 'PVOID SystemInformation', 'ULONG SystemInformationLength', 'PULONG ReturnLength']
		case 300: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtQuerySystemInformationEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQuerySystemInformationEx_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 301 NTSTATUS NtQueryTimerResolution ['PULONG MaximumTime', 'PULONG MinimumTime', 'PULONG CurrentTime']
		case 301: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtQueryTimerResolution_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueryTimerResolution_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 302 NTSTATUS NtQueueApcThreadEx ['HANDLE ThreadHandle', 'HANDLE UserApcReserveHandle', 'PPS_APC_ROUTINE ApcRoutine', 'PVOID ApcArgument1', 'PVOID ApcArgument2', 'PVOID ApcArgument3']
		case 302: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtQueueApcThreadEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtQueueApcThreadEx_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 303 NTSTATUS NtRaiseException ['PEXCEPTION_RECORD ExceptionRecord', 'PCONTEXT ContextRecord', 'BOOLEAN FirstChance']
		case 303: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtRaiseException_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtRaiseException_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 304 NTSTATUS NtRaiseHardError ['NTSTATUS ErrorStatus', 'ULONG NumberOfParameters', 'ULONG UnicodeStringParameterMask', 'PULONG_PTR Parameters', 'ULONG ValidResponseOptions', 'PULONG Response']
		case 304: {
			uint32_t arg0 = 0;
			uint32_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtRaiseHardError_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtRaiseHardError_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 305 NTSTATUS NtReadOnlyEnlistment ['HANDLE EnlistmentHandle', 'PLARGE_INTEGER TmVirtualClock']
		case 305: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtReadOnlyEnlistment_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtReadOnlyEnlistment_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 306 NTSTATUS NtRecoverEnlistment ['HANDLE EnlistmentHandle', 'PVOID EnlistmentKey']
		case 306: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtRecoverEnlistment_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtRecoverEnlistment_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 307 NTSTATUS NtRecoverResourceManager ['HANDLE ResourceManagerHandle']
		case 307: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtRecoverResourceManager_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtRecoverResourceManager_return, cpu, pc, arg0) ;
		}; break;
		// 308 NTSTATUS NtRecoverTransactionManager ['HANDLE TransactionManagerHandle']
		case 308: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtRecoverTransactionManager_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtRecoverTransactionManager_return, cpu, pc, arg0) ;
		}; break;
		// 309 NTSTATUS NtRegisterProtocolAddressInformation ['HANDLE ResourceManager', 'PCRM_PROTOCOL_ID ProtocolId', 'ULONG ProtocolInformationSize', 'PVOID ProtocolInformation', 'ULONG CreateOptions']
		case 309: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtRegisterProtocolAddressInformation_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtRegisterProtocolAddressInformation_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 310 NTSTATUS NtRegisterThreadTerminatePort ['HANDLE PortHandle']
		case 310: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtRegisterThreadTerminatePort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtRegisterThreadTerminatePort_return, cpu, pc, arg0) ;
		}; break;
		// 311 NTSTATUS NtReleaseKeyedEvent ['HANDLE KeyedEventHandle', 'PVOID KeyValue', 'BOOLEAN Alertable', 'PLARGE_INTEGER Timeout']
		case 311: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtReleaseKeyedEvent_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtReleaseKeyedEvent_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 312 NTSTATUS NtReleaseWorkerFactoryWorker ['HANDLE WorkerFactoryHandle']
		case 312: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtReleaseWorkerFactoryWorker_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtReleaseWorkerFactoryWorker_return, cpu, pc, arg0) ;
		}; break;
		// 313 NTSTATUS NtRemoveIoCompletionEx ['HANDLE IoCompletionHandle', 'PFILE_IO_COMPLETION_INFORMATION IoCompletionInformation', 'ULONG Count', 'PULONG NumEntriesRemoved', 'PLARGE_INTEGER Timeout', 'BOOLEAN Alertable']
		case 313: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint32_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtRemoveIoCompletionEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtRemoveIoCompletionEx_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 314 NTSTATUS NtRemoveProcessDebug ['HANDLE ProcessHandle', 'HANDLE DebugObjectHandle']
		case 314: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtRemoveProcessDebug_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtRemoveProcessDebug_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 315 NTSTATUS NtRenameKey ['HANDLE KeyHandle', 'PUNICODE_STRING NewName']
		case 315: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtRenameKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtRenameKey_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 316 NTSTATUS NtRenameTransactionManager ['PUNICODE_STRING LogFileName', 'LPGUID ExistingTransactionManagerGuid']
		case 316: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtRenameTransactionManager_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtRenameTransactionManager_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 317 NTSTATUS NtReplaceKey ['POBJECT_ATTRIBUTES NewFile', 'HANDLE TargetHandle', 'POBJECT_ATTRIBUTES OldFile']
		case 317: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtReplaceKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtReplaceKey_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 318 NTSTATUS NtReplacePartitionUnit ['PUNICODE_STRING TargetInstancePath', 'PUNICODE_STRING SpareInstancePath', 'ULONG Flags']
		case 318: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtReplacePartitionUnit_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtReplacePartitionUnit_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 319 NTSTATUS NtReplyWaitReplyPort ['HANDLE PortHandle', 'PPORT_MESSAGE ReplyMessage']
		case 319: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtReplyWaitReplyPort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtReplyWaitReplyPort_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 320 NTSTATUS NtRequestPort ['HANDLE PortHandle', 'PPORT_MESSAGE RequestMessage']
		case 320: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtRequestPort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtRequestPort_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 321 NTSTATUS NtResetEvent ['HANDLE EventHandle', 'PLONG PreviousState']
		case 321: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtResetEvent_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtResetEvent_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 322 NTSTATUS NtResetWriteWatch ['HANDLE ProcessHandle', 'PVOID BaseAddress', 'SIZE_T RegionSize']
		case 322: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtResetWriteWatch_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtResetWriteWatch_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 323 NTSTATUS NtRestoreKey ['HANDLE KeyHandle', 'HANDLE FileHandle', 'ULONG Flags']
		case 323: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtRestoreKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtRestoreKey_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 324 NTSTATUS NtResumeProcess ['HANDLE ProcessHandle']
		case 324: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtResumeProcess_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtResumeProcess_return, cpu, pc, arg0) ;
		}; break;
		// 325 NTSTATUS NtRollbackComplete ['HANDLE EnlistmentHandle', 'PLARGE_INTEGER TmVirtualClock']
		case 325: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtRollbackComplete_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtRollbackComplete_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 326 NTSTATUS NtRollbackEnlistment ['HANDLE EnlistmentHandle', 'PLARGE_INTEGER TmVirtualClock']
		case 326: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtRollbackEnlistment_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtRollbackEnlistment_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 327 NTSTATUS NtRollbackTransaction ['HANDLE TransactionHandle', 'BOOLEAN Wait']
		case 327: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtRollbackTransaction_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtRollbackTransaction_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 328 NTSTATUS NtRollforwardTransactionManager ['HANDLE TransactionManagerHandle', 'PLARGE_INTEGER TmVirtualClock']
		case 328: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtRollforwardTransactionManager_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtRollforwardTransactionManager_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 329 NTSTATUS NtSaveKey ['HANDLE KeyHandle', 'HANDLE FileHandle']
		case 329: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtSaveKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSaveKey_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 330 NTSTATUS NtSaveKeyEx ['HANDLE KeyHandle', 'HANDLE FileHandle', 'ULONG Format']
		case 330: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtSaveKeyEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSaveKeyEx_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 331 NTSTATUS NtSaveMergedKeys ['HANDLE HighPrecedenceKeyHandle', 'HANDLE LowPrecedenceKeyHandle', 'HANDLE FileHandle']
		case 331: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtSaveMergedKeys_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSaveMergedKeys_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 332 NTSTATUS NtSecureConnectPort ['PHANDLE PortHandle', 'PUNICODE_STRING PortName', 'PSECURITY_QUALITY_OF_SERVICE SecurityQos', 'PPORT_VIEW ClientView', 'PSID RequiredServerSid', 'PREMOTE_PORT_VIEW ServerView', 'PULONG MaxMessageLength', 'PVOID ConnectionInformation', 'PULONG ConnectionInformationLength']
		case 332: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint64_t arg4 = 0;
			uint64_t arg5 = 0;
			uint64_t arg6 = 0;
			uint64_t arg7 = 0;
			uint64_t arg8 = 0;
			if (PPP_CHECK_CB(on_NtSecureConnectPort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
				memcpy(&arg6, ctx->args[6], sizeof(uint64_t));
				memcpy(&arg7, ctx->args[7], sizeof(uint64_t));
				memcpy(&arg8, ctx->args[8], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSecureConnectPort_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) ;
		}; break;
		// 333 NTSTATUS NtSerializeBoot ['']
		case 333: {
			if (PPP_CHECK_CB(on_NtSerializeBoot_return) || PPP_CHECK_CB(on_all_sys_return2)) {
			}
			PPP_RUN_CB(on_NtSerializeBoot_return, cpu, pc) ;
		}; break;
		// 334 NTSTATUS NtSetBootEntryOrder ['PULONG Ids', 'ULONG Count']
		case 334: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtSetBootEntryOrder_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetBootEntryOrder_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 335 NTSTATUS NtSetBootOptions ['PBOOT_OPTIONS BootOptions', 'ULONG FieldsToChange']
		case 335: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtSetBootOptions_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetBootOptions_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 336 NTSTATUS NtSetContextThread ['HANDLE ThreadHandle', 'PCONTEXT ThreadContext']
		case 336: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtSetContextThread_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetContextThread_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 337 NTSTATUS NtSetDebugFilterState ['ULONG ComponentId', 'ULONG Level', 'BOOLEAN State']
		case 337: {
			uint32_t arg0 = 0;
			uint32_t arg1 = 0;
			uint32_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtSetDebugFilterState_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetDebugFilterState_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 338 NTSTATUS NtSetDefaultHardErrorPort ['HANDLE DefaultHardErrorPort']
		case 338: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtSetDefaultHardErrorPort_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetDefaultHardErrorPort_return, cpu, pc, arg0) ;
		}; break;
		// 339 NTSTATUS NtSetDefaultLocale ['BOOLEAN UserProfile', 'LCID DefaultLocaleId']
		case 339: {
			uint32_t arg0 = 0;
			uint32_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtSetDefaultLocale_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetDefaultLocale_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 340 NTSTATUS NtSetDefaultUILanguage ['LANGID DefaultUILanguageId']
		case 340: {
			uint32_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtSetDefaultUILanguage_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetDefaultUILanguage_return, cpu, pc, arg0) ;
		}; break;
		// 341 NTSTATUS NtSetDriverEntryOrder ['PULONG Ids', 'ULONG Count']
		case 341: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtSetDriverEntryOrder_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetDriverEntryOrder_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 342 NTSTATUS NtSetEaFile ['HANDLE FileHandle', 'PIO_STATUS_BLOCK IoStatusBlock', 'PVOID Buffer', 'ULONG Length']
		case 342: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtSetEaFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetEaFile_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 343 NTSTATUS NtSetHighEventPair ['HANDLE EventPairHandle']
		case 343: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtSetHighEventPair_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetHighEventPair_return, cpu, pc, arg0) ;
		}; break;
		// 344 NTSTATUS NtSetHighWaitLowEventPair ['HANDLE EventPairHandle']
		case 344: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtSetHighWaitLowEventPair_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetHighWaitLowEventPair_return, cpu, pc, arg0) ;
		}; break;
		// 345 NTSTATUS NtSetInformationDebugObject ['HANDLE DebugObjectHandle', 'DEBUGOBJECTINFOCLASS DebugObjectInformationClass', 'PVOID DebugInformation', 'ULONG DebugInformationLength', 'PULONG ReturnLength']
		case 345: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtSetInformationDebugObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetInformationDebugObject_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 346 NTSTATUS NtSetInformationEnlistment ['HANDLE EnlistmentHandle', 'ENLISTMENT_INFORMATION_CLASS EnlistmentInformationClass', 'PVOID EnlistmentInformation', 'ULONG EnlistmentInformationLength']
		case 346: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtSetInformationEnlistment_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetInformationEnlistment_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 347 NTSTATUS NtSetInformationJobObject ['HANDLE JobHandle', 'JOBOBJECTINFOCLASS JobObjectInformationClass', 'PVOID JobObjectInformation', 'ULONG JobObjectInformationLength']
		case 347: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtSetInformationJobObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetInformationJobObject_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 348 NTSTATUS NtSetInformationKey ['HANDLE KeyHandle', 'KEY_SET_INFORMATION_CLASS KeySetInformationClass', 'PVOID KeySetInformation', 'ULONG KeySetInformationLength']
		case 348: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtSetInformationKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetInformationKey_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 349 NTSTATUS NtSetInformationResourceManager ['HANDLE ResourceManagerHandle', 'RESOURCEMANAGER_INFORMATION_CLASS ResourceManagerInformationClass', 'PVOID ResourceManagerInformation', 'ULONG ResourceManagerInformationLength']
		case 349: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtSetInformationResourceManager_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetInformationResourceManager_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 350 NTSTATUS NtSetInformationToken ['HANDLE TokenHandle', 'TOKEN_INFORMATION_CLASS TokenInformationClass', 'PVOID TokenInformation', 'ULONG TokenInformationLength']
		case 350: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtSetInformationToken_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetInformationToken_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 351 NTSTATUS NtSetInformationTransaction ['HANDLE TransactionHandle', 'TRANSACTION_INFORMATION_CLASS TransactionInformationClass', 'PVOID TransactionInformation', 'ULONG TransactionInformationLength']
		case 351: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtSetInformationTransaction_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetInformationTransaction_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 352 NTSTATUS NtSetInformationTransactionManager ['HANDLE TmHandle', 'TRANSACTIONMANAGER_INFORMATION_CLASS TransactionManagerInformationClass', 'PVOID TransactionManagerInformation', 'ULONG TransactionManagerInformationLength']
		case 352: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtSetInformationTransactionManager_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetInformationTransactionManager_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 353 NTSTATUS NtSetInformationWorkerFactory ['HANDLE WorkerFactoryHandle', 'WORKERFACTORYINFOCLASS WorkerFactoryInformationClass', 'PVOID WorkerFactoryInformation', 'ULONG WorkerFactoryInformationLength']
		case 353: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtSetInformationWorkerFactory_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetInformationWorkerFactory_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 354 NTSTATUS NtSetIntervalProfile ['ULONG Interval', 'KPROFILE_SOURCE Source']
		case 354: {
			uint32_t arg0 = 0;
			uint32_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtSetIntervalProfile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetIntervalProfile_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 355 NTSTATUS NtSetIoCompletion ['HANDLE IoCompletionHandle', 'PVOID KeyContext', 'PVOID ApcContext', 'NTSTATUS IoStatus', 'ULONG_PTR IoStatusInformation']
		case 355: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint64_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtSetIoCompletion_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetIoCompletion_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 356 NTSTATUS NtSetIoCompletionEx ['HANDLE IoCompletionHandle', 'HANDLE IoCompletionReserveHandle', 'PVOID KeyContext', 'PVOID ApcContext', 'NTSTATUS IoStatus', 'ULONG_PTR IoStatusInformation']
		case 356: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtSetIoCompletionEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetIoCompletionEx_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 357 NTSTATUS NtSetLdtEntries ['ULONG Selector0', 'ULONG Entry0Low', 'ULONG Entry0Hi', 'ULONG Selector1', 'ULONG Entry1Low', 'ULONG Entry1Hi']
		case 357: {
			uint32_t arg0 = 0;
			uint32_t arg1 = 0;
			uint32_t arg2 = 0;
			uint32_t arg3 = 0;
			uint32_t arg4 = 0;
			uint32_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtSetLdtEntries_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetLdtEntries_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 358 NTSTATUS NtSetLowEventPair ['HANDLE EventPairHandle']
		case 358: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtSetLowEventPair_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetLowEventPair_return, cpu, pc, arg0) ;
		}; break;
		// 359 NTSTATUS NtSetLowWaitHighEventPair ['HANDLE EventPairHandle']
		case 359: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtSetLowWaitHighEventPair_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetLowWaitHighEventPair_return, cpu, pc, arg0) ;
		}; break;
		// 360 NTSTATUS NtSetQuotaInformationFile ['HANDLE FileHandle', 'PIO_STATUS_BLOCK IoStatusBlock', 'PVOID Buffer', 'ULONG Length']
		case 360: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtSetQuotaInformationFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetQuotaInformationFile_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 361 NTSTATUS NtSetSecurityObject ['HANDLE Handle', 'SECURITY_INFORMATION SecurityInformation', 'PSECURITY_DESCRIPTOR SecurityDescriptor']
		case 361: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtSetSecurityObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetSecurityObject_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 362 NTSTATUS NtSetSystemEnvironmentValue ['PUNICODE_STRING VariableName', 'PUNICODE_STRING VariableValue']
		case 362: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtSetSystemEnvironmentValue_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetSystemEnvironmentValue_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 363 NTSTATUS NtSetSystemEnvironmentValueEx ['PUNICODE_STRING VariableName', 'LPGUID VendorGuid', 'PVOID Value', 'ULONG ValueLength', 'ULONG Attributes']
		case 363: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint32_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtSetSystemEnvironmentValueEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetSystemEnvironmentValueEx_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 364 NTSTATUS NtSetSystemInformation ['SYSTEM_INFORMATION_CLASS SystemInformationClass', 'PVOID SystemInformation', 'ULONG SystemInformationLength']
		case 364: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtSetSystemInformation_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetSystemInformation_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 365 NTSTATUS NtSetSystemPowerState ['POWER_ACTION SystemAction', 'SYSTEM_POWER_STATE MinSystemState', 'ULONG Flags']
		case 365: {
			uint32_t arg0 = 0;
			uint32_t arg1 = 0;
			uint32_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtSetSystemPowerState_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetSystemPowerState_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 366 NTSTATUS NtSetSystemTime ['PLARGE_INTEGER SystemTime', 'PLARGE_INTEGER PreviousTime']
		case 366: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtSetSystemTime_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetSystemTime_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 367 NTSTATUS NtSetThreadExecutionState ['EXECUTION_STATE esFlags', 'PEXECUTION_STATE PreviousFlags']
		case 367: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtSetThreadExecutionState_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetThreadExecutionState_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 368 NTSTATUS NtSetTimerEx ['HANDLE TimerHandle', 'TIMER_SET_INFORMATION_CLASS TimerSetInformationClass', 'PVOID TimerSetInformation', 'ULONG TimerSetInformationLength']
		case 368: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtSetTimerEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetTimerEx_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 369 NTSTATUS NtSetTimerResolution ['ULONG DesiredTime', 'BOOLEAN SetResolution', 'PULONG ActualTime']
		case 369: {
			uint32_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			if (PPP_CHECK_CB(on_NtSetTimerResolution_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetTimerResolution_return, cpu, pc, arg0, arg1, arg2) ;
		}; break;
		// 370 NTSTATUS NtSetUuidSeed ['PCHAR Seed']
		case 370: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtSetUuidSeed_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSetUuidSeed_return, cpu, pc, arg0) ;
		}; break;
		// 371 NTSTATUS NtSetVolumeInformationFile ['HANDLE FileHandle', 'PIO_STATUS_BLOCK IoStatusBlock', 'PVOID FsInformation', 'ULONG Length', 'FS_INFORMATION_CLASS FsInformationClass']
		case 371: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			uint32_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtSetVolumeInformationFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtSetVolumeInformationFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 372 NTSTATUS NtShutdownSystem ['SHUTDOWN_ACTION Action']
		case 372: {
			uint32_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtShutdownSystem_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtShutdownSystem_return, cpu, pc, arg0) ;
		}; break;
		// 373 NTSTATUS NtShutdownWorkerFactory ['HANDLE WorkerFactoryHandle', 'LONG *PendingWorkerCount']
		case 373: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtShutdownWorkerFactory_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtShutdownWorkerFactory_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 374 NTSTATUS NtSignalAndWaitForSingleObject ['HANDLE SignalHandle', 'HANDLE WaitHandle', 'BOOLEAN Alertable', 'PLARGE_INTEGER Timeout']
		case 374: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtSignalAndWaitForSingleObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSignalAndWaitForSingleObject_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 375 NTSTATUS NtSinglePhaseReject ['HANDLE EnlistmentHandle', 'PLARGE_INTEGER TmVirtualClock']
		case 375: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtSinglePhaseReject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSinglePhaseReject_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 376 NTSTATUS NtStartProfile ['HANDLE ProfileHandle']
		case 376: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtStartProfile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtStartProfile_return, cpu, pc, arg0) ;
		}; break;
		// 377 NTSTATUS NtStopProfile ['HANDLE ProfileHandle']
		case 377: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtStopProfile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtStopProfile_return, cpu, pc, arg0) ;
		}; break;
		// 378 NTSTATUS NtSuspendProcess ['HANDLE ProcessHandle']
		case 378: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtSuspendProcess_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSuspendProcess_return, cpu, pc, arg0) ;
		}; break;
		// 379 NTSTATUS NtSuspendThread ['HANDLE ThreadHandle', 'PULONG PreviousSuspendCount']
		case 379: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtSuspendThread_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSuspendThread_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 380 NTSTATUS NtSystemDebugControl ['SYSDBG_COMMAND Command', 'PVOID InputBuffer', 'ULONG InputBufferLength', 'PVOID OutputBuffer', 'ULONG OutputBufferLength', 'PULONG ReturnLength']
		case 380: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtSystemDebugControl_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtSystemDebugControl_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 381 NTSTATUS NtTerminateJobObject ['HANDLE JobHandle', 'NTSTATUS ExitStatus']
		case 381: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtTerminateJobObject_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtTerminateJobObject_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 382 NTSTATUS NtTestAlert ['']
		case 382: {
			if (PPP_CHECK_CB(on_NtTestAlert_return) || PPP_CHECK_CB(on_all_sys_return2)) {
			}
			PPP_RUN_CB(on_NtTestAlert_return, cpu, pc) ;
		}; break;
		// 383 NTSTATUS NtThawRegistry ['']
		case 383: {
			if (PPP_CHECK_CB(on_NtThawRegistry_return) || PPP_CHECK_CB(on_all_sys_return2)) {
			}
			PPP_RUN_CB(on_NtThawRegistry_return, cpu, pc) ;
		}; break;
		// 384 NTSTATUS NtThawTransactions ['']
		case 384: {
			if (PPP_CHECK_CB(on_NtThawTransactions_return) || PPP_CHECK_CB(on_all_sys_return2)) {
			}
			PPP_RUN_CB(on_NtThawTransactions_return, cpu, pc) ;
		}; break;
		// 385 NTSTATUS NtTraceControl ['ULONG FunctionCode', 'PVOID InBuffer', 'ULONG InBufferLen', 'PVOID OutBuffer', 'ULONG OutBufferLen', 'PULONG ReturnLength']
		case 385: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			uint64_t arg5 = 0;
			if (PPP_CHECK_CB(on_NtTraceControl_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
				memcpy(&arg5, ctx->args[5], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtTraceControl_return, cpu, pc, arg0, arg1, arg2, arg3, arg4, arg5) ;
		}; break;
		// 386 NTSTATUS NtTranslateFilePath ['PFILE_PATH InputFilePath', 'ULONG OutputType', 'PFILE_PATH OutputFilePath', 'PULONG OutputFilePathLength']
		case 386: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtTranslateFilePath_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtTranslateFilePath_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 387 NTSTATUS NtUmsThreadYield ['PVOID SchedulerParam']
		case 387: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtUmsThreadYield_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtUmsThreadYield_return, cpu, pc, arg0) ;
		}; break;
		// 388 NTSTATUS NtUnloadDriver ['PUNICODE_STRING DriverServiceName']
		case 388: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtUnloadDriver_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtUnloadDriver_return, cpu, pc, arg0) ;
		}; break;
		// 389 NTSTATUS NtUnloadKey ['POBJECT_ATTRIBUTES TargetKey']
		case 389: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtUnloadKey_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtUnloadKey_return, cpu, pc, arg0) ;
		}; break;
		// 390 NTSTATUS NtUnloadKey2 ['POBJECT_ATTRIBUTES TargetKey', 'ULONG Flags']
		case 390: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtUnloadKey2_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtUnloadKey2_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 391 NTSTATUS NtUnloadKeyEx ['POBJECT_ATTRIBUTES TargetKey', 'HANDLE Event']
		case 391: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtUnloadKeyEx_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtUnloadKeyEx_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 392 NTSTATUS NtUnlockFile ['HANDLE FileHandle', 'PIO_STATUS_BLOCK IoStatusBlock', 'PLARGE_INTEGER ByteOffset', 'PLARGE_INTEGER Length', 'ULONG Key']
		case 392: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			uint32_t arg4 = 0;
			if (PPP_CHECK_CB(on_NtUnlockFile_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
				memcpy(&arg4, ctx->args[4], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtUnlockFile_return, cpu, pc, arg0, arg1, arg2, arg3, arg4) ;
		}; break;
		// 393 NTSTATUS NtUnlockVirtualMemory ['HANDLE ProcessHandle', 'PVOID *BaseAddress', 'PSIZE_T RegionSize', 'ULONG MapType']
		case 393: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint64_t arg2 = 0;
			uint32_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtUnlockVirtualMemory_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint32_t));
			}
			PPP_RUN_CB(on_NtUnlockVirtualMemory_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 394 NTSTATUS NtVdmControl ['VDMSERVICECLASS Service', 'PVOID ServiceData']
		case 394: {
			uint32_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtVdmControl_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint32_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtVdmControl_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 395 NTSTATUS NtWaitForDebugEvent ['HANDLE DebugObjectHandle', 'BOOLEAN Alertable', 'PLARGE_INTEGER Timeout', 'PDBGUI_WAIT_STATE_CHANGE WaitStateChange']
		case 395: {
			uint64_t arg0 = 0;
			uint32_t arg1 = 0;
			uint64_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtWaitForDebugEvent_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint32_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint64_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtWaitForDebugEvent_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 396 NTSTATUS NtWaitForKeyedEvent ['HANDLE KeyedEventHandle', 'PVOID KeyValue', 'BOOLEAN Alertable', 'PLARGE_INTEGER Timeout']
		case 396: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			uint32_t arg2 = 0;
			uint64_t arg3 = 0;
			if (PPP_CHECK_CB(on_NtWaitForKeyedEvent_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
				memcpy(&arg2, ctx->args[2], sizeof(uint32_t));
				memcpy(&arg3, ctx->args[3], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtWaitForKeyedEvent_return, cpu, pc, arg0, arg1, arg2, arg3) ;
		}; break;
		// 397 NTSTATUS NtWaitForWorkViaWorkerFactory ['HANDLE WorkerFactoryHandle', 'PFILE_IO_COMPLETION_INFORMATION MiniPacket']
		case 397: {
			uint64_t arg0 = 0;
			uint64_t arg1 = 0;
			if (PPP_CHECK_CB(on_NtWaitForWorkViaWorkerFactory_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
				memcpy(&arg1, ctx->args[1], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtWaitForWorkViaWorkerFactory_return, cpu, pc, arg0, arg1) ;
		}; break;
		// 398 NTSTATUS NtWaitHighEventPair ['HANDLE EventPairHandle']
		case 398: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtWaitHighEventPair_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtWaitHighEventPair_return, cpu, pc, arg0) ;
		}; break;
		// 399 NTSTATUS NtWaitLowEventPair ['HANDLE EventPairHandle']
		case 399: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtWaitLowEventPair_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtWaitLowEventPair_return, cpu, pc, arg0) ;
		}; break;
		// 400 NTSTATUS NtWorkerFactoryWorkerReady ['HANDLE WorkerFactoryHandle']
		case 400: {
			uint64_t arg0 = 0;
			if (PPP_CHECK_CB(on_NtWorkerFactoryWorkerReady_return) || PPP_CHECK_CB(on_all_sys_return2)) {
				memcpy(&arg0, ctx->args[0], sizeof(uint64_t));
			}
			PPP_RUN_CB(on_NtWorkerFactoryWorkerReady_return, cpu, pc, arg0) ;
		}; break;
		default:
			PPP_RUN_CB(on_unknown_sys_return, cpu, pc, ctx->no);
	}
	PPP_RUN_CB(on_all_sys_return, cpu, pc, ctx->no);
	PPP_RUN_CB(on_all_sys_return2, cpu, pc, call, ctx);
#endif
}

/* vim: set tabstop=4 softtabstop=4 noexpandtab ft=cpp: */