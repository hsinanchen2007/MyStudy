### 解题思路

1、s[i] = 0时，若s[i-1]是1或2，则dp[i] = dp[i-2]，否则解码出错
2、else if s[i-1]是1，dp[i] = dp[i-1] + dp[i-2]
3、else if s[i-1]是2，且s[i]小于7，dp[i] = dp[i-1] + dp[i-2]
4、else dp[i] = dp[i-1]

### 代码

```c
int numDecodings(char * s)
{
    int i     = 0;
    int size  = 0;
    int res   = 0;
    int n_1   = 0;
    int n_2   = 0;

    size      = strlen(s);
    /***********************************************************
    1、s[i] = 0时，若s[i-1]是1或2，则dp[i] = dp[i-2]，否则解码出错
    2、else if s[i-1]是1，dp[i] = dp[i-1] + dp[i-2]
    3、else if s[i-1]是2，且s[i]小于7，dp[i] = dp[i-1] + dp[i-2]
    4、else dp[i] = dp[i-1]
    ***********************************************************/
    if('0' == s[0])
    {
        return 0;
    }

    n_2 = 1;
    n_1 = 1;
    res = 1;

    for(i = 1;i<size;i++)
    {
        if('0' == s[i])
        {
            if(('1' == s[i-1])||('2' == s[i-1]))
            {
                res = n_2;
            }
            else
            {
                return 0;
            }
        }        
        else if('1' == s[i-1])
        {
            res = n_2 + n_1;
        }
        else if(('2' == s[i-1])&&(s[i] < '7'))
        {
            res = n_2 + n_1;
        }
        else
        {
            res = n_1;
        }
        
        n_2 = n_1;
        n_1 = res;
    }

    return res;
}
```