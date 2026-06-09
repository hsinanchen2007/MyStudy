### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        tmp = set()
        for x in nums:
            if x not in tmp:
                tmp.add(x)
            else:
                return x

```