### 解题思路
遇到数字或字母就入栈。然后从栈顶和字符串开头开始比较，遇到字母或数字不相等就返回０，忽略大小写。若最后栈非空，返回０，否则返回１。

### 代码

```c
bool isPalindrome(char * s){
    if(s == "")
        return 1;

    int len = strlen(s);
    char *stk = (char*)malloc(sizeof(char) * len);
    int top = -1, i;
    for(i = 0; i < len; i++){
        if(isupper(s[i])){
            stk[++top] = s[i] + 32;
        }
        else if(islower(s[i]) || isdigit(s[i])){
            stk[++top] = s[i];
        }
    }
    for(i = 0; i < len; i++){
        if(isupper(s[i])){
            char t = stk[top];
            if(s[i] + 32 != t)
                return 0;
            top--;
        }
        else if(islower(s[i]) || isdigit(s[i])){
            char t = stk[top];
            if(s[i] != t)
                return 0;
            top--;
        }
    }
    if(top >= 0)
        return 0;
    return 1;
}
```