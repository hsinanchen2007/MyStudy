### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        low=0
        high=len(nums)-1
        if target<nums[0]:
            return 0
        while low<=high:
            mid=(low+high)//2
            if nums[mid]<target:
                low=mid+1
            else:
                high=mid-1
        return low

```