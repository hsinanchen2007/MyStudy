```
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        l = len(nums)
        re = []
        for i in range(0, l):
            re.append(0)
        for i in range(0, l):
            re[nums[i]-1] = 1
        for i in range(0, l):
            if re[i] == 0:
                re.append(i + 1)
        return re[l:]
```