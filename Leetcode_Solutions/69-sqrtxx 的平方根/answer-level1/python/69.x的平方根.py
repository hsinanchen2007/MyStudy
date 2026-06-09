### 解题思路
- 在区间(1,x/2)之间，使用二分查找的方法确定x的平方根
- 设置一个小值left,大值right，计算中间值mid，检查mid的平方与x的关系
- 然后不断缩小区间，直到left > right结束
### 代码

```python
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x==0 or x==1:
            return x

        left,right = 2, x//2
        while left<=right:
            mid = left + (right-left)//2
            if mid < x/mid:
                left = mid + 1
            elif mid > x/mid:
                right = mid - 1
            else:
                return mid
        return right
```