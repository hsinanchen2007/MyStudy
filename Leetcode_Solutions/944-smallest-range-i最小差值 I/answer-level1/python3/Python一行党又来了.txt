### 解题思路
数组中最小值和最大值相差大于两倍的K时，最小差值为最大值和最小值之差减两倍的K；当最小值和最大值相差小于或等于两倍的K时，最小差值为0。

### 代码

```python3
class Solution:
    def smallestRangeI(self, A: List[int], K: int) -> int:
        return max(max(A) - min(A) - 2*K, 0)
```