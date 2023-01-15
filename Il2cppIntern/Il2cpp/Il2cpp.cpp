#include <Windows.h>
#include "Il2cpp.h"

namespace Il2cpp {

    #define API_FUNC(r, n, p) r (*n) p
    #include "Il2cppFunctions.h"
    #undef API_FUNC

    void Initialize()
    {
        HMODULE GameAssembly = LoadLibraryA("GameAssembly.dll");
        #define API_FUNC(r, n, p) n = (r (*) p)(GetProcAddress(GameAssembly, #n))
        #include "Il2cppFunctions.h"
        #undef DO_API
    }
}


