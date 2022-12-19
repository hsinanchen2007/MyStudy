### 解题思路
最朴素的想法就是我从一个idx开始寻找nums[idx]直到出现重复的数字。然后记录下长度。过程中也要维护一个访问过的set，防止重复运算。最后返回最长的长度即可。

### 代码

```python
class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        if not nums: return 0
        seen, cur = set(), set()
        res = 0
        for i in range(len(nums)):
            while i not in seen and i not in cur:
                seen.add(i)
                cur.add(i)
                i = nums[i]
            res = max(res, len(cur))
            cur = set()
        return res
```