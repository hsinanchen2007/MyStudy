### 解题思路
利用**栈**

### 代码

```python
class Solution(object):
    def balancedStringSplit(self, s):
        dic = {'R':'L','L':'R'}
        stack = []
        count = 0
        for c in s:
            if not stack:
                stack.append(c)
            else:
                if c == dic[stack[-1]]:
                    stack.pop()
                    if not stack:
                        count += 1
                else:
                    stack.append(c)
        return count        
```