这一题跟[爱吃香蕉的珂珂 (leetcode #875)](https://leetcode-cn.com/problems/koko-eating-bananas/)的做法是完全一样的。
考虑到：当$k$为正整数时，函数$f(k) = -\sum_{i=0}^{n-1} \lceil nums[i]/k \rceil$单调非减，且在$k = \max(nums)$时，函数值趋于饱和。
所以，可以在区间$[1, \max(nums)]$上进行二分查找。
当然，在下面的代码中，`sum`是可以展开优化的，但是实际测试发现，优化的作用不大。

```python
import math

class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        left, right = 1, max(nums)
        while left < right:
            mid = left + ((right - left) >> 1)
            if sum(math.ceil(num / mid) for num in nums) > threshold:
                left = mid + 1
            else:
                right = mid
        return left
```
时间复杂度：$O(len(nums) \max(nums))$，空间复杂度：$O(1)$。
具体运行时间最快可以到`508 ms`。
![image.png](https://pic.leetcode-cn.com/8061090f2c5524a2488e6f9fd7acaa789c5f71e12f9bf0c6a4900c68d53d37d3-image.png)

