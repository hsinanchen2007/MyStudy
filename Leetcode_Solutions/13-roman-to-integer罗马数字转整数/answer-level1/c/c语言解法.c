### 解题思路
利用了大量的if语句。
### 代码

```c
int romanToInt(char* s){
    int cnt=0;
    int* p=(int*)calloc(sizeof(int),strlen(s)+1);
    for(int i=0;i<strlen(s);i++)
    {
        switch(s[i])
        {
            case 'I':p[i]=1;break;
            case 'V':p[i]=5;break;
            case 'X':p[i]=10;break;
            case 'L':p[i]=50;break;
            case 'C':p[i]=100;break;
            case 'D':p[i]=500;break;
            case 'M':p[i]=1000;break;
        }
    }
    for(int i=0;i<strlen(s)+1;)
    {
        if(p[i]==1&&p[i+1])
        {
            if(p[i+1]==5||p[i+1]==10)
            {
                cnt+=(p[i+1]-p[i]);
                i+=2;
            }
            else
            {
                cnt+=p[i];
                i++;
            }
        }
        else if(p[i]==10&&p[i+1])
        {
            if(p[i+1]==50||p[i+1]==100)
            {
                cnt+=(p[1+i]-p[i]);
                i+=2;
            }
            else
            {
                cnt+=p[i];
                i++;
            }
        }
        else if(p[i]==100&&p[i+1])
        {
            if(p[i+1]==500||p[i+1]==1000)
            {
                cnt+=(p[i+1]-p[i]);
                i+=2;
            }
            else
            {
                cnt+=p[i];
                i++;
            }
        }
        else
        {
            cnt+=p[i];
            i++;
        }

    }
    return cnt;
}
```