### 解题思路
此处撰写解题思路
利用数组，左括号“进栈”，遇到右括号就看前一个是否匹配，匹配就“出栈”，否则非法；
当然要考虑第一个就是右括号的情况。

### 代码

```c
bool isValid(char * s){
    int len = strlen(s);
    if (len == 0)
    {
        return true;
    }

    if (len == 1)
    {
        return false;
    }

    char *tmp_str = (char*)malloc(sizeof(char) * (len+1));
    if (tmp_str == NULL)
    {
        return false;
    }
    memset(tmp_str, 0, sizeof(char) * (len+1));
    int cursor = 0;
    for (int i=0;i<len;i++)
    {
        if (s[i] == ' ')
        {
            continue;
        }
        if ('(' == s[i] || '[' == s[i] || '{' == s[i])
        {
            tmp_str[cursor++] = s[i];
        }
        else
        {
            if (cursor == 0 && (')' == s[i] || ']' == s[i] || '}' == s[i]))
            {
                return false;
            }            
            if ((')' == s[i] && '(' == tmp_str[cursor-1]) || (']' == s[i] && '[' == tmp_str[cursor-1]) || ('}' == s[i] && '{' == tmp_str[cursor-1]))
            {
                tmp_str[cursor--] = ' ';
            }
            else
            {
                return false;
            }
        }
    }

    free(tmp_str);

    if (cursor == 0)
    {
        return true;
    }
    return false;
}
```