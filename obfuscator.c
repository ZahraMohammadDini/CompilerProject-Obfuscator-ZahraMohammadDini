#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"
#include "obfuscator.h"

#define MAX_LINE 1024

void obfuscate(const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");
    if (!in || !out) {
        perror("File error");
        exit(1);
    }

    char line[MAX_LINE];
    int in_main = 0;

    while (fgets(line, MAX_LINE, in)) {
        replace_word(line, "sum", "fxz");
        replace_word(line, "result", "a39");
        replace_word(line, "x", "var1");
        replace_word(line, "y", "var2");
        replace_word(line, "total", "obf_result");

        if (strstr(line, "int main()")) {
            in_main = 1;
        }
        if (in_main && strstr(line, "{")) {
            fputs(line, out);
            fputs("    int useless = 0;\n", out);
            fputs("    if (useless == 9999) printf(\"dead\\n\");\n", out);
            continue;
        }

        if (strstr(line, "obf_result = fxz")) {
            fputs("    int selector = 1;\n", out);
            fputs("    while (selector > 0) {\n", out);
            fputs("        switch(selector) {\n", out);
            fputs("            case 1:\n", out);
            fputs("                obf_result = fxz(var1, var2);\n", out);
            fputs("                selector = 2;\n", out);
            fputs("                break;\n", out);
            fputs("            case 2:\n", out);
            fputs("                printf(\"%d\\n\", obf_result);\n", out);
            fputs("                selector = 0;\n", out);
            fputs("                break;\n", out);
            fputs("        }\n", out);
            fputs("    }\n", out);
            continue;
        }

        fputs(line, out);
    }

    fclose(in);
    fclose(out);
}
