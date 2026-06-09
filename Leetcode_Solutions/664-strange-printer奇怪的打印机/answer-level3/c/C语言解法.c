### 解题思路
先把第一个字符打印了，后边的字符要么和第前边某个字符一起打印，要么单独打印；
如果和前边的字符一起打印，后边的字符不占用打印次数，但是源字符串被拆分成两段

### 代码

```c

int calc_iter(char * s, int start, int end, int dp[100][100])
{
    int ret = 0;
    int res = 0;
    int i = 0;
    
    if (start > end)
    {
        return 0;
    }
    
    if (dp[start][end] > 0)
    {
        return dp[start][end];
    }
    
    ret = 1 + calc_iter(s, start+1, end, dp);
    for (i = start+1; i <= end; i++)
    {
        if (s[i] == s[start])
        {
            res = calc_iter(s, start, i-1, dp) + calc_iter(s, i+1, end, dp);
            if (res < ret)
            {
                ret = res;
            }
        }
    }
    
    dp[start][end] = ret;
    
    return ret;
}

int strangePrinter(char * s){
    int ret = 0;
    int dp[100][100] = {0};
    int len = strlen(s);
    
    ret = calc_iter(s, 0, len-1, dp);
    
    return ret;
}


```