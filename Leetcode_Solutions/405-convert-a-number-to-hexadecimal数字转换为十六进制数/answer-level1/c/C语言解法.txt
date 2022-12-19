每4位计算一个十六进制数。
```C []
char hex[9] = {0};
char * toHex(int num){
    int i = 7;
    int index = 0;
    int tmp = 0;
    memset(hex, 0, 9 * sizeof(char));
    while (i >= 0)
    {
        tmp = (num >> (i-- << 2)) & 0xf;
        if (tmp > 0 || index > 0) hex[index++] = (tmp > 9) ? (tmp - 10 + 'a') : (tmp + '0');
    }
    if (0 == index) hex[0] = '0';
    return hex;
}
```

或者直接调用sprintf，格式化转换。
```C []
char hex[9] = {0};
char * toHex(int num){
    sprintf(hex, "%x", num);
    return hex;
}
```

