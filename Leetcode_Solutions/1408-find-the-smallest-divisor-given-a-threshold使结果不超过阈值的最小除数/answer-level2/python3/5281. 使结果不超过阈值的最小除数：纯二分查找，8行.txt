###解题思路

边查边算，应该没有多余的代码了，时间复杂度$O(Nlog(maxNums))$。

###代码

```python []
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        l, r = 1, max(nums)
        while l < r:
            m = (l + r) // 2
            if sum(map(lambda x: math.ceil(x / m), nums)) <= threshold:
                r = m
            else:
                l = m + 1
        return r
```
![image.png](https://pic.leetcode-cn.com/5a82d268408d8a857baefdebb80b26fa290f1974c35e2e6b8641b5d00b766244-image.png)
