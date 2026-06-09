![1362.jpg](https://pic.leetcode-cn.com/b1f35974f472de7b72bfbd49742608950e27c889fc12f0e672f59275f79d0e3a-1362.jpg)
```
from math import sqrt,floor

class Solution:
    def getDivisors(self,num):
        for i in range(floor(sqrt(num)),0,-1):
            if not num%i:
                return i,(k:=num//i)
    
    def closestDivisors(self, num: int) -> List[int]:
        p1,l1=self.getDivisors(num+1)
        p2,l2=self.getDivisors(num+2)
        return [p2,l2] if l1-p1>l2-p2 else [p1,l1]
```
思路：
先寻找两个因数中较小的那一个，因为较大那一个距离平方根比较小的那一个远（猜的，不敢保证正确性）。同时我们应该从sqrt往下查找，找到了就是最大的。