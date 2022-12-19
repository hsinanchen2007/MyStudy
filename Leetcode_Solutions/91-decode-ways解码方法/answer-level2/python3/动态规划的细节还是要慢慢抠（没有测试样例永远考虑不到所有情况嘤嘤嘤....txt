### 解题思路
动态规划的转移方程可以想到，但是需要注意细节，比如字符串长度为1，单个字符为0的情况
最重要的就是初始化前两个状态必须要正确！
![捕获.PNG](https://pic.leetcode-cn.com/725a4403f040db9ec8bb0ba731ab73eb4edc706200fbd4701dc498c570b8c340-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```python3
class Solution:
    # 只包含数字，所以要考虑0的情况
    # 第i位的编码方法数 = 该位单独编码时的方法总数+该位与前一位一起编码时的方法总数
    # dp[i] = dp[i-1] + dp[i-2]
    def numDecodings(self, s: str) -> int:
        t = len(s)
        dp = [0]*t

        if s[0] != '0':
            dp[0] = 1
        
        if t == 1:
            return dp[0]
        # 单独编码
        if s[1] != '0':
            dp[1] += dp[0]
        # 判断是否可以合起来编码
        if s[0] == '1' or s[0] == '2' and s[1] <= '6':
            dp[1] += 1

        for i in range(2,t):
            # 该位可以单独编码
            if s[i] != '0':
                dp[i] += dp[i-1]
            # 该位与前一位合在一起可以解码
            if s[i-1] == '1' or s[i-1] =='2' and s[i] <= '6':
                dp[i] += dp[i-2]
        return dp[-1]
```