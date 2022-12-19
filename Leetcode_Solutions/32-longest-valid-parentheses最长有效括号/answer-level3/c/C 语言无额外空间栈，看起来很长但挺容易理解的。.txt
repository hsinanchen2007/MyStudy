    最快 0 ms,平均 4 ms，内存 7.3 MB，有待优化。
    代码看起来很长，但其实前后顺序和逆序部分重复度很高，可以优化。
    题目分为两种情况：1.左括号多于右括号个数；2.右括号多于等于左括号个数。
    写一个顺序遍历，在情况2下可找出所有合法子串大小，这并不难。然后，若是在情况1下，则在最后一个不合法子串那截至，
此时之前的情况均属于情况2。最后，记录下最后一个不合法子串的下标x。
    写一个逆序的，并非完全逆序，而是从末尾到x遍历。此时必定属于情况2，但因为是逆序要互换’（‘和’）‘，所以可以套用
顺序遍历。

    **顺序时子串内的元素只包含’（‘，逆序只包含’）‘。**
```


int longestValidParentheses(char * s){//**以题目给的s为栈，故不用额外空间**
    int len=strlen(s);
    if(len<=1)
        return 0;

    int t=0;//****
    int tail=0;//**栈顶指针，保存栈内第一个‘（’的下标**
    int top=-1;//*栈顶指针，实际上保存‘（’的个数**
    int max=0;
    int m=0;
    
    while(t<len&&tail-m<len-max)**顺序遍历**
    {
        if(s[t]=='(')//**入栈**
        {
            top++;
            if(top==0)
            {
                tail=t;
            }
        }
        else if(s[t]==')')
        {
            if(top>=0)//**出栈**
            {
                top--;
                m+=2;
                if(top<0&&m>max)
                    max=m;  
            }
            else//**清空栈**
            {
                top=-1;
                m=0;
            }
        }
        t++;
    }
    if(top!=-1)
    {
        t=len-1;
        len=tail;
        tail=t;
        top=-1;
        m=0;
        
       while(t>=len&&tail+m>len+max)**逆序遍历**
        {
            if(s[t]==')')//**入栈**
            {
                top++;
                if(top==0)
                {
                    tail=t;
                }
            }
            else if(s[t]=='(')
            {
                if(top>=0)//**出栈**
                {
                    top--;
                    m+=2;
                    if(top<0&&m>max)
                        max=m;  
                }
                else//**清空栈**
                {
                    top=-1;
                    m=0;
                }
            }
        t--;
        }
    }
    
    return max;
}


```

