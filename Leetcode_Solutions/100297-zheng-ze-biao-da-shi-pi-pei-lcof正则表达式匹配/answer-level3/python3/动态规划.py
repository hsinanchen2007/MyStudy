### 解题思路
我觉得与[@loick](/u/loick/)同学的思路差不多，不过写的不大一样，所以也不算是原创，也不保证效率，就是用例通过了。写一下自我感动。
二维数组dp[i][j]：第i个p与第j个s是否能匹配：是，则True，否，这False
初始化这个dp为False
dp[0][0]表示开始匹配，赋值True。
第一行和第三行说明，dp的规模要比p和s的大一位。
最后是否匹配，看dp[len(p)][len(s)]

整体思路是遍历p中每一个字符（下标i），然后针对这个字符遍历s，给dp[i][?]赋值。

从第一位p开始遍历p的字符：【dp下标与s和p的下标不同】
p[i-1]为字符：dp[i][j] = dp[i - 1][j - 1] and s[j - 1] == p[i - 1]
p[i-1]为'.'：dp[i][j] = dp[i - 1][j - 1]
p[i-1]为'\*'：两种情况：
            1）忽略前一位：dp[i - 2][j]
            2）要前一位：dp[i][j - 1] and p[i - 2] in [s[j - 1], '.]（要前一位的前提是，前一位p[i - 2]能对上s的当前位）
            这里有一种特殊情况，即dp[i][0]，表示用空串对应p[i - 1]，这样就只有*且忽略前一位可做到。

### 代码

```python
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if s == p:
            return True
        len_s = len(s)
        len_p = len(p)
        
        
        dp = [[False] * (len_s + 1) for _ in range(len_p + 1)]

        dp[0][0] = True
        for i in range(1, len_p + 1):
            if p[i - 1] not in ['.', '*']:
                for j in range(1, len_s + 1):
                    dp[i][j] = dp[i - 1][j - 1] and s[j - 1] == p[i - 1]

            elif p[i - 1] == '.':
                for j in range(1, len_s + 1):
                    dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][0] = dp[i - 2][0]
                for j in range(1, len_s + 1):
                    dp[i][j] = dp[i - 2][j] or dp[i][j - 1] and p[i - 2] in [s[j - 1], '.']

        return dp[len_p][len_s]
```