```
class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        if k<0:
            return 0
        if k==0:
            repeat = set()
            repeatNum = set()
            for i in range(len(nums)):
                if nums[i] in repeat:
                    repeatNum.add(nums[i])
                else:
                    repeat.add(nums[i])
            return len(repeatNum)
        r = 0
        d = set(nums)
        for j in d:
            if (j+k) in d:
                r += 1
        return r
```
