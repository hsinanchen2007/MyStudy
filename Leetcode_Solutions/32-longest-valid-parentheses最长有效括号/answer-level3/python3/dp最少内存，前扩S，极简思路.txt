### 解题思路
此处撰写解题思路
主要也是dp，就是如果是（）就是dp[i-1]的加上2；
如果是））就看前面有没有对应的（，如果有，就是dp[i-1]+2+dp[i-2-dp[i-1]],
如果光是这样的话，会有问题，因为可能是-1，然后就索引到dp的队尾了，所以我们在整个s的前面加一个空元素，‘ ’。
solved
### 代码

```python3
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        if len(s)<2:
            return 0
        s = ' '+s
        dp = [0 for i in s]
        n = len(s)
        for i in range(1,n):
            if s[i-1:i+1]=='()':
                dp[i] = dp[i-2]+2
            if s[i-1:i+1]=='))':
                if s[i-1-dp[i-1]]=='(':
                    dp[i]=dp[i-1]+2+dp[i-2-dp[i-1]]
                else:
                    dp[i]=0
        return max(dp)
        
```