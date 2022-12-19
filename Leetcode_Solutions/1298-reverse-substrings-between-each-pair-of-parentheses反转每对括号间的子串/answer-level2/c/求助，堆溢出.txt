```
void reverse(char *s,int start,int end)
{
    while(start<end)
    {
        if(s[start]=='(' || s[start]==')')
        {
            start++;
            continue;
        }
        if(s[end]==')' || s[end]=='(')
        {
            end--;
            continue;
        }
        char temp=s[start];
        s[start]=s[end];
        s[end]=temp;
        start++;
        end--;
    }
}
char * reverseParentheses(char * s){
    int data[2000]={0};  //数组模仿栈，存放左阔号位置
    int top=0;   //栈顶指针
    int i=0;

    while(s[i]!='\0')
    {
        while(s[i]!='\0' && s[i]!='(' && s[i]!=')')
            i++;
        if(s[i]=='(')
        {
            data[top++]=i+1;   //因为data的初始元素为0，所以第一个元素索引设为1
            i++;
            continue;
        }else if(s[i]==')')
        {
            reverse(s,data[top-1],i-1);     //确定好括号的位置很关键
            top--;
            i++;
            continue;
        }
        else   //括号全部被处理
            break;
    }
    
    char *result=malloc(i);
    int j;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]!='(' && s[i]!=')')
        {
            result[j]=s[i];
            j++;
        }
    }
    result[j]='\0';
    return result;
}
```
