### 解题思路
暴力解题都花了一个小时，太菜了
执行用时 :
4 ms
, 在所有 C 提交中击败了
77.22%
的用户
内存消耗 :
5.4 MB
, 在所有 C 提交中击败了
100.00%
的用户

### 代码

```c
int myAtoi(char* str) {
    long lresult = 0;
    long ltmp = 0;
    int iBit = 0;
    int isign = -1; //0为无符号,1为正数,2为负数
    int i;

    for(i=0; str[i]!='\0'; i++)
    {
        if(-1 == isign)
        {
            if(str[i] == '+')
            {
                isign = 1;
            }
            else if(str[i] == '-')
            {
                isign = 2;
            }
            else if((str[i] >= '0') && (str[i] <= '9'))
            {
                isign = 0;
                i--;
            }
            else if(str[i] == ' ' || str[i] == '\"')
            {
                continue;
            }
            else
            {
                lresult = 0;
                break;
            }
        }
        else
        {
            if((str[i] >= '0') && (str[i] <= '9'))
            {
                iBit++;
                ltmp = str[i]-'0';
            }
            else
            {
                break;
            }

            if(INT_MAX < lresult * 10 + ltmp)
            {
                if(2 == isign)
                {
                    lresult = INT_MIN;
                }
                else
                {
                    lresult = INT_MAX;
                }
                break;
            }
            lresult =  lresult * 10 + ltmp;
        }

    }

    if(2 == isign)
    {
        lresult = lresult * (-1);
    }
    return lresult;
}
```