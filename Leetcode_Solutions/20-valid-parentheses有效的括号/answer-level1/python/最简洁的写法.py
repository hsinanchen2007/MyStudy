### 解题思路
此处撰写解题思路
代码简洁，括号匹配使用map 存起来，用 右括号取左边的。


### 代码

```python
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        paren_map = { ')':'(',']':'[','}':'{' }
        for c in s:
            if c not in paren_map:
                stack.append(c)
            elif not stack or paren_map[c] != stack.pop():
                return False
        return not stack
```