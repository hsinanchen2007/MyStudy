### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums_map = collections.Counter(nums)
        for i in range(len(nums)+1):
            if nums_map.get(i,0) == 0:
                return i

```