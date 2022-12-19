### 解题思路
假设某个数为最长上升子序列的最后一个数，序列长度为该数前面子序列的最长上升子序列的元素个数加1（自下而上）。
从第一个元素开始，以此类推，找到序列的最长长度（自上而下）。

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        else:
            ans = []
            for i in range(len(nums)):
                ans.append(1)
                for j in range(i):
                    if nums[i] > nums[j]:
                        ans[i] = max(ans[i], ans[j] + 1)
            return max(ans)
```