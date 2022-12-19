### 解题思路
每次排序后最小值取反就行，虽然复杂，但是简单粗暴

### 代码

```python3
class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        for i in range(K):
            A.sort()
            A[0] = -A[0]
        return sum(A)
```