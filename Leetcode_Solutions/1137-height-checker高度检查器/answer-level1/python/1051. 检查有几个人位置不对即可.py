### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        return sum(i != j for i, j in zip(heights, sorted(heights)))
```