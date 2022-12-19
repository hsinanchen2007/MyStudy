### 解题思路
最长回文子串
s为所求字符串
定义dp数组存放回文长度，sub_s回文字符串，dp[i]代表回文长度，s[i-dp[i]+1:i+1]为回文字串(当前坐标包含当前坐标，回退dp[i]位)。下标从零开始，左开右闭。
例如baba,则dp[2] = 3,sub_s = bab  --(s[2-3+1:3+1])
对于任意回文串A，xAx也为回文串。
因此我们所求，有两种情况
1，s[i] == s[i-dp[i-1] + 1],那么dp[i] = dp[i-1] + 2
2，s[i] != s[i-dp[i-1] + 1],那么寻找dp[i-1]对应的回文字串中结合s[i]，是否存在回文串。
   s[i:k] == s[k:i],i-dp[i-1] < k < i。从左到右，第一个就是最大回文串。dp[i] = i - k + 1

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        str_size = len(s)
        dp = [1] * str_size  #初始化为1
        for i in range(1,str_size):
            lens = dp[i-1]
            if i - lens - 1 >= 0 and s[i - lens - 1] == s[i]:
                dp[i] = lens + 2
            else:
                for j in range(i-lens, i):
                    if s[i] == s[j] and s[j:i+1][::-1] == s[j:i+1]:
                        dp[i] = i-j + 1
                        break
        index = dp.index(max(dp))
        return s[index-dp[index]+1:index+1]
```