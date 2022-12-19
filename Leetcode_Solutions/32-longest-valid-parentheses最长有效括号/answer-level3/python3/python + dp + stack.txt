```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = []
        if len(s) < 2: return 0
        dp = [0] * len(s)
        for i, ch in enumerate(s):
            if ch == ')':
                if stack and stack[-1][0] == '(':
                    _, index = stack.pop()
                    dp[i] = max(dp[i], dp[index - 1] + 2 + dp[i - 1])
            else: stack.append(('(', i))
        return max(dp)
```