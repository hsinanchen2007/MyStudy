### 解题思路
排序O(nlogn)，遍历O(m+n)

### 代码

```python3
class Solution:
    def smallestDifference(self, a: List[int], b: List[int]) -> int:
        a = sorted(a)
        b = sorted(b)
        i, j, gap = 0, 0, abs(a[0]-b[0])
        while i < len(a) and j < len(b):
            gap = min(gap, abs(a[i]-b[j]))
            if a[i] < b[j]:
                i += 1
            else:
                j += 1
            if gap == 0:
                return 0
        return gap
            
```