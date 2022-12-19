### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isNumber(self, s: str) -> bool:
        try:
            float(s)
            return True
        except:
            return False
```