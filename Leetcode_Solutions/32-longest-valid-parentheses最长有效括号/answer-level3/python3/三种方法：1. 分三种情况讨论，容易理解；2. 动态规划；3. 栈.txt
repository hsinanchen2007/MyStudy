方法一
将情况分为三种：
1. s正好是有效括号字符串，直接返回s的长度；
2. s除去有效括号之后，以')'结尾，把这种情况做成函数；
3. s除去有效括号之后，以'('结尾，这时以s中的'('作为分段点，分段调用上面做好的函数。
```
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        # 函数
        def fun(s):
            if not s:
                return [0]
            res = []
            ans = 0
            stack = [s[0]]
            left, right = 0, 0
            if s[0] == '(':
                left += 1
            else:
                right += 1
            for k in range(1, len(s)):
                if right > left:
                    res.append(ans)
                    ans = 0
                    left = 0
                    right = 0
                if stack and stack[-1] == '(' and s[k] == ')':
                    stack.pop()
                    left -= 1
                    ans += 2
                else:
                    stack.append(s[k])
                    if s[k] == '(':
                        left += 1
                    else:
                        right += 1
            res.append(ans)
            return res

        if not s:
            return 0

        # 除去有效括号，并记录剩余括号的索引（用于后续可能的分段）
        TmpStack = [s[0]]
        inds = [0]
        for k in range(1, len(s)):
            if TmpStack and TmpStack[-1] == '(' and s[k] == ')':
                TmpStack.pop()
                inds.pop()
            else:
                TmpStack.append(s[k])
                inds.append(k)
        
        # 第一种情况
        if not TmpStack:
            return len(s)

        # 第二种情况
        elif TmpStack[-1] == ')':
            return max(fun(s))

        # 第三种情况
        else:
            res = []
            res.append(max(fun(s[:inds[0]])))
            for i in range(1, len(inds)):
                res.append(max(fun(s[inds[i-1]+1:inds[i]])))
            res.append(max(fun(s[inds[-1]:])))
            return max(res)
```

方法二
动态规划
官方题解的动态规划的Python3版本
```
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        maxans = 0
        dp = [0] * len(s)
        for k in range(1, len(s)):
            if s[k] == ')':
                if s[k-1] == '(':
                    if k-2 >= 0:
                        dp[k] = dp[k-2] + 2
                    else:
                        dp[k] = 0 + 2
                elif k-dp[k-1]-1 >= 0 and s[k-dp[k-1]-1] == '(':
                    if k-dp[k-1]-2 >= 0:
                        dp[k] = dp[k-1] + dp[k-dp[k-1]-2] + 2
                    else:
                        dp[k] = dp[k-1] + 0 + 2
                maxans = max(maxans, dp[k])
        return maxans
```

方法三
栈
官方题解的栈的Python3版本
```
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        maxans = 0
        stack = [-1]
        for k in range(len(s)):
            if s[k] == '(':
                stack.append(k)
            else:
                stack.pop()
                if stack:
                    maxans = max(maxans, k - stack[-1])
                else:
                    stack.append(k)
        return maxans
```
