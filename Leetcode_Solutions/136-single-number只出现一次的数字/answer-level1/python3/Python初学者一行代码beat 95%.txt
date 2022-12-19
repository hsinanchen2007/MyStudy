重要条件：题目限定了每个数字都只会出现两次
思路：先使用set（）得到所有非重复的数字，double后求和，与nums求和的值相减即得答案
```
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        return result = 2*sum([i for i in set(nums)])-sum(nums)
```
