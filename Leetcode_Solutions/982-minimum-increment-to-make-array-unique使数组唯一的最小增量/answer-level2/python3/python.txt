### 解题思路

先排序
然后前后两数比较，将个数递增，之后更新数字
最后返回

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        res = 0
        for i in range(1,len(A)):
            if A[i] <= A[i-1]:
                res = res + A[i-1] - A[i] + 1
                A[i] = A[i-1] + 1
        return res
```