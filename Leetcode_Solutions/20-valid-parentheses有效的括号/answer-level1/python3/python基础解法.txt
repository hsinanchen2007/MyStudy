### 解题思路
1. “（）”，“[]”, "{}"直接替换掉，通过循环判断是否为空，为空则True，非空则为False
2. 利用栈来解决的方法，后续补充

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        while len(s) != None:
            a = len(s)
            s = s.replace("[]", "")
            s = s.replace("()", "")
            s = s.replace("{}", "")
            if len(s) == 0:
                return True
            if len(s) == a:
                return False
            else:
                a = len(s)
```