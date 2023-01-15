namespace Il2cpp {
	#define API_FUNC(rt, n, p) extern rt (*n) p
	#include "Il2cppFunctions.h"
	#undef API_FUNC
	extern void Initialize();
}