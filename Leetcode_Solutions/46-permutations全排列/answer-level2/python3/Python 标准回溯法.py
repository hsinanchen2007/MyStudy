逐个字符添加，添加后去掉该字符（设为为None），尝试完成后进行恢复

```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def helper(solution):
            nonlocal nums,res
            if len(solution) == len(nums):
                res.append(solution.copy())

            for i in range(len(nums)):
                if nums[i] is not None:
                    num = nums[i]
                    nums[i] = None
                    solution.append(num)
                    helper(solution)
                    solution.pop()
                    nums[i] = num


        res = []
        helper([])
        return res
```
