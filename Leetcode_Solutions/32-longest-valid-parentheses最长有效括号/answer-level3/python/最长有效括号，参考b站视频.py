### 解题思路
第一次写动态规划问题，参考了[b站视频讲解](https://www.bilibili.com/video/av74192978?from=search&seid=15722910652935937860) ，讲得很清楚。

### 代码

```python3
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        N = len(s)
        dp = [0] * (N + 1)
        stack = []
        for i, c in enumerate(s):
            if c == '(':
                stack.append(c)
            else:
                index = i + 1
                if stack:
                    stack.pop()
                    pairs = 1 + dp[index - 1]
                    pre_index = index - 2*pairs
                    if dp[pre_index] > 0:
                        pairs += dp[pre_index]
                    dp[index] = pairs
        return max(dp) * 2

```