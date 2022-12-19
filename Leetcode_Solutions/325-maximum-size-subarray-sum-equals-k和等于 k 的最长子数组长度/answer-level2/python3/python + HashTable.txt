```python
class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        # Time complexity : O(N)
        # Space complexity: O(N)
        # Prefix_sum + HashTable
        pre_dic = {0: 0}
        res, pre_sum = 0, 0
        for i in range(len(nums)):
            pre_sum += nums[i]
            if pre_sum - k in pre_dic:
                res = max(res, i + 1 - pre_dic[pre_sum - k])
            if pre_sum not in pre_dic:
                pre_dic[pre_sum] = i + 1
        return res
```