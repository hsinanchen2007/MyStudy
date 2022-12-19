### 解题思路
从后往前看。
（1）如果当前为是0，那么结果是0，因为不可能以0开头decode
（2）else，可以用当前位decode的字母和剩下的字符串组成decode的结果，所以dp[i] = dp[i + 1]
（3）如果当前位和后一位对应的整数在26以内，那么可以用当前位和后一位decode的字母和剩下的字符串组成decode的结果，所以 dp[i] += dp[i + 2]

最后返回dp[0]，也就是从第一个字母开始，decode的总数。

### 代码

```python
class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        dp = [0] * (len(s) + 1)
        dp[-1] = 1
        dp[-2] = 1 if s[-1] != "0" else 0
        for i in range(len(s) - 2, -1, -1):
            if s[i] == "0":
                dp[i] = 0
            else:
                dp[i] = dp[i + 1]
                if int(s[i:i + 2]) <= 26:
                    dp[i] += dp[i + 2]

        return dp[0]
```