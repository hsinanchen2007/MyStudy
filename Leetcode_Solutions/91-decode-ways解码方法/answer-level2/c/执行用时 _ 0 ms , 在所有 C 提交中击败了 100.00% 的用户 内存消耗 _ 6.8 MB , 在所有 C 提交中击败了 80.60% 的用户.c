### 解题思路
其实不太熟悉C，有什么特别傻的地方大家担待，其实跟爬楼梯那个差不多，只不过要处理的细节多一点
- 首位是0, 没有办法解码, 直接返回0
- 前一位是0
   - 目前也是0(连续两个0的), 没法解码, 返回0
   - 当前不是0, 一共dp[i-1]种方法, 即和前面方法一样, 因为没法组合,所以只能自己, 没有任何增加
- 前一位不是0
   1. 但当前是0, 只能组合所以dp[i-2]种
   2. 当前也不是0
      - 和前一位组合小于26, dp[i-2]+dp[i-1]
      - 大于26了, 只能不组合, dp[i-1]
最后返回就可以了....

### 代码

```c
int conver(char c)
{
    return c - '0';
}

int len(char *s)
{
    int n = 0;
    while (*s != '\0'){
        n++;
        s++;
    }
    return n;
}
int numDecodings(char *s)
{
    int n = len(s);
    if (n == 0) return 0;
    if (n == 1&&s[0]!='0'){
        return 1;
    }
    
    if (s[0] == '0')
    {
        return 0;
    }
    int dp[5000];
    dp[0] = 1;
    int i;

    if (s[1] == '0')
    {
        if (conver(s[0]) * 10 + conver(s[1]) <= 26)
            dp[1] = 1;
        else
        {
            return 0;
        }
    }
    else
    {
        if (conver(s[0]) * 10 + conver(s[1]) <= 26)
            dp[1] = 2;
        else
        {
            dp[1] = 1;
        }
    }
    if (n==2){
        return dp[1];
    }

    for (i = 2; s[i] != '\0'; i++)
    {
        if (s[i - 1] == '0')
        {
            if (s[i] == '0')
                return 0;
            else
                dp[i] = dp[i - 1];
        }
        // 前一位不等于0
        else
        {
            if (s[i] == '0')
            {
                if (conver(s[i - 1]) * 10 + conver(s[i]) <= 26)
                    dp[i] = dp[i - 2]; // 后两位结合
                else
                    return 0;
            }
            // 后一位也不是0
            else
            {
                if (conver(s[i - 1]) * 10 + conver(s[i]) <= 26)
                {
                    dp[i] = dp[i - 1] + dp[i - 2]; // dp[i-1]: dp[i]自己组合, dp[i-2]: dp[i-1]和dp[i] 组合
                }
                else
                { // 只能自己, 不能组合
                    dp[i] = dp[i - 1];
                }
            }
        }
    }
    return dp[i - 1];
}
```