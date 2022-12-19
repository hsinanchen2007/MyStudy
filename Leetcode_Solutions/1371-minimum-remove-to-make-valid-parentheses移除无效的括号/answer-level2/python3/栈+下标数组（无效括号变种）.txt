### 解题思路
找到无效括号下标
用有效下标重新组成字符串

### 代码

```python3
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []
        s_l = len(s)
        invalid_index = [False for i in range(s_l)]
        for i in range(s_l):
            if s[i] == '(':
                stack.append(i)
                invalid_index[i] = True
            if s[i] == ')':
                if stack == []:
                    invalid_index[i] = True
                else:
                    invalid_index[stack.pop()] = False
        res = ''
        for i in range(len(s)):
            if invalid_index[i] == False:
                res += s[i]
        return res
```