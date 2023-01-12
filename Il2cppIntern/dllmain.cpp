#include "pch.h"
#include "Il2cpp.hpp";
#include <string.h>
#include <iostream>

void Main() {

    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    std::cout << "TEST\n";


    intptr_t domain = Il2cpp::il2cpp_domain_get();
    intptr_t asm_cshrp = Il2cpp::il2cpp_domain_assembly_open(domain, "Assembly-CSharp.dll");
    intptr_t img = Il2cpp::il2cpp_assembly_get_image(asm_cshrp);
    int class_count = Il2cpp::il2cpp_image_get_class_count(img);
    for (int i = 0; i < class_count; i++) {
        intptr_t _class = Il2cpp::il2cpp_image_get_class(img, i);
        char* name = Il2cpp::il2cpp_class_get_name(_class);
        std::cout << name << std::endl;
    }
}


BOOL APIENTRY DllMain(HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Main, 0, 0, 0);
    }
    return TRUE;
}

