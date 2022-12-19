## 思路：

只要数组里存在，两个相同的数的索引号相差小于等于k，返回` true`

```python
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        lookup = {}
        # 没有重复元素, 肯定返回False
        if len(set(nums)) == len(nums): return False
        # 只要有一个重复元素 相差的索引号 <=k 返回True
        for idx, num in enumerate(nums):
            if num in lookup and idx - lookup[num] <= k:
                return True
            lookup[num] = idx
        return False
```