

![Screenshot 2020-03-19 at 12.34.43 AM.png](https://pic.leetcode-cn.com/61db05b6e8e1f1fe48ab08bab2742b2d864abbad50af86b5024372af10f2c63f-Screenshot%202020-03-19%20at%2012.34.43%20AM.png)


```c
bool isValid(char * s){
    int len = strlen(s);
    if (len % 2) return false;
    char *stack = (int *) malloc (sizeof(char) * len);
    int top = -1;
    int i;
    for(i = 0; i < len; i++) {
        if (s[i] == ')') {
            if (top < 0  ||  stack[top--] != '(') return false;
        }
        else if (s[i] == '}') {
            if (top < 0 || stack[top--] != '{') return false;
        }
        else if (s[i] == ']' ) {
            if (top < 0 || stack[top--] != '[') return false;
        }
        else  stack[++top] = s[i];
    }
    return top == -1 ? true : false;
}
```
