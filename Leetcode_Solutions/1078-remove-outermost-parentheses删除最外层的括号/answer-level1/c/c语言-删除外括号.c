### 解题思路
利用栈来括号匹配，中间加一个字符前移

### 代码

```c
int match(char *S,char *stack,int i,int top);
void movek(char *S,int i,int k);
char * removeOuterParentheses(char * S){
    char stack[10000];
    int top=0,i,k=0;
    for(i=0;i<strlen(S);i++)
    {
            if(match(S,stack,i,top)==1)
            {//若字符串匹配，出栈
                top--;//若栈为空，表示一个原语结束
                if(top==0){
                    k++;
                     movek(S,i,k-1);
                }
                else movek(S,i,k);
            }
            else {
                stack[top++]=S[i];
                if(top==1){
                    k++;
                    movek(S,i,k-1);
                }
                else movek(S,i,k);
            }
            
           
    }
    //字符串长度为strlen(s)-k;
    S[strlen(S)-k]='\0';
    return S;            
}
int match(char *S,char *stack,int i,int top)
{
        if(top==0)return 0;
        if(stack[top-1]=='('&&S[i]==')')return 1;
        return 0;
}
void movek(char *S,int i,int k){
    if(i==0)return;
    S[i-k]=S[i];
}
```