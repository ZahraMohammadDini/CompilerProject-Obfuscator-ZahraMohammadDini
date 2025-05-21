#include <stdio.h>
#include "obfuscator.h"

int main() {
    obfuscate("input.mc", "output.mc");
    printf("✅ Obfuscation complete. See output.mc\n");
    return 0;
}
