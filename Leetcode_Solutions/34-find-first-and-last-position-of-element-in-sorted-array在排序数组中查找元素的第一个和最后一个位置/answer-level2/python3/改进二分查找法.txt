### 解题思路
left和right作为边界，在二分的过程中当一个边界为target时，只需移动第二个边界即可
当边界都为target时得到答案
当left与right都不为target时进行二分查找
当找到target时则同时移动边界。

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left = 0
        right = len(nums)-1
        while left<=right:
            mid = (left+right)//2
            if nums[left] == target and nums[right] == target:
                return [left,right]
            if nums[left] == target:right-=1
            elif nums[right] == target:left+=1
            else:
                if nums[mid]>target:right = mid-1
                elif nums[mid]<target:left = mid+1
                else:
                    right-=1
                    left+=1
        
        return [-1,-1]


```