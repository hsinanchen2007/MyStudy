### 解题思路
利用栈存储，然后字符串比较。
### 代码

```c

void stackProc(char *src, char *des, int len) {
    int top = -1;
    for (int i = 0; i < len; i++) {
        if (src[i] != '#') {
            des[++top] = src[i];
        } else {
            if (top >= 0) {
                des[top] ='\0';
                top--;
            }
        }
    } 
    return;      
}

bool backspaceCompare(char * S, char * T){
    int len1 = strlen(S);
    int len2 = strlen(T);

    char *stack_S = (char *)malloc(sizeof(char) * (len1 + 1));
    char *stack_T = (char *)malloc(sizeof(char) * (len2 + 1));
    memset(stack_S, '\0', sizeof(char) * (len1 + 1));
    memset(stack_T, '\0', sizeof(char) * (len2 + 1));

    stackProc(S, stack_S, len1);
    stackProc(T, stack_T, len2);

    if (strcmp(stack_S, stack_T) != 0) {
        free(stack_S);
        free(stack_T);
        return false;
    }
    free(stack_S);
    free(stack_T);
    return true;
}
```