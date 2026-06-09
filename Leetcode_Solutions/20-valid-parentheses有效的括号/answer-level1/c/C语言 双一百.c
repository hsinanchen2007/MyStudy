### 解题思路
s判定条件 如果符合 那么字符串对称位置 必然 是对应的括号（根据题中意思）
我只是个两个月的小白，具体栈我不是很懂。
但我的基本思想就是  构造一个 前半部分的括号字符串，再与后半部分进行逐个比较 这样就可完成判断
### 代码

```c
bool isValid(char * s){
    if(s==NULL||s[0]=='\0')    return true;
    int top=0;
    char *stack=(char*)malloc(strlen(s)+1);
    for(int i=0;s[i];i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            stack[top++]=s[i];
        else
        {
            if((--top)<0)      return false;  //栈顶到栈尾
            if((s[i]==')'&&stack[top]!='(')||(s[i] == ']' && stack[top] != '[')||(s[i] == '}' && stack[top] != '{'))
                return false;
        }
    }
    return (!top);               //全不为括号情况
}


```