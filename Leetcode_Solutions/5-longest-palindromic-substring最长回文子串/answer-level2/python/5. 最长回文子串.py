### 解题思路
解题思路：马拉车算法
第一步：在字符串两端和各字母中间插入'#'，在不影响字符串回文特性的情况下，将字符串统一为奇数长度
第二步：定义dp[i]记录字符串i位置的最大回文半径
第三步：马拉车计算每个位置的最大回文半径
第四步：根据pos记录的回文半径最大的位置生成最长回文子串（这种方式比每次比较回文子串长度更优）
### 代码

```python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = ''
        if s:
            str = '#' + '#'.join(list(s)) + '#'
            dp = [1 for i in range(len(str))]
            mx = 0
            flag = 1
            pos = 0

            for i in range(1, len(str)):
                if mx > i:
                    dp[i] = min(mx - i, dp[2 * flag - i])

                while 0 <= i - dp[i] and i + dp[i] < len(str) and str[i - dp[i]] == str[i + dp[i]]:
                    dp[i] += 1

                if i + dp[i] > mx:
                    mx = i + dp[i]
                    flag = i

                if dp[i] > dp[pos]:
                    pos = i

            for k in str[pos - dp[pos] + 1: pos + dp[pos]]:
                if k != '#':
                    res += k

        return res
```