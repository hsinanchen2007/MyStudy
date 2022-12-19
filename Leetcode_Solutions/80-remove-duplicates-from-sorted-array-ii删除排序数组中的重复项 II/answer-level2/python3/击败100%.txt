```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n1,n2 = 0,0
        aa = ""
        while True:
            try:
                nums[n1]
            except IndexError:
                break
            if nums[n1] != aa:
                aa = nums[n1]
                n2 = 1
                n1 += 1
            else:
                if n2 == 2:
                    nums.pop(n1)
                else:
                    n2 += 1
                    n1 += 1
        return(len(nums))
```
