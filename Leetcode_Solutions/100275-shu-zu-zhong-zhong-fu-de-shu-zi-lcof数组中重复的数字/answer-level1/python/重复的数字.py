### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        nums.sort()
        v = nums[-1]
        for n in nums:
            if n == v:
                return n
            v = n

```