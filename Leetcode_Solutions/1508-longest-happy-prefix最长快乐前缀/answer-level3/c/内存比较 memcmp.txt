暴力破解
用memcmp比较，顺利通过

```
bool check_char(char *num1, char *num2, int len)
{
    return (memcmp(num1, num2, len) == 0);
}
char * longestPrefix(char * s){
    int index = 0;
    int len = strlen(s);
    for(index = 0; index < len - 1; index++)
    {
        if(check_char(s, &s[index + 1], len - 1 - index))
        {
            return &s[index + 1];
        }
    }
    
    return "";
}
```
