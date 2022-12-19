### 解题思路
首先考虑一般情况，每一个字符s[i]可以和前一个字符**共同译码**，也可以**单独译码**，如果选择共同译码，相当于s[i - 1]和s[i]的组合方式已经固定，那么s[:i - 1]有多少种组合方式那么共同译码就有多少种组合方式，如果选择分开译码，那就相当于只有最后一个字符已经固定，那么s[:i]有多少种组合方式共同译码就有多少种组合方式。在题目中还要考虑'0'的情况。

### 代码

```python
class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s[0] == '0':
            return 0
        length = len(s)
        dp = [1] * length
        for i in range(1, length):
            tmp = int(s[i - 1:i + 1])
            if tmp > 26 and tmp % 10 == 0 or tmp == 0:
                return 0
            elif tmp <= 26 and s[i - 1] != '0' and s[i] != '0':
                dp[i] = dp[i - 1] + dp[i - 2] # 对应s[i]和s[j]分开译码和共同译码
            elif s[i - 1] == '0' or tmp > 26: 
                dp[i] = dp[i - 1] # 只能单独译码
            else: # s[i] == 0
                dp[i] = dp[i - 2] # 只能共同译码，因为初始化为1，所以就算i == 1也能赋值为1
            
        # print(dp)
        return dp[-1]
```