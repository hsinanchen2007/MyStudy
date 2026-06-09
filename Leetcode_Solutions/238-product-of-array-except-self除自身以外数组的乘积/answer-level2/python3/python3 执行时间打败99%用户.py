### 解题思路
思路和官方解题方法二一样，但是写法有些细微区别，时间更快了些
空间复杂度O(1)

### 代码

```python3
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        if not nums: return nums
        ans = [1 for _ in range(len(nums))]
        for i in range(len(nums)-1):
            ans[i+1] = ans[i] * nums[i]
        
        R = 1
        for i in reversed(range(len(nums))):
            ans[i] = ans[i] * R
            R *= nums[i]
        return ans
```