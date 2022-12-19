### 解题思路
此处撰写解题思路

### 代码

```c
char * defangIPaddr(char * address)
{
    int length = strlen(address), count = 0;
    char newstr[length + 6 + 1];  // +6 3个'['']'  +1 ‘\0’
    char (*p)[] = &newstr;  //以返回指针的形式避免返回局部变量在主函数失效问题


    for (int i = 0; i < length; i++)
    {
        if (address[i] == '.')
        {
            newstr[count++] = '[';
            newstr[count++] = '.';
            newstr[count++] = ']';
            continue;
        }
        newstr[count++] = address[i];
    }
    newstr[count] = '\0';
    return p;

}
```