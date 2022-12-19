### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findMagicIndex(self, nums: List[int]) -> int:
        nums = sorted(nums)
        for n,i in enumerate(nums):
            if n==i:
                return n
        return -1
```