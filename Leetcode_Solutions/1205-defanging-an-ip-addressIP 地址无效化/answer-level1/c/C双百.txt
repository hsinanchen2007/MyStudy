### 解题思路
此处撰写解题思路

### 代码

```c
char * defangIPaddr(char * address)
{
    int i;
    char* res=(char*)malloc((strlen(address)+7)*sizeof(char));
    int len = strlen(address)+6;
    res[len--] = '\0';
    i = strlen(address)-1;
    while(i>=0)
    {
        if(address[i] != '.')
        {
            res[len--] = address[i]; 
        }
        else
        {
            res[len--] = ']';
            res[len--]='.';
            res[len--]='[';
        }
        i--;
    }
    return (res);
}
```