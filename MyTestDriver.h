/** @file
  TODO: Brief Description of UEFI Driver MyTestDriver
  
  TODO: Detailed Description of UEFI Driver MyTestDriver

  TODO: Copyright for UEFI Driver MyTestDriver
  
  TODO: License for UEFI Driver MyTestDriver

**/

#ifndef __EFI_MY_TEST_DRIVER_H__
#define __EFI_MY_TEST_DRIVER_H__

#include <Uefi.h>
#include "MyTestDriverNVDataStruc.h"
//
// Libraries
//
#include <Library/UefiBootServicesTableLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/BaseLib.h>
#include <Library/UefiLib.h>
#include <Library/DevicePathLib.h>
#include <Library/DebugLib.h>


#include <Library/UefiRuntimeServicesTableLib.h>
//
// UEFI Driver Model Protocols
//
#include <Protocol/DriverBinding.h>
#include <Protocol/HiiDatabase.h>
#include <Protocol/HiiPackageList.h>
#include <Protocol/DriverSupportedEfiVersion.h>
#include <Protocol/ComponentName2.h>
#include <Protocol/ComponentName.h>
#include <Protocol/HiiConfigAccess.h>

// Added for HII
#include <Protocol/HiiConfigRouting.h>
#include <Protocol/FormBrowser2.h>
#include <Protocol/HiiString.h>
#include <Library/DevicePathLib.h>

//
// Consumed Protocols
//
#include <Protocol/PciIo.h>

//
// Produced Protocols
//

//
// Guids
//

//
// Driver Version
//
#define MY_TEST_DRIVER_VERSION  0x00000000

//
// Protocol instances
//
extern EFI_DRIVER_BINDING_PROTOCOL  gMyTestDriverDriverBinding;
extern EFI_COMPONENT_NAME2_PROTOCOL  gMyTestDriverComponentName2;
extern EFI_COMPONENT_NAME_PROTOCOL  gMyTestDriverComponentName;
extern EFI_HII_CONFIG_ACCESS_PROTOCOL  gMyTestDriverHiiConfigAccess;

#define MYTESTDRIVER_DEV_SIGNATURE SIGNATURE_32 ('m', 'w', 'd', 'r')

typedef struct {
  UINT32                          Signature;
  EFI_HANDLE                      Handle;
  MYTESTDRIVER_CONFIGURATION      Configuration;
  EFI_HANDLE                      DriverHandle[2];
  EFI_HII_HANDLE                  HiiHandle[2];
  //
  // Consumed protocol
  //
  EFI_HII_DATABASE_PROTOCOL       *HiiDatabase;
  EFI_HII_STRING_PROTOCOL         *HiiString;
  EFI_HII_CONFIG_ROUTING_PROTOCOL *HiiConfigRouting;
  EFI_FORM_BROWSER2_PROTOCOL      *FormBrowser2;
  //
  // Produced protocol
  //
  EFI_HII_CONFIG_ACCESS_PROTOCOL  ConfigAccess;
} MYTESTDRIVER_DEV;

#define MYTESTDRIVER_DEV_FROM_THIS(a) CR (a, MYTESTDRIVER_DEV, ConfigAccess, MYTESTDRIVER_DEV_SIGNATURE)

#pragma pack(1)

///
/// HII specific Vendor Device Path definition.
///
typedef struct {
VENDOR_DEVICE_PATH       VendorDevicePath;
EFI_DEVICE_PATH_PROTOCOL End;
} HII_VENDOR_DEVICE_PATH;

#pragma pack()

//
// Include files with function prototypes
//
#include "DriverBinding.h"
#include "ComponentName.h"
#include "HiiConfigAccess.h"

#endif
