```python
class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        #consecutive subarray
        # Time complexity : O(N)
        # Space complexity: O(N)
        res = 0
        dic = collections.defaultdict(list)
        prefix_sum = [0] * (len(nums) + 1)
        dic[0].append(0)
        for i in range(len(nums)):
            prefix_sum[i + 1] = prefix_sum[i] + nums[i]
            dic[prefix_sum[i + 1]].append(i + 1)

        for i, num in enumerate(prefix_sum):
            for index in dic[num + k]:
                if index >= i: res = max(res, index - i)
        return res
```