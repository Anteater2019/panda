/*
 * Virtio PCI Bindings
 *
 * Copyright IBM, Corp. 2007
 * Copyright (c) 2009 CodeSourcery
 *
 * Authors:
 *  Anthony Liguori   <aliguori@us.ibm.com>
 *  Paul Brook        <paul@codesourcery.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 */

#ifndef QEMU_VIRTIO_PCI_H
#define QEMU_VIRTIO_PCI_H

#include "hw/pci/msi.h"
#include "hw/virtio/virtio-blk.h"
#include "hw/virtio/virtio-net.h"
#include "hw/virtio/virtio-rng.h"
#include "hw/virtio/virtio-serial.h"
#include "hw/virtio/virtio-scsi.h"
#include "hw/virtio/virtio-balloon.h"
#include "hw/virtio/virtio-bus.h"
#include "hw/virtio/virtio-input.h"
#include "hw/virtio/virtio-gpu.h"
#include "hw/virtio/virtio-crypto.h"

#ifdef CONFIG_VIRTFS
#include "hw/9pfs/virtio-9p.h"
#endif
#ifdef CONFIG_VHOST_SCSI
#include "hw/virtio/vhost-scsi.h"
#endif

typedef struct VirtIOPCIProxy VirtIOPCIProxy;
typedef struct VirtIOBlkPCI VirtIOBlkPCI;
typedef struct VirtIOSCSIPCI VirtIOSCSIPCI;
typedef struct VirtIOBalloonPCI VirtIOBalloonPCI;
typedef struct VirtIOSerialPCI VirtIOSerialPCI;
typedef struct VirtIONetPCI VirtIONetPCI;
typedef struct VHostSCSIPCI VHostSCSIPCI;
typedef struct VirtIORngPCI VirtIORngPCI;
typedef struct VirtIOInputPCI VirtIOInputPCI;
typedef struct VirtIOInputHIDPCI VirtIOInputHIDPCI;
typedef struct VirtIOInputHostPCI VirtIOInputHostPCI;
typedef struct VirtIOGPUPCI VirtIOGPUPCI;
typedef struct VirtIOCryptoPCI VirtIOCryptoPCI;

/* virtio-pci-bus */

typedef struct VirtioBusState VirtioPCIBusState;
typedef struct VirtioBusClass VirtioPCIBusClass;

#define TYPE_VIRTIO_PCI_BUS "virtio-pci-bus"
#define VIRTIO_PCI_BUS(obj) \
        OBJECT_CHECK(VirtioPCIBusState, (obj), TYPE_VIRTIO_PCI_BUS)
#define VIRTIO_PCI_BUS_GET_CLASS(obj) \
        OBJECT_GET_CLASS(VirtioPCIBusClass, obj, TYPE_VIRTIO_PCI_BUS)
#define VIRTIO_PCI_BUS_CLASS(klass) \
        OBJECT_CLASS_CHECK(VirtioPCIBusClass, klass, TYPE_VIRTIO_PCI_BUS)

enum {
    VIRTIO_PCI_FLAG_BUS_MASTER_BUG_MIGRATION_BIT,
    VIRTIO_PCI_FLAG_USE_IOEVENTFD_BIT,
    VIRTIO_PCI_FLAG_MIGRATE_EXTRA_BIT,
    VIRTIO_PCI_FLAG_MODERN_PIO_NOTIFY_BIT,
    VIRTIO_PCI_FLAG_DISABLE_PCIE_BIT,
    VIRTIO_PCI_FLAG_PAGE_PER_VQ_BIT,
    VIRTIO_PCI_FLAG_ATS_BIT,
    VIRTIO_PCI_FLAG_INIT_DEVERR_BIT,
    VIRTIO_PCI_FLAG_INIT_LNKCTL_BIT,
    VIRTIO_PCI_FLAG_INIT_PM_BIT,
};

/* Need to activate work-arounds for buggy guests at vmstate load. */
#define VIRTIO_PCI_FLAG_BUS_MASTER_BUG_MIGRATION \
    (1 << VIRTIO_PCI_FLAG_BUS_MASTER_BUG_MIGRATION_BIT)

/* Performance improves when virtqueue kick processing is decoupled from the
 * vcpu thread using ioeventfd for some devices. */
#define VIRTIO_PCI_FLAG_USE_IOEVENTFD   (1 << VIRTIO_PCI_FLAG_USE_IOEVENTFD_BIT)

