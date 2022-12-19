```
class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        if n > 9 * k or n < k:
            return []
        nums = list(range(1, 10))
        result = []
        self.backtrack(k, n, nums, result, [], 0)
        return result

    def backtrack(self, k, n, nums, result, res, i):
        if sum(res) == n and len(res) == k:
            result.append(res)
            return
        for j in range(i, len(nums)):
            # 剪枝优化
            if sum(res) > n or len(res) > k:
                continue
            self.backtrack(k, n, nums, result, res + [nums[j]], j + 1)
```