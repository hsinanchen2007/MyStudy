```
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        #位运算&判断奇偶
        return sum(len(str(n)) & 1 == 0 for n in nums)
```
