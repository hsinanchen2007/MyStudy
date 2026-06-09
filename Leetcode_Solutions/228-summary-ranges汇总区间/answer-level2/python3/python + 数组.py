```python
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        # special case
        if len(nums) == 1: return [str(nums[0])]
        res = []
        begin, pre = None, None
        def append(res, begin, end):
            if begin == end:
                res.append(str(begin))
            else: res.append(str(begin) + '->' + str(end))

        for i, num in enumerate(nums):
            if begin is None:
                begin = pre = num
                continue
            if num != pre + 1:
                append(res, begin, pre)
                begin = pre = num
            else: pre = num
            if i == len(nums) - 1: append(res, begin, pre)
        return res
```