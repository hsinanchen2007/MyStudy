### 解题思路
此处撰写解题思路
(1)两字符串程度相差大于1，直接返回false
(2)满足(1)的条件时，有任一字符串长度为1可直接返回true
(3)满足(1)而不满足(2)时，有任一字符串长度为1，且此唯一的字符与另外一个目标字符串中某个字符相同则返回true,没有相同的字符返回false
(4)满足(1)且长度至少为2的两个字符串，有少于2个字符不同时返回true，有2个及以上不同时返回false
### 代码

```c
#include <string.h>

bool oneEditAway(char* first, char* second)
{
    char * lon=NULL,* shot=NULL;
    int len1=strlen(first),len2=strlen(second);
    bool same=false,flag=false;
    int sub=len1-len2;
    switch(sub)
    {
        case 1:
        lon=first;
        shot=second;
        same=false;
        break;
        case -1:
        lon=second;
        shot=first;
        same=false;
        break;
        case 0:
        same=true;
        break;
        default:
        return false;
    }
    if(len1==0 || len2==0)
        return true;
    else if(len1==1 || len2==1)
    {
        if(same)
            return true;
        else if(*shot==lon[0] || *shot==lon[1])
            return true;
        else
            return false;
    }
    if(same)
    {
        while(*first)
        {
            if(*first!=*second)
            {
                if(flag)
                    return false;
                else
                    flag=true;
            }
            first++;
            second++;
        }
    }
    else
    {
        while(*lon)
        {
            if(*lon!=*shot)
            {
                if(flag)
                    return false;
                else
                {
                    flag=true;
                    lon++;
                    continue;
                }
            }
            lon++;
            shot++;
        }
    }
    return true;
}
```