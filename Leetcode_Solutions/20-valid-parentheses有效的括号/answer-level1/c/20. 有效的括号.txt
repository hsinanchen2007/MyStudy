### 解题思路
此处撰写解题思路
注意要求：
1、堆栈的大小要根据测试用例的长度，所以尽量大，故9999
2、堆栈的index小于0时会报错，在codeblocks中无错，故top = 1
![CgoB5l2IRLSATKk3AMg-Ag7s3RA865.gif](https://pic.leetcode-cn.com/432f26a397af0c53490cab915b881172556aedc0e867e612ab12f59f5ed4ad63-CgoB5l2IRLSATKk3AMg-Ag7s3RA865.gif)
### 代码

```c

bool isValid(char * p)
{
    int len=strlen(p);
    if(len == 1)
        return 0;
    int top=1,i;
    char s[9999];  //堆栈存储
    for(i=0; i<len; i++)
    {
        switch(p[i])
        {
        case '(':
        case '[':
        case '{':
            s[top++]=p[i];
            break;
        case ')':
            if(s[top-1]=='(')
                top--;
            else return 0;
            break;
        case ']':
            if(s[top-1]=='[')
                top--;
            else return 0;
            break;
        case '}':
            if(s[top-1]=='{')
                top--;
            else return 0;
            break;
        }
    }
    if(top==1)
        return 1;  //输出1表示匹配成功
    else
        return 0;   //输出0表示匹配失败
}
```