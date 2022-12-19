### 解题思路
感觉有一点难度

### 代码

```c
char * defangIPaddr(char * address){
    char* p=malloc(sizeof(char)*25);
    char *s=p;
    while(*address)
    {
        if(*address=='.')
        {
            *p++='[';
            *p++='.';
            *p++=']';
            address++;
        }
        else
        {
            *p++=*address;
            address++;
        }
    }
    *p='\0';
    return s;
}
```