/* virtio version flags */
#define VIRTIO_PCI_FLAG_DISABLE_PCIE (1 << VIRTIO_PCI_FLAG_DISABLE_PCIE_BIT)

/* migrate extra state */
#define VIRTIO_PCI_FLAG_MIGRATE_EXTRA (1 << VIRTIO_PCI_FLAG_MIGRATE_EXTRA_BIT)

/* have pio notification for modern device ? */
#define VIRTIO_PCI_FLAG_MODERN_PIO_NOTIFY \
    (1 << VIRTIO_PCI_FLAG_MODERN_PIO_NOTIFY_BIT)

/* page per vq flag to be used by split drivers within guests */
#define VIRTIO_PCI_FLAG_PAGE_PER_VQ \
    (1 << VIRTIO_PCI_FLAG_PAGE_PER_VQ_BIT)

/* address space translation service */
#define VIRTIO_PCI_FLAG_ATS (1 << VIRTIO_PCI_FLAG_ATS_BIT)

/* Init error enabling flags */
#define VIRTIO_PCI_FLAG_INIT_DEVERR (1 << VIRTIO_PCI_FLAG_INIT_DEVERR_BIT)

/* Init Link Control register */
#define VIRTIO_PCI_FLAG_INIT_LNKCTL (1 << VIRTIO_PCI_FLAG_INIT_LNKCTL_BIT)

/* Init Power Management */
#define VIRTIO_PCI_FLAG_INIT_PM (1 << VIRTIO_PCI_FLAG_INIT_PM_BIT)

typedef struct {
    MSIMessage msg;
    int virq;
    unsigned int users;
} VirtIOIRQFD;

/*
 * virtio-pci: This is the PCIDevice which has a virtio-pci-bus.
 */
#define TYPE_VIRTIO_PCI "virtio-pci"
#define VIRTIO_PCI_GET_CLASS(obj) \
        OBJECT_GET_CLASS(VirtioPCIClass, obj, TYPE_VIRTIO_PCI)
#define VIRTIO_PCI_CLASS(klass) \
        OBJECT_CLASS_CHECK(VirtioPCIClass, klass, TYPE_VIRTIO_PCI)
#define VIRTIO_PCI(obj) \
        OBJECT_CHECK(VirtIOPCIProxy, (obj), TYPE_VIRTIO_PCI)

typedef struct VirtioPCIClass {
    PCIDeviceClass parent_class;
    DeviceRealize parent_dc_realize;
    void (*realize)(VirtIOPCIProxy *vpci_dev, Error **errp);
} VirtioPCIClass;

typedef struct VirtIOPCIRegion {
    MemoryRegion mr;
    uint32_t offset;
    uint32_t size;
    uint32_t type;
} VirtIOPCIRegion;

typedef struct VirtIOPCIQueue {
  uint16_t num;
  bool enabled;
  uint32_t desc[2];
  uint32_t avail[2];
  uint32_t used[2];
} VirtIOPCIQueue;

struct VirtIOPCIProxy {
    PCIDevice pci_dev;
    MemoryRegion bar;
    VirtIOPCIRegion common;
    VirtIOPCIRegion isr;
    VirtIOPCIRegion device;
    VirtIOPCIRegion notify;
    VirtIOPCIRegion notify_pio;
    MemoryRegion modern_bar;
    MemoryRegion io_bar;
    MemoryRegion modern_cfg;
    AddressSpace modern_as;
    uint32_t legacy_io_bar_idx;
    uint32_t msix_bar_idx;
    uint32_t modern_io_bar_idx;
    uint32_t modern_mem_bar_idx;
    int config_cap;
    uint32_t flags;
    bool disable_modern;
    bool ignore_backend_features;
    OnOffAuto disable_legacy;
    uint32_t class_code;
    uint32_t nvectors;
    uint32_t dfselect;
    uint32_t gfselect;
    uint32_t guest_features[2];
    VirtIOPCIQueue vqs[VIRTIO_QUEUE_MAX];

    VirtIOIRQFD *vector_irqfd;
    int nvqs_with_notifiers;
    VirtioBusState bus;
};

static inline bool virtio_pci_modern(VirtIOPCIProxy *proxy)
{
    return !proxy->disable_modern;
}

static inline bool virtio_pci_legacy(VirtIOPCIProxy *proxy)
{
    return proxy->disable_legacy == ON_OFF_AUTO_OFF;
}

static inline void virtio_pci_force_virtio_1(VirtIOPCIProxy *proxy)
{
    proxy->disable_modern = false;
    proxy->disable_legacy = ON_OFF_AUTO_ON;
}

