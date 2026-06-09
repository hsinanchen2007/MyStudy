### 解题思路
第三通用模版需要，check left&right不管什么情况，因为right，left靠近的时候，没有进循环

### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        N = len(nums)
        if N == 0:
            return (-1, -1)         
        

        def find_start():
            left = 0
            right = N-1
            index_start = -1
            while left+1 < right:
                mid = left + (right-left)//2
                if nums[mid] == target:
                    right = mid
                elif nums[mid]<target:
                    left = mid
                elif nums[mid]>target:
                    right = mid

            if nums[left] == target:
                index_start = left
            elif nums[right] == target:
                index_start = right
            else:
                return -1
            return index_start 


        def find_end():
            left = 0
            right = N-1
            index_end = -1
            while left+1 < right:
                mid = left + (right-left)//2
                if nums[mid]==target:
                    left = mid
                elif nums[mid] > target:
                    right = mid
                elif nums[mid] < target:
                    left = mid
                
            if nums[right] == target:
                index_end = right
            elif nums[left] == target:
                index_end = left
            else:
                return -1  
            return index_end 

        return [find_start(),find_end()]
```