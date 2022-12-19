### 解题思路
1.用一个dp数组来表示，s[j:i]是否为回文串
2.如果是回文串，判断长度
### 代码

```python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        max_len=1
        start=0
        dp=[[0 for _ in range(len(s))] for _ in range(len(s))]
        for i in range(len(s)):
            dp[i][i]=True
        for i in range(1,len(s)):
            for j in range(i):
                if s[i]==s[j]:
                    if i-j+1<=3:
                        dp[j][i]=True
                    else:
                        dp[j][i]=dp[j+1][i-1]
                if dp[j][i]==True:
                    if i-j+1>max_len:
                        max_len=i-j+1
                        start=j
        return s[start:start+max_len]

      

```