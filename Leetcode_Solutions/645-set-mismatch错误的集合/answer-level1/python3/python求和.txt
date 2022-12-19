```
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        sum1 = sum(nums)
        sum2 = (1 + len(nums)) * len(nums) / 2
        a = list(set([x for x in range(1,len(nums)+1)]) - set(nums))[0]
        l = []
        l.append(int(a - sum2 + sum1))
        l.append(a)
        return l
```
