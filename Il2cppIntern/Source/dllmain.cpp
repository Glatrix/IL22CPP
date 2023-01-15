#include "Includes.h"
#include "../Il2cpp/Il2cpp.h"

void Main() {
    AllocConsole();
    auto f = freopen("CONOUT$", "w", stdout);
    std::cout << "Test" << std::endl;

    Il2cpp::Initialize();
    intptr_t domain = Il2cpp::il2cpp_domain_get();
    intptr_t asmCshrp_assembly = Il2cpp::il2cpp_domain_assembly_open(domain, "Assembly-CSharp.dll");
    intptr_t asmCshrp_image = Il2cpp::il2cpp_assembly_get_image(asmCshrp_assembly);
    std::cout << Il2cpp::il2cpp_image_get_name(asmCshrp_image) << " Has " << Il2cpp::il2cpp_image_get_class_count(asmCshrp_image) << " Classes.";
}


BOOL APIENTRY DllMain(HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved){
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Main, 0, 0, 0);
    }
    return TRUE;
}