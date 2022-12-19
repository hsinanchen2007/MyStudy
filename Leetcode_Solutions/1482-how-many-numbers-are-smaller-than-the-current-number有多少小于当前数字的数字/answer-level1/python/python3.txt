### 解题思路
排序解决
### 代码

```python3
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        lnum = sorted(nums)
        ans = []
        for i in range(len(nums)):
            for j in range(len(lnum)):
                if nums[i] == lnum[j]:
                    ans.append(j)
                    break
        return ans
```