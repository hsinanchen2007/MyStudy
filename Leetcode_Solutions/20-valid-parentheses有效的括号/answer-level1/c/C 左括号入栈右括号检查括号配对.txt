### 解题思路
1、判断字符串大小和长度，如果长度为奇数，返回false
2、循环遍历，遇到左括号进行入栈
3、遇到右括号，与栈顶元素进行配对，如果不配对，则返回false
4、配对OK，将栈顶元素出栈
5、直至循环结束，检查栈是否为空，非空返回false


### 代码

```c
bool isValid(char * s){
    char *stack_array = NULL; 
    int stack_top = 0;
    if (s == NULL)
        return false;
    int str_len = strlen(s);
    printf("%d\n", str_len);
    if (str_len == 0)   // 空字符串返回true
        return true;
    if (str_len % 2 == 1)
        return false;
    stack_array = (char *)malloc(sizeof(char) * str_len);
    for (int i = 0; i < str_len; i++) {
        stack_array[i] = '\0';
    }

    for (int i = 0; i < str_len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            // push
            stack_array[stack_top] = s[i];
            stack_top++;
            printf("A%d,%c\n", stack_top,stack_array[stack_top-1]);
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (stack_top == 0) { // check start postion
                free(stack_array);
                return false;
            }
            //push && check
            if ((stack_array[stack_top -1 ] == '(' && s[i] == ')') 
            || (stack_array[stack_top - 1] == '[' && s[i] == ']')
            || (stack_array[stack_top - 1] == '{' && s[i] == '}')) {
                stack_array[stack_top - 1] = '\0';
                stack_top--;
                printf("B%d\n", stack_top);
            } else {
                printf("C%d\n", stack_top);
                free(stack_array); 
                return false;
            }
        } else {
            printf("D%d\n", stack_top);
            free(stack_array);
            return false;
        }
    }
    free(stack_array);
    if (stack_top != 0)
        return false;
    return 
        true;
}
```