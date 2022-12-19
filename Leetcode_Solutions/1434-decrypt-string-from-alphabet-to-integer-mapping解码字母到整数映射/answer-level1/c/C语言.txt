### 解题思路
此处撰写解题思路

### 代码

```c
char * freqAlphabets(char * s)
{
    int i, len = strlen(s);
    char c;
    char *res = (char*)malloc(sizeof(char) * (len + 1));
    int p = 0;
    for (i = 0; i < len; i++)
    {
        if (i + 2 < len && s[i + 2] == '#')
        {
            c = (s[i] - '0') * 10 + s[i + 1] - '0' - 1 + 'a';
            i += 2;
        }
        else
            c = s[i] - '0' - 1 + 'a';
        res[p++] = c;
    }
    res[p] = '\0';
    return res;
}
```