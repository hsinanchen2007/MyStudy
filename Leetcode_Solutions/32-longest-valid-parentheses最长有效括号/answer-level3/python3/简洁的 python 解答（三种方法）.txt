[原文](https://codeplot.top/2019/10/09/leetcode-%E5%8A%9B%E6%89%A3-32-%E6%9C%80%E9%95%BF%E6%9C%89%E6%95%88%E6%8B%AC%E5%8F%B7-python/)

# 两次遍历
```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        def fun(s, t):
            left = 0
            right = 0
            max_length = 0
            for ch in s:
                if ch == t: left += 1
                else: right += 1
                if left == right: max_length = max(max_length, left<<1)
                elif right > left:
                    left = 0
                    right = 0
            return max_length
        return max(fun(s, '('), fun(s[::-1], ')'))
```

# DP

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        dp = [0] * len(s)
        ans = 0
        for i in range(1, len(s)):
            if s[i] == ')':
                if s[i-1] == '(':
                    dp[i] = (dp[i-2] if i - 2 > 0 else 0) + 2
                    ans = max(ans, dp[i])
                else:
                    j = i - dp[i-1] - 1
                    
                    if j >= 0 and s[j] == '(':
                        dp[i] = dp[i-1] + 2
                        if j - 1 >= 0: dp[i] += dp[j - 1]
                        ans = max(ans, dp[i])
        return ans
```

# 栈

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        l = [-1]
        max_length = 0
        cur = 0
        for i, ch in enumerate(s):
            if ch == '(':
                l.append(i)
            else:
                l.pop()
                if not l:
                    l.append(i)
                else:
                    max_length = max(max_length, i - l[-1])
        return max_length
```