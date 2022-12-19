### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        index_pre1 = 0
        index_pre2 = 0
        for i in nums:
            t = max(index_pre2, i + index_pre1)
            index_pre1 = index_pre2
            index_pre2 = t
        return index_pre2
```