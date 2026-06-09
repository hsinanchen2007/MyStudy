### 解题思路
    我觉得这道题就是想让你用c来写的，别的语言一行代码就搞定了==
    找到字符串中每个空格的位置，将其后的字符按照从后往前的顺序依次后移两位（因为替换后会多占俩个位置）要注意的是每次操作以后数组长度也要做相应的修改。

### 代码

```c
char* replaceSpace(char* s)
{
    if(!s)
        return NULL;
    char *str = (char *)malloc(10005*sizeof(char*));
    strcpy(str,s);
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(str[i] == ' ')
        {
            for(int j = len; j >= i+1; j--)
            {
                str[j+2] = str[j];
            }
            len+=2;
            str[i] = '%';
            str[i+1] = '2';
            str[i+2] = '0';
            i = i+2;
        }
        
    }
    str[len] = '\0';
    return str;
}
```