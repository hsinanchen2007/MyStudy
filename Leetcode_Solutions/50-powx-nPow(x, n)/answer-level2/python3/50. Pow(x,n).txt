### 解题思路
这道题考察的是快速幂算法，也就是二分法（分治策略）。明白了这一点，代码就很容易实现，下面是带备忘录的递归代码，关键在于区分n的正负与奇偶。时间复杂度和空间复杂度都为O(logN)。

### 代码

```python3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        def fastPow(n):
            if n not in memo:
                if n%2==0:
                    memo[n] = fastPow(n/2)*fastPow(n/2)
                else:
                    memo[n] = x*fastPow((n-1)/2)*fastPow((n-1)/2)
            return memo[n]
        
        if n<0:
            x=1/x
            n=-n
        memo = {0:1,1:x}
        print(memo)
        return fastPow(n)
```