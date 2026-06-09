### 解题思路
其实这道题的思路非常简单，括号问题如果学过数据结构第一个思路就是栈，用栈来实现
但是既然是leetcode上的题肯定就不会像我们学的时候那么简单，学的时候只是懂原理并实现。
   
 该题有一个陷阱，第一个元素可能为‘）’，‘]’，‘}’，这就需要我们灵活多变，我们再增加条件即可，重点是自己多尝试，加油！
### 代码

```c
bool isValid(char * s){
    if(s[0]=='\0')
        return true;
    int n=strlen(s);
    int i=0;
    char str[n],st;
    int top=-1;
    while(s[i]!='\0')
    {
        st=s[i];
        switch(s[i])
        {
            case '(':top++;str[top]=st;break;
            case ')':
             if(top==-1)//防止出现第一个元素就是该值的可能，下面同理
            {
                top++;
                str[top]=st;
                break;
            }
            if(str[top]=='(')
            {
                top--;
                break;
            }
            else
            {
                top++;
                str[top]=st;
                break;
            }
            case '[':top++;str[top]=st;break;
            case ']':
            if(top==-1)
            {
                top++;
                str[top]=st;
                break;
            }
            if(str[top]=='[')
            {
                top--;
                break;
            }
            else
            {
                top++;
                str[top]=st;
                break;
            }
            case '{':top++;str[top]=st;break;
            case '}':
            if(top==-1)
            {
                top++;
                str[top]=st;
                break;
            }
            if(str[top]=='{')
            {
                top--;
                break;
            }
            else
            {
                top++;
                str[top]=st;
                break;
            }
        }
        i++;
    }
    if(top==-1)
        return true;
    else
        return false;
}
```
代码通俗易懂，在这里不做过多的解释！