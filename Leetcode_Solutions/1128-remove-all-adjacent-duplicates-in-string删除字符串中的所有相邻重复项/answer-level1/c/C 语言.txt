### 解题思路
使用栈
T: 4 ms, 98.82%, O(N)
S: 9.4 MB, 100.00%, O(1)

### 代码

```c
char * removeDuplicates(char * S){
    char *stack = (char *)malloc(sizeof(char) * (20000 + 2));
    int top = -1;

    for (int i = 0; S[i] != '\0'; ++i) {
        if (top == -1 || stack[top] != S[i]) {// 短路计算，无妨
            stack[++top] = S[i];
            continue;
        }
        top--;
    }

    stack[top + 1] = '\0';
    return stack;
}
```