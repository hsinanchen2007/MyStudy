### 解题思路
通过n除以3的商和余数判断。

### 代码

```python3
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        
        num = n

        if num == 1:
            return True
        num2 = num%3
        num= num//3

        
        while num:
            if num2 != 0:
                return False
            if num == 1:
                return True
            num2 = num%3
            num = num//3
            
```