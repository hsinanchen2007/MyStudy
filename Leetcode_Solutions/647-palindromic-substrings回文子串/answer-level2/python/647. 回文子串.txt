### 解题思路
解题思路：马拉车算法
第一步：在字符串两端和各字母中间插入'#'，在不影响字符串回文特性的情况下，将字符串统一为奇数长度
第二步：定义dp[i]记录字符串i位置的最大回文半径
第三步：马拉车计算每个位置的最大回文半径
第四步：计算回文子串总数（如果字符是'#'并且回文半径为1，那么跳过不计算；其他情况res += dp[i] // 2）
### 代码

```python
class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        res = 0
        if s:
            str = list('#' + '#'.join(list(s)) + '#')
            # 记录各位置的回文半径
            dp = [1 for i in range(len(str))]
            # 已探明的最右边界
            mx = 0
            # 能到达最右边界的回文串的中心
            flag = 1

            for i in range(1, len(str)):
                if mx > i:
                    dp[i] = min(mx - i, dp[2 * flag - i])

                while i - dp[i] >= 0 and i + dp[i] < len(str) and str[i - dp[i]] == str[i + dp[i]]:
                    dp[i] += 1

                if str[i] != '#' or dp[i] > 1:
                    res += dp[i] // 2

        return res
```