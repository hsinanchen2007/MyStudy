### 解题思路
本题要求对数时间复杂度，所以需要用二分法解。利用二分法分别寻找左右区间，利用标志left判断需要寻找的是左区间还是右区间。在寻找左区间时，在找到nums[mid]=target时，仍然将区间左移，令mid=high;在寻找右区间时，nums[mid]=target时或nums[mid]<target时仍然将区间右移。
二分法具体细节可以看我点赞的文章。
### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:    
        left_index = self.extreme_insertion_index(nums, target, left=True)
        if left_index==len(nums) or nums[left_index]!=target:
            return [-1, -1]
        return [left_index, self.extreme_insertion_index(nums, target, False)-1]

    def extreme_insertion_index(self, nums, target, left):
        low = 0
        high = len(nums)
        #终止条件low=high，这是一个左闭右开区间，当左右边界值相等时区间为空
        while low<high:
            mid = (low+high)//2
            if target<nums[mid] or (target==nums[mid] and left):
                high = mid
            else:
                low = mid + 1
        return low 
```