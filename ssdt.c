

#include <ntddk.h>
	

VOID DriverUnload(PDRIVER_OBJECT driver)
{
	// ����ʵ��������ʲô��������ֻ��ӡһ�仰:
	DbgPrint("first: Our driver is unloading��\r\n");
}

// DriverEntry����ں������൱��main��
NTSTATUS DriverEntry(PDRIVER_OBJECT driver, PUNICODE_STRING reg_path)
{
    UNICODE_STRING zw_create_file = RTL_CONSTANT_STRING(L"ZwCreateFile");
	PVOID pt_create = MmGetSystemRoutineAddress(&zw_create_file);
	driver->DriverUnload = DriverUnload;
	return STATUS_SUCCESS;
}
