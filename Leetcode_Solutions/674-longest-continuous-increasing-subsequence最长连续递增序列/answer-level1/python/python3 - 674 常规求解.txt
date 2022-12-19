### 解题思路
两个列表存储结果
一个存储当前递增序列
一个存储当前最长递增序列

### 代码

```python3
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        if nums == []:
            return 0
        res = [nums[0]]
        ans = [nums[0]]
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                ans.append(nums[i])
            else:
                if len(ans) > len(res):
                    res = ans
                ans = [nums[i]]
        if len(ans) > len(res):
            res = ans
        return len(res)
```