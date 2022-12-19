```
def numDecoding(s):
    """动态规划解决此题，本来不难，要考虑到很多0的时候不能解码的情况，错误了很多次"""
    if int(s[0]) == 0:   #第一个数是0的情况不能解码
        return 0
    n = len(s)
    if n <= 1:
        return 1
    
    #排除连续两个0的情况，以及0前面的数是大于2的情况，都不能解码
    for i in range(1, n):
        if (int(s[i]) == 0 and int(s[i - 1]) == 0) or (int(s[i]) == 0 and int(s[i - 1]) > 2):
            return 0
    
    #动态规划，dp过程
    dp = [0] * (n + 1)
    dp[0], dp[1] = 1, 1
    for i in range(2, n + 1):
        
        #考虑当可以分为两步到达时，即i-1为1时，i要大于0；i为2时，i必须大于0小于7
        if (int(s[i - 2]) == 1 and 0 < int(s[i - 1])) or (int(s[i - 2]) == 2 and 0 < int(s[i - 1]) <= 6):
            dp[i] = dp[i - 2] + dp[i - 1]
            
        #考虑最后一是0的情况，就只有从i-2处上来
        elif int(s[i - 1]) == 0:
            dp[i] = dp[i - 2]
        
        #其他情况即i-1>3时只能从i-1处上来
        else:
            dp[i] = dp[i - 1]
    return dp[-1]
```
