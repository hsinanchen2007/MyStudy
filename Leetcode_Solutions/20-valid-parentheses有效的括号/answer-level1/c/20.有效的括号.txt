### 解题思路
此处撰写解题思路
**正确的输入**：括号与栈首匹配则出栈，最终栈空。
**错误判断**：
+ 1.栈首为[{(,当前括号为]})，但不匹配；
+ 2.栈首为]}) *（因为若正确，一定已经出栈）*；
+ 3.遍历完，栈非空则错。
**启示**
可以从几个例子入手，先给各种情况分类
### 代码

```c
bool isValid(char * s){
    typedef struct l{
        char c;
        struct l* next;
    }Stack;
    typedef Stack* pStack;
    int len = strlen(s);
    int size = 0;
    pStack first;
    for(int i = 0;i < len;i++)
    {
        if(size==0)
        {
            first=(pStack)malloc(sizeof(Stack)); 
            first->next=NULL;
            first->c=s[i];
            size++;
        }
        else if(first->c=='}'||first->c==']'||first->c==')')
        {
            return 0;
        }
        else
        { 
            if((first->c=='{'&&s[i]=='}')||(first->c=='['&&s[i]==']')||(first->c=='('&&s[i]==')'))
            {
                pStack tmp=first;
                first=first->next;
                free(tmp);
                size--;
            }
            else if(s[i]=='{'||s[i]=='['||s[i]=='(')//
            {
            	pStack tmp=(pStack)malloc(sizeof(Stack));
            	tmp->next=first;
            	tmp->c=s[i];
            	first=tmp;
            	size++;
            }
            else
            {
               return 0; 
            }
        }
    }
    if(size!=0)
    return 0;
    else 
    return 1;
}
```