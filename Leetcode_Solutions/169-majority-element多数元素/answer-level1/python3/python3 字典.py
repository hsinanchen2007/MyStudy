第一眼的思路就想到了 用字典
```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        index = n//2
        dict = {}
        for num in nums:
            if num in dict:
                dict[num] += 1
            else:
                dict[num] = 1
            
        for i in dict:
            if dict[i] > index:
                return i
```
