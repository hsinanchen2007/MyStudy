### 解题思路


### 代码

```c
int gcd(int a, int b) {
    int rem = 0;
    
    while (b > 0) {
        rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

char * gcdOfStrings(char * str1, char * str2){
    int len1 = 0;
    int len2 = 0;
    int p = 0;
    char buf1[2001] = {0};
    char buf2[2001] = {0};

    (void)sprintf(buf1, "%s%s", str1, str2);
    (void)sprintf(buf2, "%s%s", str2, str1);

    if (0 != strcmp(buf1, buf2)) { return ""; }
    
    len1 = strlen(str1);
    len2 = strlen(str2);

    p = gcd(len1, len2);
    str1[p] = '\0';
    return str1;
}
```