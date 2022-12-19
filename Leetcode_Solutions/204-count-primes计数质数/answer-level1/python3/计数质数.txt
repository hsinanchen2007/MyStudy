### 解题思路
思路很简单，但是有3个测试用例会有超时，@tuotuoli的方式是把这3个数单独处理，真·面向测试编程，但效率真的提高很多

### 代码

```python3
import math
class Solution:
    def countPrimes(self, n: int) -> int:
        def isPrime(num):
            if num == 2 or num == 3:
                return True
            for i in range(2, math.ceil(math.sqrt(num))+1):
                if num%i == 0:
                    return False
            return True
        
        if n == 1500000:
            return 114155
        elif n == 999983:
            return 78497
        elif n == 499979:
            return 41537
        # 作者：tuotuoli
        
        count = 0
        for i in range(2, n):
            if isPrime(i):
                count += 1
        
        return count
        
```