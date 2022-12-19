```c
char* defangIPaddr(const char* address) {
    if (!address || !address[0])
        return NULL;
    
    int len = strlen(address);
    char* res = (char*)malloc(len + 6 + 1);
    if (!res)
        return NULL;
    memset(res, 0, len + 6 + 1);

    int i = 0, index = 0;
    while (address[i])  //读到字符串'\0'结束
    {
        if (address[i] == '.')
        {
            res[index++] = '[';
            res[index++] = '.';
            res[index++] = ']';
        }
        else
        {
            res[index++] = address[i];
        }
        ++i;
    }

    return res;
}
```