### 解题思路
字典查询表

### 代码

```python3
class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        d = {}
        for i in range(len(nums)):
            d[i] = nums[i]
        count = 0
        i = 0
        while i < len(nums):
            tmp = i
            ans = 0
            while d[tmp] != '#':
                ans += 1
                res = d[tmp]
                d[tmp] = '#'
                tmp = res
            i += 1
            count = max(count,ans)
        return count
```