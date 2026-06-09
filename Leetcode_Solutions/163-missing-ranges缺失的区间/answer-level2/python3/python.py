```python
class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
        # there maybe repeatable elements in the array.
        res = []
        begin = lower
        nums.append(upper + 1)
        for i, num in enumerate(nums):
            if i > 0 and nums[i] == nums[i - 1]: continue
            if num == begin: begin += 1
            else:
                if num - begin > 1:
                    res.append(str(begin) + '->' + str(num - 1))
                else:
                    res.append(str(begin))
                begin = num + 1
        return res
```