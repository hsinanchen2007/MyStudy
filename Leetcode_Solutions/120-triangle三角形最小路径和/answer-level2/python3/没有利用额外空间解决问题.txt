### 解题思路
倒着来，思路见代码，很简单

### 代码

```python3
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        seq = triangle[-1]
        for li in triangle[::-1][1:]:
            for i in range(len(li)):
                seq[i] = min(seq[i] + li[i], seq[i + 1] + li[i])
        return seq[0]
```