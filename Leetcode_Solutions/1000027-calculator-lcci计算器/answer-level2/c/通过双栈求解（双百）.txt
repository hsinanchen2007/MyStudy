### 解题思路
此处撰写解题思路

### 代码

```c
int calculate(char* s){
    int len=strlen(s);
    int num[len], top1=-1;
    char sg[len], top2=-1;
    int flag=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]==' ')
        {
            flag=0;
            continue;
        }
        if(!(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'))
        {
            if(flag==0)                 
                num[++top1]=s[i]-'0';
            else
                num[top1]=num[top1]*10+(s[i]-'0');        //考虑多位数
            flag=1;
        }
        else
        {
            flag=0;
            if(top2==-1)
            {
                sg[++top2]=s[i];
            }
            else if(s[i]=='+' || s[i]=='-')
            {
                while(top2>=0)
                {
                    char temp=sg[top2];
                    int sum;
                    switch(temp)
                    {
                        case '+':
                            sum=num[top1-1]+num[top1];
                            break;
                        case '-':
                            sum=num[top1-1]-num[top1];
                            break;
                        case '*':
                            sum=num[top1-1]*num[top1];
                            break;
                        case '/':
                            sum=num[top1-1]/num[top1];
                    }
                    num[--top1]=sum;
                    top2--;
                }
                sg[++top2]=s[i];
            }
            else if((s[i]=='*' || s[i]=='/') && (sg[top2]=='+' || sg[top2]=='-'))
            {
                sg[++top2]=s[i];
            }
            else if((s[i]=='*' || s[i]=='/') && (sg[top2]=='*' || sg[top2]=='/'))
            {
                while(top2>=0 && (sg[top2]=='*' || sg[top2]=='/'))
                {
                    if(sg[top2]=='*')
                    {
                        int sum=num[top1-1]*num[top1];
                        num[--top1]=sum;
                    }
                    else
                    {
                        int sum=num[top1-1]/num[top1];
                        num[--top1]=sum;
                    }
                    top2--;
                }
                sg[++top2]=s[i];
            }
        }
    }
    while(top2>=0)
    {
        int sum;
        switch (sg[top2--])
        {
            case '+':
                sum=num[top1-1]+num[top1];
                break;
            case '-':
                sum=num[top1-1]-num[top1];
                break;
            case '*':
                sum=num[top1-1]*num[top1];
                break;
            case '/':
                sum=num[top1-1]/num[top1];
                break;
        }
        num[--top1]=sum;
    }
    return num[0];
}
```