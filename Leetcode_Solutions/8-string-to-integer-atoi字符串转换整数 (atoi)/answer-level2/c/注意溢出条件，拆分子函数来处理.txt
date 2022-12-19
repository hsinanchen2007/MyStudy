### 解题思路
首先找到第一个不为空的字符位置，特别注意要区分空格' '
随后分2种情况
一种是开头为'+'或者'-'，然后从下一位置开始，求连续的整数
另一种直接是 '0'到'9'的数字，直接从当前位置求连续整数
最好定义一个字函数来求这个整数，这样代码结构很明了，特别注意溢出的判断

### 代码

```c
int findNumStr(char *str, int maxLen, int flag)
{
    //定义long long 型，溢出int也没关系
    long long res = 0;
    int i   = 0;
    
    if(maxLen <= 0)
    {
        return 0;
    }

    while(i < maxLen)
    {
        if((str[i] < '0' )||(str[i] > '9'))
        {
            break;
        }
        else
        {
            res = res * 10;
            res = res + (str[i] - '0');

            //溢出则直接返回
            if(res * flag > INT_MAX)
            {
                return INT_MAX;
            }

            if(res * flag < INT_MIN)
            {
                return INT_MIN;
            }
            
            i++;
        }
    }

    return (int)(flag * res);
}

int myAtoi(char * str)
{
    int len = strlen(str);
    int flag  = -1;
    int i   = 0;
    int res = 0;

    if(0 == len)
    {
        return 0;
    }

    while(i < len)
    {
        //当判断到字符串为空格或者为空则空转
        if((' ' == str[i])||(0 == str[i]))
        {
            i++;
            continue;
        }

        //找到第一个起始字符后开始寻找其对应的数字
        if((str[i] == '-') || (str[i] == '+'))
        {
            if((i + 1) < len)
            {
                flag = (str[i] == '-') ? -1 : 1;    
                res = findNumStr(&str[i+1], len - i - 1, flag);
            }

            break;
        }

        if((str[i] >= '0')&&(str[i] <= '9'))
        {
            flag = 1;
            res = findNumStr(&str[i], len - i, flag);
            break;
        }

        break;
        
    }

    return res;
}
```