static inline void virtio_pci_disable_modern(VirtIOPCIProxy *proxy)
{
    proxy->disable_modern = true;
}

/*
 * virtio-scsi-pci: This extends VirtioPCIProxy.
 */
#define TYPE_VIRTIO_SCSI_PCI "virtio-scsi-pci-base"
#define VIRTIO_SCSI_PCI(obj) \
        OBJECT_CHECK(VirtIOSCSIPCI, (obj), TYPE_VIRTIO_SCSI_PCI)

struct VirtIOSCSIPCI {
    VirtIOPCIProxy parent_obj;
    VirtIOSCSI vdev;
};

#ifdef CONFIG_VHOST_SCSI
/*
 * vhost-scsi-pci: This extends VirtioPCIProxy.
 */
#define TYPE_VHOST_SCSI_PCI "vhost-scsi-pci-base"
#define VHOST_SCSI_PCI(obj) \
        OBJECT_CHECK(VHostSCSIPCI, (obj), TYPE_VHOST_SCSI_PCI)

struct VHostSCSIPCI {
    VirtIOPCIProxy parent_obj;
    VHostSCSI vdev;
};
#endif

/*
 * virtio-blk-pci: This extends VirtioPCIProxy.
 */
#define TYPE_VIRTIO_BLK_PCI "virtio-blk-pci-base"
#define VIRTIO_BLK_PCI(obj) \
        OBJECT_CHECK(VirtIOBlkPCI, (obj), TYPE_VIRTIO_BLK_PCI)

struct VirtIOBlkPCI {
    VirtIOPCIProxy parent_obj;
    VirtIOBlock vdev;
};

/*
 * virtio-balloon-pci: This extends VirtioPCIProxy.
 */
#define TYPE_VIRTIO_BALLOON_PCI "virtio-balloon-pci-base"
#define VIRTIO_BALLOON_PCI(obj) \
        OBJECT_CHECK(VirtIOBalloonPCI, (obj), TYPE_VIRTIO_BALLOON_PCI)

struct VirtIOBalloonPCI {
    VirtIOPCIProxy parent_obj;
    VirtIOBalloon vdev;
};

/*
 * virtio-serial-pci: This extends VirtioPCIProxy.
 */
#define TYPE_VIRTIO_SERIAL_PCI "virtio-serial-pci-base"
#define VIRTIO_SERIAL_PCI(obj) \
        OBJECT_CHECK(VirtIOSerialPCI, (obj), TYPE_VIRTIO_SERIAL_PCI)

struct VirtIOSerialPCI {
    VirtIOPCIProxy parent_obj;
    VirtIOSerial vdev;
};

/*
 * virtio-net-pci: This extends VirtioPCIProxy.
 */
#define TYPE_VIRTIO_NET_PCI "virtio-net-pci-base"
#define VIRTIO_NET_PCI(obj) \
        OBJECT_CHECK(VirtIONetPCI, (obj), TYPE_VIRTIO_NET_PCI)

struct VirtIONetPCI {
    VirtIOPCIProxy parent_obj;
    VirtIONet vdev;
};

/*
 * virtio-9p-pci: This extends VirtioPCIProxy.
 */

#ifdef CONFIG_VIRTFS

#define TYPE_VIRTIO_9P_PCI "virtio-9p-pci-base"
#define VIRTIO_9P_PCI(obj) \
        OBJECT_CHECK(V9fsPCIState, (obj), TYPE_VIRTIO_9P_PCI)

typedef struct V9fsPCIState {
    VirtIOPCIProxy parent_obj;
    V9fsVirtioState vdev;
} V9fsPCIState;

#endif

/*
 * virtio-rng-pci: This extends VirtioPCIProxy.
 */
#define TYPE_VIRTIO_RNG_PCI "virtio-rng-pci-base"
#define VIRTIO_RNG_PCI(obj) \
        OBJECT_CHECK(VirtIORngPCI, (obj), TYPE_VIRTIO_RNG_PCI)

struct VirtIORngPCI {
    VirtIOPCIProxy parent_obj;
    VirtIORNG vdev;
};

/*
 * virtio-input-pci: This extends VirtioPCIProxy.
 */
#define TYPE_VIRTIO_INPUT_PCI "virtio-input-pci"
#define VIRTIO_INPUT_PCI(obj) \
        OBJECT_CHECK(VirtIOInputPCI, (obj), TYPE_VIRTIO_INPUT_PCI)

