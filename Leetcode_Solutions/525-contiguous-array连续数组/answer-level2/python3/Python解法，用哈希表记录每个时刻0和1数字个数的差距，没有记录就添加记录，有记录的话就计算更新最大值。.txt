```python3
class Solution:
    import collections
    def findMaxLength(self, nums: List[int]) -> int:
        res = 0
        dic = collections.defaultdict(int)
        count = 0
        dic[count] = -1 ## 初始化最开始的标志，当1和0数字相等时，返回的应该是index+1，其他情况index相减即可。
        for i in range(len(nums)):
            if nums[i] == 1:
                count -= 1
            else:
                count += 1
            if count in dic:
                res = max(res, i - dic[count])
            else:
                dic[count] = i
        return res
            
