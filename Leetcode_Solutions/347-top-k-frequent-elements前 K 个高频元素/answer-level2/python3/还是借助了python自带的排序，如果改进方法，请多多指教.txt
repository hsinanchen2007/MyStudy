```
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        nums.sort()
        i = 0
        j = 0
        res = {}
        while j < len(nums):
            if nums[i] == nums[j]:
                j += 1
            else:
                diff = j - i
                res[nums[i]] = diff
                i = j
                j += 1
        diff = j-i
        res[nums[i]] = diff
        ress = sorted(res.items(),key=lambda x:x[1])
        resss = []
        for i in range(len(ress)-k,len(ress)):
            resss.append(ress[i][0])
        return resss
```
