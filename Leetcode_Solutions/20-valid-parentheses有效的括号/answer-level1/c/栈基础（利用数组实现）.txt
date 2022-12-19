### 解题思路
代码比较啰嗦，主要是"" - true，" " - false返回的结果不同

### 代码

```c
#define MAXSIZE 10000

bool isValid(char * s){

    char *stack;
    stack = (char *)malloc(sizeof(char) * MAXSIZE);
    memset (stack, 0, sizeof(char) * MAXSIZE);

    int len = strlen(s);
    int top = -1;
    bool res = false;

    if (len == 0)
        return true;

    for (int i = 0; i < len; i ++)
    {
        if (s[i] == ' ')
        {
            res = false;
            continue;
        }
        
        if (s[i] == '(' | s[i] == '[' || s[i] == '{')
        {
            stack[++top] = s[i];
        }
        else
        {
            if (top == -1)
            {
                res = false;
                break;
            }
            
            if (s[i] == ')')
            {
                if (stack[top] == '(')
                {
                    res = true;
                    top --;
                }
                else
                {
                    res = false;
                    break;
                }
            }
            else if (s[i] == ']')
            {
                if (stack[top] == '[')
                {
                    res = true;
                    top --;
                }
                else
                {
                    res = false;
                    break;
                }
            }
            else if (s[i] == '}')
            {
                if (stack[top] == '{')
                {
                    res = true;
                    top --;
                }
                else
                {
                    res = false;
                    break;
                }
            }
            else
            {
                res = false;
                break;
            }
        }
    }

    if (top > -1)
    {
        res = false;
    }

    return res;
}
```