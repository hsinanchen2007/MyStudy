解题思路：如果一个数是2的n次幂，那么用2不断的去除这个数直到该数变为1都不会出现余数，反之则一定会出现余数。
```
class Solution:
    def isPowerOfTwo(self, n) -> bool:
        if n==0:
            return False
        if n==1:
            return True
        while(n!=1):
            temp = n % 2
            n = n//2
            if temp!=0:
                return False
        return True
```
