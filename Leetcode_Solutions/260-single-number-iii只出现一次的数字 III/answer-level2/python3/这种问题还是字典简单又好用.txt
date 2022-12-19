```
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        length = len(nums)
        if(length <= 2):
            return nums
        dic1 = dict.fromkeys(list(set(nums)), 0)
        for each in nums:
            if(dic1[each] == 0):
                dic1[each] += 1
            else:
                del dic1[each]
        return list(dic1.keys())
```
