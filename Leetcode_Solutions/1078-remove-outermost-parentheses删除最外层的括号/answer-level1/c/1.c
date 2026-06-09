### 解题思路
一个结果字符串, 一个计数器就够了，扫描所给字符串
### 代码

```c
char * removeOuterParentheses(char * S){


//如果是左括号，当count>1时, 写入目标字符串，count始终+1
int i=0,count=0,k=0;
    if(S[0]=='\0') return NULL;
    for(i=0;S[i]!='\0';i++)
    {
        if(S[i]=='(')
        {
            count++;
            if(count>1) S[k++]=S[i];
        }
//如果是右括号，仅当count >= 1的时候, 写入字符串，count始终-1
        if(S[i]==')')
        {
            count--;
            if(count>=1) S[k++]=S[i];
        }
    }
    S[k]='\0';
    return S;
}
```