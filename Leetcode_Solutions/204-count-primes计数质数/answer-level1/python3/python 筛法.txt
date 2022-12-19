### 解题思路
筛法，每次从i*i开始，因为2到i-1已经全部筛过，所以不从i*2开始筛（2的倍数也被筛过）


### 代码

```python3
import math
class Solution:
    def countPrimes(self, n: int) -> int:

        if n<2:
            return 0
        isPrime=[1 for _ in range(n)]
        isPrime[0]= isPrime[1]=0
        for i in range(2,int(n**0.5)+1):
            if isPrime[i]:
                isPrime[i*i:n:i] = [0] * ((n-1-i**2)//i+1)
        return sum(isPrime)

      