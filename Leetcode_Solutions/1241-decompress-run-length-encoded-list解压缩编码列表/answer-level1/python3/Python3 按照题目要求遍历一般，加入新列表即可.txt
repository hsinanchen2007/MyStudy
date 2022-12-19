```
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        new_nums=[]
        for i in range(len(nums)-1):
            if i % 2 == 0:
                for _ in range(nums[i]):
                    new_nums.append(nums[i+1])
        return new_nums
```