struct VirtIOInputPCI {
    VirtIOPCIProxy parent_obj;
    VirtIOInput vdev;
};

#define TYPE_VIRTIO_INPUT_HID_PCI "virtio-input-hid-pci"
#define TYPE_VIRTIO_KEYBOARD_PCI  "virtio-keyboard-pci"
#define TYPE_VIRTIO_MOUSE_PCI     "virtio-mouse-pci"
#define TYPE_VIRTIO_TABLET_PCI    "virtio-tablet-pci"
#define VIRTIO_INPUT_HID_PCI(obj) \
        OBJECT_CHECK(VirtIOInputHIDPCI, (obj), TYPE_VIRTIO_INPUT_HID_PCI)

struct VirtIOInputHIDPCI {
    VirtIOPCIProxy parent_obj;
    VirtIOInputHID vdev;
};

#ifdef CONFIG_LINUX

#define TYPE_VIRTIO_INPUT_HOST_PCI "virtio-input-host-pci-base"
#define VIRTIO_INPUT_HOST_PCI(obj) \
        OBJECT_CHECK(VirtIOInputHostPCI, (obj), TYPE_VIRTIO_INPUT_HOST_PCI)

struct VirtIOInputHostPCI {
    VirtIOPCIProxy parent_obj;
    VirtIOInputHost vdev;
};

#endif

/*
 * virtio-gpu-pci: This extends VirtioPCIProxy.
 */
#define TYPE_VIRTIO_GPU_PCI "virtio-gpu-pci"
#define VIRTIO_GPU_PCI(obj) \
        OBJECT_CHECK(VirtIOGPUPCI, (obj), TYPE_VIRTIO_GPU_PCI)

struct VirtIOGPUPCI {
    VirtIOPCIProxy parent_obj;
    VirtIOGPU vdev;
};

/*
 * virtio-crypto-pci: This extends VirtioPCIProxy.
 */
#define TYPE_VIRTIO_CRYPTO_PCI "virtio-crypto-pci"
#define VIRTIO_CRYPTO_PCI(obj) \
        OBJECT_CHECK(VirtIOCryptoPCI, (obj), TYPE_VIRTIO_CRYPTO_PCI)

struct VirtIOCryptoPCI {
    VirtIOPCIProxy parent_obj;
    VirtIOCrypto vdev;
};

/* Virtio ABI version, if we increment this, we break the guest driver. */
#define VIRTIO_PCI_ABI_VERSION          0

/* Input for virtio_pci_types_register() */
typedef struct VirtioPCIDeviceTypeInfo {
    /*
     * Common base class for the subclasses below.
     *
     * Required only if transitional_name or non_transitional_name is set.
     *
     * We need a separate base type instead of making all types
     * inherit from generic_name for two reasons:
     * 1) generic_name implements INTERFACE_PCIE_DEVICE, but
     *    transitional_name does not.
     * 2) generic_name has the "disable-legacy" and "disable-modern"
     *    properties, transitional_name and non_transitional name don't.
     */
    const char *base_name;
    /*
     * Generic device type.  Optional.
     *
     * Supports both transitional and non-transitional modes,
     * using the disable-legacy and disable-modern properties.
     * If disable-legacy=auto, (non-)transitional mode is selected
     * depending on the bus where the device is plugged.
     *
     * Implements both INTERFACE_PCIE_DEVICE and INTERFACE_CONVENTIONAL_PCI_DEVICE,
     * but PCI Express is supported only in non-transitional mode.
     *
     * The only type implemented by QEMU 3.1 and older.
     */
    const char *generic_name;
    /*
     * The transitional device type.  Optional.
     *
     * Implements both INTERFACE_PCIE_DEVICE and INTERFACE_CONVENTIONAL_PCI_DEVICE.
     */
    const char *transitional_name;
    /*
     * The non-transitional device type.  Optional.
     *
     * Implements INTERFACE_CONVENTIONAL_PCI_DEVICE only.
     */
    const char *non_transitional_name;

    /* Parent type.  If NULL, TYPE_VIRTIO_PCI is used */
    const char *parent;

    /* Same as TypeInfo fields: */
    size_t instance_size;
    void (*instance_init)(Object *obj);
    void (*class_init)(ObjectClass *klass, void *data);
} VirtioPCIDeviceTypeInfo;

/* Register virtio-pci type(s).  @t must be static. */
void virtio_pci_types_register(const VirtioPCIDeviceTypeInfo *t);

#endif
