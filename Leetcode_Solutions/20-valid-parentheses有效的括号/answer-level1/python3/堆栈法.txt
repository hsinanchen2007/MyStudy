### 解题思路
先判断是不是左边的直接输入，然后判断有没有匹配的,比较好理解

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        c = ['(','[','{']
        a = {")":"(","}":"{","]":"["}
        b = [0]
        for i in s:
            if i in c:
                b.append(i)
            elif a[i] == b[-1]:
                b.pop()
            else:
                b.append(i)
        return b == [0]
```