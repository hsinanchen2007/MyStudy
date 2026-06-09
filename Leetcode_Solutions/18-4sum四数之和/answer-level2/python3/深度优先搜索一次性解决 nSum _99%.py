类似 3sum 的方法.

1. 首先还是排序
2. 当 n > 2 的时候深度优先搜索可能的解
3. 然后当 n == 2 的时候利用 3sum 的方法求出结果

```py
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        return self.nSum(nums, target, 4)

    def nSum(self, nums, target, n):
        def dfs(pos: int, cur: List[int], n: int, target: int):
            if n == 2:
                j = pos
                k = len(nums) - 1
                while j < k:
                    sum = nums[j] + nums[k]
                    if sum < target:
                        j += 1
                    elif sum > target:
                        k -= 1
                    else:
                        solution = cur[:] + [nums[j], nums[k]]
                        ans.append(solution)
                        while j < k and nums[j] == nums[j+1]:
                            j += 1
                        while j < k and nums[k] == nums[k-1]:
                            k -= 1
                        j += 1
                        k -= 1
                return
            i = pos
            while i < len(nums) - n + 1:
                # 剪枝的一种情况
                if nums[i] * n > target or nums[-1] * n < target:
                    break
                # 排除重复数字
                if i > pos and nums[i] == nums[i-1]:
                    i += 1
                    continue
                cur.append(nums[i])
                dfs(i+1, cur, n-1, target-nums[i])  # 回溯
                cur.pop()
                i += 1
        ans = []
        nums.sort()
        dfs(0, [], n, target)
        return ans
```
