### 解题思路
#1 给每个罗马字符标注优先级
#2 扫描字符串，如果当前罗马字符大于等于下一个罗马字符代表的数值，则加到结果中，否则减掉

### 代码

```c

int pr(char  s)//判断当前罗马字符的优先级
{
    switch(s)
    {
        case '\0': return -1;break;
        case 'I': return 0;break;
        case 'V': return 1;break;
        case 'X': return 2;break;
        case 'L': return 3;break;
        case 'C': return 4;break;
        case 'D': return 5;break;
        case 'M': return 6;break;
        default: return 0;
    }
}

int val(char  s)//返回该罗马字符代表的数值
{
    switch(s)
    {
        case '\0': return 0;break;
        case 'I': return 1;break;
        case 'V': return 5;break;
        case 'X': return 10;break;
        case 'L': return 50;break;
        case 'C': return 100;break;
        case 'D': return 500;break;
        case 'M': return 1000;break;
        default: return 0;
    }
}

int romanToInt(char * s){
    int solution = 0;
    char * t = s;
    for(int i = 0 ; i < strlen(s) ; i++)
    {
        if(pr(t[i]) >= pr(t[i+1])) 
        {
            solution += val(t[i]);
        }
        else    solution -=val(t[i]);
    }
    return solution;
}


```