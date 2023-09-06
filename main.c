#include "base.h"
#include <stdio.h>

int main()
{
    printf("cl\t= %d\n", COMPILER_CL);
    printf("clang\t= %d\n", COMPILER_CLANG);
    printf("gcc\t= %d\n", COMPILER_GCC);
    printf("windows\t= %d\n", OS_WINDOWS);
    printf("linux\t= %d\n", OS_LINUX);
    printf("mac\t= %d\n", OS_APPLE);
    printf("x86\t= %d\n", ARCH_X86);
    printf("x64\t= %d\n", ARCH_X64);
    printf("arm64\t= %d\n", ARCH_ARM64);
    printf("arm\t= %d\n", ARCH_ARM);
    return 0;
}
