```
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        nums.sort()
        i,j = 0,1
        n1 = len(nums)
        list1 = []
        while j < n1:
            if nums[i] != nums[j]:
                i += 1
                j += 1
            else:
                list1.append(nums[i])
                i += 2
                j += 2
        return(list1)
```
