#ifndef __MYTESTDRIVERNVDATASTRUC_H_
#define __MYTESTDRIVERNVDATASTRUC_H_
#include <Guid/HiiPlatformSetupFormset.h>
#include <Guid/HiiFormMapMethodGuid.h>

#define MYTESTDRIVER_VAR_GUID \
    { \
        0x9ae45eee, 0x1b99, 0x4369, {0x4a, 0x16, 0x66, 0x4e, 0xcd, 0xf2, 0x30, 0x57} \
    }

#define MYTESTDRIVER_FORMSET_GUID \
    {\
        0x5481db09, 0xe5f7, 0x4158, {0xa5, 0xc5, 0x2d, 0xbe, 0xa4, 0x95, 0x34, 0xff} \
    }



#define CONFIGURATION_VARSTORE_ID   0x1234

#pragma pack(1)

typedef struct 
{

    UINT16          MyTestDriverStringData[20];
    UINT8           MyTestDriverHexData;
    UINT8           MyTestDriverBaseAddress;
    UINT8           MyTestDriverChooseToEnable;
    EFI_HII_TIME    Time;
    EFI_HII_DATE    Date;

} MYTESTDRIVER_CONFIGURATION;

#pragma pack()
#endif


// formset
//   guid     = {0xf274b470, 0xefe4, 0x11ed, {0xa6, 0xde, 0x00, 0x58, 0x3f, 0x00, 0x40, 0xf6}},
//   title    = STRING_TOKEN(STR_SAMPLE_FORM_SET_TITLE),
//   help     = STRING_TOKEN(STR_SAMPLE_FORM_SET_HELP),

//   form formid = 1, title = STRING_TOKEN(STR_SAMPLE_FORM1_TITLE);
//   endform;
