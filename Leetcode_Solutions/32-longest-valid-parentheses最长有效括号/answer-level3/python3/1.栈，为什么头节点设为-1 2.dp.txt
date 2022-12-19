### 1
为什么头节点设为-1，因为是为了后面弹出的括号能与前面连续括号接上去

比如

    `()()`
    stack = [-1,1]
    maxlength = 1-(-1) = 2
    stack = [-1]
    stack = [-1,2]
    maxlength = 3-(-1) = 4

如果当前字符为 ")" 没有匹配的上的,那么后面的括号就不可能再接上前面的连续括号，则重新设置起始节点

    `())()`
    maxlen = 1-(-1) = 2
    stack = [-1]
    stack = []
    stack = [2] # 重新设置起始点
    stack = [2,3]
    maxlen = 4 - 2 = 2
    stack = [2]

这才是这道题用栈的精髓

### 代码

```python3

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]
        max_count = 0
        for i,c in enumerate(s):
            if c == '(':
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    # 不可能与之前的接上，重新设置起点
                    stack.append(i)
                else:
                    # 可能与开头接上
                    max_count = max(max_count,i-stack[-1])
        return max_count
```

### 2
状态定义：
    dp[i] 以 i 结尾的最长有小括号

状态初始化：
    s[i] == '(' -> dp[i] = 0

状态转移：
    1. dp[i] = dp[i-2]+()
    2. dp[i] = dp[i-1-dp[i-1]-1]+(+dp[i-1]+)

### 代码
```python3

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        sub_pair = n//2
        max_len = 0
        for sp in range(1,sub_pair+1):
            for i in range(0,n-sp*2+1):
                stack = []
                flag = True
                for c in s[i:i+sp*2]:
                    if c == '(':
                        stack.append(c)
                    else:
                        if stack and stack.pop() == '(':
                            continue
                        else:
                            flag = False
                flag = flag and not stack
                if flag == True: max_len = max(max_len,sp*2)
        return max_len
```