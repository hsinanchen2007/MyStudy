### 解题思路
不建议此方法

### 代码

```python3
class Solution:
    def isNumber(self, s: str) -> bool:
        try:
            n = float(s)
            return True
        except:return False
```