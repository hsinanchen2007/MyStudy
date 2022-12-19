### 解题思路
1.定义str数组，top指针解决问题
2.遍历s如果是左括号则进栈
3.遍历s如果是右括号则分三种情况：
   1str为空则出错
   2str栈顶元素不是与之对应的左括号则出错
   3栈顶元素是与之对应的左括号，将其出栈，继续比较

### 代码

```c
bool isValid(char * s){
    int n=strlen(s);
    char str[++n];
    int i=0,top=-1;
    if(s[0]=='\0')
    return true;
    while(s[i]!='\0')
    {   
        
        switch(s[i])
        {
            case '(':top++;str[top]=s[i];i++;break;
            case '[':top++;str[top]=s[i];i++;break;
            case '{':top++;str[top]=s[i];i++;break;
            case ')':
                if(top==-1) return false;
                if(str[top]!='(') return false;
                else
                {
                    str[top]='\0';
                    top--;
                    i++;
                    break;
                }
            case ']':
                if(top==-1) return false;
                if(str[top]!='[') return false;
                else{
                    str[top]='\0';
                    top--;
                    i++;
                    break;
                }
            case '}':
                if(top==-1) return false;
                if(str[top]!='{') return false;
                else{
                    str[top]='\0';
                    top--;
                    i++;
                    break;
                }
        }
    }
    if(top==-1) return true;
    else {return false;}
}
```