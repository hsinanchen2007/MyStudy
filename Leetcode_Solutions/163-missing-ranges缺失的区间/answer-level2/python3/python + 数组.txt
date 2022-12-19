```python
class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
        res = []
        pre = lower - 1
        for i, num in enumerate(nums):
            if num == pre: continue
            if num == pre + 1: 
                pre = num
                continue
            if num < lower or pre > upper: continue
            left = max(lower, pre + 1)
            right = min(num - 1, upper)
            if left == right: res.append(str(left))
            else: res.append(str(left) + '->' + str(right))
            pre = num
        if pre + 1 == upper:
            res.append(str(upper))
        elif pre + 1 < upper:
            res.append(str(pre + 1) + '->' + str(upper))
        return res
        

```