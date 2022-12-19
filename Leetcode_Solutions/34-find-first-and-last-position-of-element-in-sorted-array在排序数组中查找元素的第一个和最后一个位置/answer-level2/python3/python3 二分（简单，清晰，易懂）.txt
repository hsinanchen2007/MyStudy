### 解题思路

![截屏2020-03-04下午9.49.06.png](https://pic.leetcode-cn.com/db40075e78d7749ae6fc08ab0d002fd039c127246e5dab6bf6af6bf14bace3b2-%E6%88%AA%E5%B1%8F2020-03-04%E4%B8%8B%E5%8D%889.49.06.png)

### 代码

```python []
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums: return [-1, -1]
        # 确定左边界
        left, right = 0, len(nums)-1
        while left + 1 < right:
            mid = (left + right) >> 1
            if nums[mid] >= target: 
                right = mid 
            else: 
                left = mid 
        if nums[left] == target:    lbound = left
        elif nums[right] == target: lbound = right
        else: return [-1, -1]
        # 确定右边界
        left, right = 0, len(nums)-1
        while left + 1 < right:
            mid = (left + right) >> 1
            if nums[mid] <= target: 
                left = mid
            else: 
                right = mid 
        if nums[right] == target:  rbound = right
        elif nums[left] == target: rbound = left
        else: return [-1,-1]

        return [lbound, rbound]

```