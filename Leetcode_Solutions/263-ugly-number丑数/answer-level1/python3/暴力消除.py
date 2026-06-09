### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isUgly(self, num: int) -> bool:
        if num <= 0:
            return False
        while num >= 2:
            if num%2 == 0:
                num = num/2
            elif num % 3 == 0:
                num = num/3
            elif num % 5 == 0:
                num = num/5
            else: 
                return False
        return True
```