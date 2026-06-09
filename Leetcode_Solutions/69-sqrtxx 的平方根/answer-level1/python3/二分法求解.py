### 解题思路
代码中已注释

### 代码

```python
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        # 二分查找
        if x<=1:
            return x
        # 记录区间的首尾
        l,h=1,x
        while l<=h:
            mid = l+(h-l)/2
            sqrt=x/mid
            # sqrt=mid即开方
            if sqrt==mid:
                return mid
            elif mid>sqrt:
                h=mid-1
            else:
                l=mid+1
        return h
```