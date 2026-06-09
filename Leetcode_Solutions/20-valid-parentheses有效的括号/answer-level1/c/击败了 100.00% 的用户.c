### 解题思路
1. 利用辅助栈，遍历字符串
2. 出现")]}"时弹栈，如果弹出的不匹配，则返回false
3. 遍历字符串结束后，如果栈空则true否则false

### 代码

```c
bool isValid(char * s){
    char *str = (char *)malloc(sizeof(char) * strlen(s));
    int num = 0;

    while (*s != '\0')
    {
        if (num == 0 || *s == '(' || *s == '[' || *s == '{')
        {
            str[num++] = *s;
        } 
        else if (*s == ')')
        {
            if (str[num - 1] == '(') num--;
            else 
            {   
                free(str);
                return false;
            }
        }
        else if (*s == ']')
        {
            if (str[num - 1] == '[') num--;
            else 
            {   
                free(str);
                return false;
            }
        }
        else if (*s == '}')
        {
            if (str[num - 1] == '{') num--;
            else 
            {   
                free(str);
                return false;
            }
        }
        s++;
    }
    free(str);
    if (num == 0) return true;
    else return false;
}
```