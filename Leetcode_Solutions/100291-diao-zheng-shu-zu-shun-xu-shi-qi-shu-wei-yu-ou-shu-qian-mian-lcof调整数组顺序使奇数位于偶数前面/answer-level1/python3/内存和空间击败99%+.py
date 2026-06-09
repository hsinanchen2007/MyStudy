![图片.png](https://pic.leetcode-cn.com/6aba8081e982080beb6658853b9cd81388f128484c09910f814d6dcbb0acbac6-%E5%9B%BE%E7%89%87.png)
```python
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        # 双指针法, 时间复杂度O(n),sapce:O(1)
        n = len(nums)
        i,j = 0, n-1
        while i<j:
            while i< n and nums[i]%2 != 0:
                i += 1
            while j > 0 and nums[j]%2 == 0:
                j -= 1
            if i < j:
                nums[i],nums[j] = nums[j], nums[i]
        return nums
```