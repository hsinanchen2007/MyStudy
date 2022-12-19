思路：利用递归寻找

代码：
```
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        
        num = n

        if num == 1:
            return True
        num2 = num % 2
        num= num // 2

        
        while num:
            if num2 != 0:
                return False
            if num == 1:
                return True
            num2 = num % 2
            num = num // 2
```
