### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isUgly(self, num: int) -> bool:
        if num == 0:
            return False
        if num in [1, 2, 3, 5]:
            return True
        else:
            if num % 2 == 0:
                return self.isUgly(num // 2)
            elif num % 3 == 0:
                return self.isUgly(num // 3)
            elif num % 5 == 0:
                return self.isUgly(num // 5)
            else:
                return False
        
```