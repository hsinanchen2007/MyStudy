### 解题思路

对于python来说，条件查找一般都是列表解析最快。

### 代码

```python []
class Solution:
    def findMagicIndex(self, nums: List[int]) -> int:
        return next((i for i, j in enumerate(nums) if i == j), -1)
```