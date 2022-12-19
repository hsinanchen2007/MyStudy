### 解题思路
此处撰写解题思路
用switch 判断，有几种特殊情况，就得列出来
### 代码

```c
int romanToInt(char * s)
{
    int num;
    int sum=0;

    while(*s!='\0')
    {
        switch(*s)
        {
            case 'I':num=1;
            if(*(s+1)=='V')
            {
               num=4;
               ++s;
                
            }
            else if(*(s+1)=='X')
            {
                 num=9;
                 ++s;
               
            };break;
            case 'V':num=5;break;
            case 'X':num=10;
            if(*(s+1)=='L')
            {
                num=40;
                ++s;
            }
            else if(*(s+1)=='C')
            {
                num=90;
                ++s;
                
            };
            break;
            case 'L':num=50;break;
            case 'C':num=100;
            if(*(s+1)=='D')
            {
                num=400;
                ++s;
            }
            else if(*(s+1)=='M')
            {
                 num=900;
                   ++s;
            };
            break;
            case 'D':num=500;break;
            case 'M':num=1000;break;

        }
        sum=sum+num;
        s++;

    }
return sum;
}
```