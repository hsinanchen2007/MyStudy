### 解题思路
  使用栈得到合理的括号匹配 
  然后拼接就好  
  都有注释 简单易懂！

### 代码

```python3

class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        if not s:
            return ''
        if '(' not in s and ')' not in s:
            return s
        valids = []
        stack = []
        for i in range(len(s)):
            if s[i].isalpha():
                continue
            if s[i] == '(':
                stack.append(('(', i))
            elif s[i] == ')':
                if stack and stack[- 1][0] == '(':
                    # start = stack.pop()[1]
                    start = stack.pop()
                    end = i
                    valids.append(start[1])
                    valids.append(end)
        valids = set(valids)
        # print(valids)
        ans = []
        for i in range(len(s)):
            if s[i].isalpha():
                ans.append(s[i])
            elif i in valids:
                ans.append(s[i])
        return ''.join(ans)

```