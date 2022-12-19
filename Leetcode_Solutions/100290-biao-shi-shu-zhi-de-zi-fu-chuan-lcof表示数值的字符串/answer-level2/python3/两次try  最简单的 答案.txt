### 解题思路
尝试能否转换为数字 不行就不行-- 

### 代码

```python3
class Solution:
    def isNumber(self, s: str) -> bool:
        xl=0
        try:
            float(s) 
            xl=1
        except:
            pass
        try:
            int(s) 
            xl=1
        except:
            pass
        return bool(xl)
```