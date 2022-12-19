### 解题思路
分析树形求解思路，套用回溯法模板

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        tmp = []

        def isBackTracking(res, tmp, index, n, nums):
            res.append(tmp[:])

            if index == n:
                return
            
            for i in range(index, n):
                tmp.append(nums[i])
                isBackTracking(res, tmp, i+1, n, nums)
                tmp.pop()

        isBackTracking(res, tmp, 0, len(nums), nums)

        return res
```