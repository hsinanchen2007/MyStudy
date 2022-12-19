### 解题思路
Python 二重循环

### 代码

```python3
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        lens = len(nums)
        count = [0 for _ in range(lens)]
        for i in range(lens):
            for j in range(i+1,lens):
                if nums[i] > nums[j]:
                    count[i] += 1
                if nums[i] < nums[j]:
                    count[j] += 1
        return count

```