### 解题思路
辅助栈，开括号逆向转换为对应的闭括号入栈，如果是开括号，则入栈，如果是闭括号，则匹配栈顶元素，匹配则继续，不匹配则返回false结束；如果字符串遍历完成辅助栈不空，则返回false。

### 代码

```c
bool isValid(char * s) {
    int top = 0;
    int size;
    bool bValid = true;
    char *stack = NULL;
    
    if (*s == '0') {
        return true;
    }

    size = strlen(s);
    if ((size % 2) != 0) {
        return false;
    }

    stack = malloc(size);

    for (int i = 0; i < size; i++) {
        if (s[i] == '(' ) {
            stack[top] = ')';
            top++;
        } else if (s[i] == '[') {
            stack[top] = ']';
            top++;
        } else if (s[i] == '{') {
            stack[top] = '}';
            top++;
        } else if (top > 0 && stack[top - 1] == s[i]) {
            top--;
            stack[top] = 0;
        } else {
            bValid = false;
            break;
        }
    }
    
    if (top > 0) {
        bValid = false;
    }

    free(stack);
    stack = NULL;

    return bValid;
}
```