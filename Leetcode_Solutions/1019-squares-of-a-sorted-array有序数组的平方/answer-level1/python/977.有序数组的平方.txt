### 解题思路
平方后排序。

### 代码

```python3
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        ans = []
        for i in A:
            ans.append(i**2)
        ans.sort()
        return ans
        # return sorted(x*x for x in A)
```