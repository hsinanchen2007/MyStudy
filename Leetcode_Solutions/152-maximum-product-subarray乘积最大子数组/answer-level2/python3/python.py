```python
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # corner case
        if nums == []: return 0
        # special case
        if len(nums) == 1: return nums[0]
        neg_val, pos_val = 0, 0
        res = float('-inf')
        for num in nums:
            if num < 0:
                pos_val, neg_val = neg_val * num, pos_val * num
            elif num > 0:
                pos_val, neg_val = pos_val * num, neg_val * num
            elif num == 0:
                pos_val, neg_val = 0, 0
            pos_val = max(pos_val, num)
            neg_val = min(neg_val, num)
            res = max(res, pos_val)
        return res

```