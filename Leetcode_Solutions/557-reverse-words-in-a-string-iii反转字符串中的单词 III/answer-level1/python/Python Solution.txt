### 解题思路
using stack, LIFO: last-in first-out
### 代码

```python
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s=s+" "
        stack,res=[],""
        for word in s:
            stack.append(word)
            if word == " ":
                while stack:
                    res += stack.pop()
        return res[1:]
```