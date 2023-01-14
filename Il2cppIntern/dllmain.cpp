#include "pch.h"
#include "Il2cpp.hpp";
#include <string.h>
#include <iostream>
#include <functional>

void Main() {
    AllocConsole();
    auto f = freopen("CONOUT$", "w", stdout);
    //std::cout << "START" << std::endl;
    intptr_t domain     = Il2cpp::il2cpp_domain_get();
    intptr_t asm_cshrp  = Il2cpp::il2cpp_domain_assembly_open(domain, "Assembly-CSharp.dll");
    intptr_t img        = Il2cpp::il2cpp_assembly_get_image(asm_cshrp);
    int class_count     = Il2cpp::il2cpp_image_get_class_count(img);
    for (int i = 0; i < class_count; i++) {
        intptr_t _class     = Il2cpp::il2cpp_image_get_class(img, i);
        char* class_name    = Il2cpp::il2cpp_class_get_name(_class);
        if (std::strcmp(class_name, "PlayerControl") == 0) {
            std::cout << "Found Class: PlayerControl\n Fields:" << std::endl;
            intptr_t iter;
            while (true){
                intptr_t fld    = Il2cpp::il2cpp_class_get_fields(_class, iter);
                if ((intptr_t*)fld == nullptr) {
                    break;
                }
                char* fld_name      = Il2cpp::il2cpp_field_get_name(fld);
                int offset          = Il2cpp::il2cpp_field_get_offset(fld);
                intptr_t type       = Il2cpp::il2cpp_field_get_type(fld);
                char* fld_typeName  = Il2cpp::il2cpp_type_get_name(type);

                std::cout << "[0x" << std::hex << offset << "] " << fld_typeName << " " << fld_name << ";" << std::endl;
            }
        }
    }
    std::cout << "END" << std::endl;
    
}

BOOL APIENTRY DllMain(HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved){
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Main, 0, 0, 0);
    }
    return TRUE;
}