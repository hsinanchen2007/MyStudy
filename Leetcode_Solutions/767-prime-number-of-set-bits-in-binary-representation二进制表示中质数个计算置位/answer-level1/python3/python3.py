### 解题思路


### 代码

```python3
class Solution:
    def countPrimeSetBits(self, L: int, R: int) -> int:
        def count_one_in_bits(x):
            count = 0
            while x: # when has bit 1
                if x&0x1: # if last bit is 1
                    count += 1
                x >>= 1
            return count

        def isPrime(x):
            if x<=1:return False # greater than 1
            for i in range(2,x): # [2,x)
                if x%i == 0:
                    return False
            return True
        res = 0
        for x in range(L,R+1): # [L,R]
            if isPrime(count_one_in_bits(x)):
                res += 1
        return res
```