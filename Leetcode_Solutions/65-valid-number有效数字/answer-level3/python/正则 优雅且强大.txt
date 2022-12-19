### 解题思路
此处撰写解题思路
?: (0,1)
+：[1:]
*: [0:]
### 代码

```python3
class Solution:
    def isNumber(self, s: str) -> bool:
        res= re.match(" *[+-]?(\d+(\.\d*)?|\.\d+)(e[+-]?\d+)? *$",s)
        return bool(res)
```