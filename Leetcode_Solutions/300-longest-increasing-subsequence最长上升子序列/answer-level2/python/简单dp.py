### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        table = [1] * len(nums)
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[j] < nums[i]:
                    table[i] = max(table[i], table[j]+1) 

        return max(table) if table else 0
```