# 方法一：动态规划，题解看官方吧
```
class Solution:  # 动态规划
    def longestValidParentheses(self, s: str) -> int:
        array = [0 for _ in s]  # 初始化数组
        for i in range(1, len(s)):
            if s[i] == ')' and s[i-1] == '(':
                array[i] = i-2 >= 0 and 2+array[i-2] or 2
            elif s[i] == ')' and s[i-1] == ')':
                if i-array[i-1]-1 >= 0 and s[i-array[i-1]-1] == '(':
                    array[i] = i-array[i-1]-2 >= 0 and array[i-1]+array[i-array[i-1]-2]+2 or array[i-1]+2
            else:
                continue
        return len(array) > 0 and max(array) or 0
```

# 方法二：栈
```
class Solution:  # 栈
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]
        max_len = 0
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                stack.pop()
                if not stack:  # 空栈
                    stack.append(i)
                else:
                    max_len = max(max_len, i - stack[-1])
        return max_len
```


