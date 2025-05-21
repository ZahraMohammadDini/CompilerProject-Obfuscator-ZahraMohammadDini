int fvar1z(int a, int b) {
    int a39 = a + b;
    return a39;
}

int main() {
    int useless = 0;
    if (useless == 9999) printf("dead\n");
    int var1 = 3;
    int var2 = 4;
    int obf_result = fvar1z(var1, var2);
    printf("%d\n", obf_result);
    return 0;
}
