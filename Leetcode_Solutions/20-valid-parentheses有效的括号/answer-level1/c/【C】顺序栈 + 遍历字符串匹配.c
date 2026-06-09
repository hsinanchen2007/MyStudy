### 解题思路

顺序栈 + 遍历字符串匹配

说明在注释里

### 代码

```c
bool isValid(char * s){
    //空字符串显然符合
    if(*s == 0) return true;

    int len = strlen(s);

    //奇数长度的字符串显然不符合
    if(len & 1) return false;

    char stack[len];
    int top = -1;
    for(int i=0; i<len; ++i){
        //如果是左括号们，欢迎入栈
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            stack[++top] = s[i];
        //不是左括号们，如果栈空则无法配对，不符合
        else if(top == -1) return false;
        //不是左括号们，栈非空，当前和栈顶配对，符合
        else if(s[i] == stack[top]+1 || s[i] == stack[top]+2)
            stack[top--] = 0;
        //不是左括号们，栈非空，当前和栈顶不配对，不符合
        else return false;
    }
    //最后栈为空则符合，不为空则不符合
    return top == -1;
}
```