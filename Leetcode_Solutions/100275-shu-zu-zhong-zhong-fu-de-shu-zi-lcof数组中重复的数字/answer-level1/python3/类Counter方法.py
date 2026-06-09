### 解题思路
使用python3类Counter

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        k = collections.Counter(nums)
        return k.most_common() [0][0]