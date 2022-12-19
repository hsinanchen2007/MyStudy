![image.png](https://pic.leetcode-cn.com/ae9b4c6a153a339733f44feb103704d067b2ed351599bed162c8e3016ffb6c35-image.png)


```

'''
先从左到右把配对的括号找到，然后递归处理括号中的字符串，最后进行
拼接
'''

class Solution:

    def solve(self, s, start, end, m):
        i = start

        ans = ''
        while i <= end:
            if s[i] == '(':
                ans += self.solve(s, i+1, m[i]-1, m)[::-1]
                i = m[i]+1
            else:
                ans += s[i]
                i += 1
        return ans


    def reverseParentheses(self, s: str) -> str:
        stack = []
        m = {}
        for i, ch in enumerate(s):
            if ch == '(' or ch == ')':
                if ch == ')':
                    m[stack[-1]] = i
                    stack.pop(-1)
                else:
                    stack.append(i)

        return self.solve(s, 0, len(s)-1, m)
```
