### 解题思路
换装替代法的JAVA版可在官方题解中发现，此为Python简化版

### 代码

```python
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        # 环装替代法
        n = len(nums)
        start = 0
        
        i = start
        for _ in range(n - 1):
            i = (i + k) % n

            # 如果回到了数组头部，重新设置，直接进入下一轮循环
            if i == start:
                start += 1
                i = start
                continue

            nums[start], nums[i] = nums[i], nums[start]
        
```