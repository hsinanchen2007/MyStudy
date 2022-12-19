### 解题思路
采用二分查找法求解：
首先考虑特殊值（开方等于自身的数0和1）；
其次考虑到b开方向下取整后得到的数a之间的关系肯定是a**2<=b<(a+1)**2；
最后根据这个关系列出代码即可。

### 代码

```python
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x==1 or x==0:
            return x
        l = 1
        r = x // 2
        while l<=r:
            mid = (l+r) // 2
            if x >= mid*mid and x < (mid+1)*(mid+1):
                return mid
            elif x < mid*mid:
                r = mid - 1
            elif x >= (mid+1)*(mid+1):
                l = mid +1
        return mid
```