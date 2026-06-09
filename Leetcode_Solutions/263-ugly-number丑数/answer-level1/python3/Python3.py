### 解题思路
除掉所有因子后等于1

### 代码

```python3
class Solution:
    def isUgly(self, num: int) -> bool:
        if not num:return False # positive number
        for factor in [2,3,5]:
            while num%factor == 0: # divide all factor
                num /= factor
        return num == 1 # non other factor left
```