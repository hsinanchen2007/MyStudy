### 解题思路

每有一个'(',i加1,每有一个')',i减1,我这是考虑到了样例一定没出错,即左括号和右括号数量一定相等

### 代码

```c
char * removeOuterParentheses(char * S){
    int i=-1,n=0,m=0;
    char b;
    while(b=S[m++])
    {
        if(b=='(')
        {
            if(i==-1)
                i++;
            else
            {
                i++;
                S[n++]=b;
            }
        }
        if(b==')')
        {
            if(i==0)
                i--;
            else
            {
                i--;
                S[n++]=b;
            }
        }
    }
    S[n]='\0';
    return S;
}
```