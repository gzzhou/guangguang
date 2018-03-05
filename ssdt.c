

#include <ntddk.h>
	

VOID DriverUnload(PDRIVER_OBJECT driver)
{
	// 但是实际上我们什么都不做，只打印一句话:
	DbgPrint("first: Our driver is unloading…\r\n");
}

// DriverEntry，入口函数。相当于main。
NTSTATUS DriverEntry(PDRIVER_OBJECT driver, PUNICODE_STRING reg_path)
{
    UNICODE_STRING zw_create_file = RTL_CONSTANT_STRING(L"ZwCreateFile");
	PVOID pt_create = MmGetSystemRoutineAddress(&zw_create_file);
	driver->DriverUnload = DriverUnload;
	return STATUS_SUCCESS;
}
