### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if nums == []:
            return 0
        maxLength = [1]*len(nums)
        for i in range(len(nums)):
            lqNums = [maxLength[j] for j in range(i) if nums[j]<nums[i]]
            maxLength[i] = max(lqNums)+1 if lqNums != [] else 1
        return max(maxLength)
```