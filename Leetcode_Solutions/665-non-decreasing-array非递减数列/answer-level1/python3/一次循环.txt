
```python []
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        temp = min(nums)-1
        temp2 = temp -2
        changed = False
        for i in range(len(nums)):
            if nums[i] < temp:
                if changed == True:
                    return False
                elif nums[i] >= temp2:
                    changed = True
                    temp = nums[i]
                elif nums[i] < temp2:
                    nums[i] = temp          
                changed = True
            temp2 = temp
            temp = nums[i]
        return True
```
