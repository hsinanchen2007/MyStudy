```
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        re = []
        l = len(nums)
        for i in range(0, l):
            re.append(0)
        for num in nums:
            re[num - 1] = re[num - 1] + 1
        for i in range(0, l):
            if re[i] > 1:
                re.append(i + 1)
        return re[l:]
```