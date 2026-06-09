### 解题思路
遇到数字入栈，遇到算术符出栈并将算术结果入栈

### 代码

```c
bool isNumber(char *str) {
    if (*str == '*' || *str == '/' || *str == '+') return false;
    if (*str == '-' && strlen(str) == 1) return false;
    return true;
}
int convertToNumber(char *str) {
    int result = 0;
    if (*str == '-') {
        for (int i = 1; i < strlen(str); i ++) {
            result = result * 10 + (*(str + i) - '0');
        }
        result = 0 - result;
    }
    else {
        for (int i = 0; i < strlen(str); i ++) {
            result = result * 10 + (*(str + i) - '0');
        }
    }
    return result;
}
int evalRPN(char ** tokens, int tokensSize){
    if (tokensSize == 1) {
        return convertToNumber(tokens[0]);
    }
    int result = 0;
    int stack[10000] = {0};
    int count = 0;
    for (int i = 0; i < tokensSize; i ++) {
        if (isNumber(tokens[i])) {
            stack[count ++] = convertToNumber(tokens[i]);
        }
        else {
            if (*tokens[i] == '+') {
                result = (stack[count - 2] + stack[count - 1]);
            }
            if (*tokens[i] == '-') {
                result = (stack[count - 2] - stack[count - 1]);
            }
            if (*tokens[i] == '*') {
                result = (stack[count - 2] * stack[count - 1]);
            }
            if (*tokens[i] == '/') {
                result = (stack[count - 2] / stack[count - 1]);
            }
            count -= 1;
            stack[count - 1] = result;
        }
    }
    return result;
}
```