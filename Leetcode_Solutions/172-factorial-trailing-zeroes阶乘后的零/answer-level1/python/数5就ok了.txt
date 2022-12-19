### 解题思路
因为每两个数就会有一个2的倍数，而每5个数才会有一个5的倍数，所以对于阶乘来说，不需要考虑2不够用。所以只需要看小于n的数里有多少5的倍数，有多少5**k的倍数 就ok了

### 代码

```python3
class Solution:
    def trailingZeroes(self, n: int) -> int:
        res=0
        
        while n/5>0:
            res+=int(n/5)
            n=n/5
        return res
```