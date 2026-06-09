C语言实现
```C []
char * addStrings(char * num1, char * num2){
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    char *p1, *p2;
    if (len1 > len2) {
        p1 = num1 + len1 - 1;
        p2 = num2 + len2 - 1;
    } else {
        p2 = num1 + len1 - 1;
        p1 = num2 + len2 - 1;
        len1 = len1 ^ len2;
        len2 = len1 ^ len2;
        len1 = len1 ^ len2;
    }
    char *ret = (char*)malloc((len1 + 2) * sizeof(char));
    memset(ret, 0, (len1 + 2) * sizeof(char));
    int i, tmp, carry = 0;
    for (i = 0; i < len2; ++i) {
        tmp = *p1-- + *p2-- + carry - 96;
        ret[len1 - i] = tmp % 10 + 48;
        carry = tmp / 10;
    }
    for (i = len2; i < len1; ++i) {
        tmp = *p1-- + carry - 48;
        ret[len1 - i] = tmp % 10 + 48;
        carry = tmp / 10;
    }
    if (carry) {
        ret[0] = '1';
        return ret;
    }
    else
        return ret + 1;
}

```
