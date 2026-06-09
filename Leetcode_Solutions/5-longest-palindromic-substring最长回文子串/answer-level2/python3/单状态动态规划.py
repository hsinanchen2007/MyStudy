### 解题思路
此处撰写解题思路
单状态动态规划，dp[i]表示以s[i]元素结尾的所有回文串，并且时刻更新res记录最长长度。
### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s)==0 or len(s)==1:return s


        dp=[[0,1] for i in range(len(s))]
        res=1
        for i in range(1,len(s)):
            for x in dp[i-1]:
                if i-x-1>=0 and s[i]==s[i-x-1]:
                    if x+2>res:res=x+2
                    dp[i].append(x+2)
        for index in range(len(s)):
            if res in dp[index]:
                return s[index-res+1:index+1]
```