```python
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        r, d = k + 1, {}
        for i, n in enumerate(nums):
            r, d[n] = min(r, i - d.get(n, -k - 1)), i
        return r <= k
```
- 本题题目有误，实际意思是找同数字最小间隔，若不超过 k 则满足条件
- 遍历列表，每次都比对最小间隔，并更新哈希表索引，当前位置往左的最小间隔一定是与上一次同数字出现的索引的距离
