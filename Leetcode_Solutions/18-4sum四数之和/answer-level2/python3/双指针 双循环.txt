### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        nums.sort()
        n = len(nums)
        for i in range(n):
            if (i > 0 and nums[i] == nums[i-1]):
                continue
            for j in range(i + 1, n):
                if (j>i+1 and nums[j]==nums[j-1]):
                    continue
                L = j + 1
                R = n - 1
                while L < R:
                    sum = nums[i] + nums[j] + nums[L] + nums[R]
                    if sum == target:
                        res.append([nums[i], nums[j], nums[L], nums[R]])
                        while (L < R and nums[L] == nums[L + 1]):
                            L += 1
                        while (L < R and nums[R] == nums[R - 1]):
                            R -= 1
                        L += 1
                        R -= 1
                    elif sum < target:
                        L += 1
                    else:
                        R -= 1
        return res

```