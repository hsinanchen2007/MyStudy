### 解题思路
快排，迭代器

### 代码

```python []
class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        m, n, d = len(mat), len(mat[0]), collections.defaultdict(list)
        for i, j in itertools.product(range(m), range(n)):
            d[i - j].append(mat[i][j])
        d = {k: iter(sorted(v)) for k, v in d.items()}
        for i, j in itertools.product(range(m), range(n)):
            mat[i][j] = next(d[i - j])
        return mat
```
![image.png](https://pic.leetcode-cn.com/b505b651d086b8f1f9f46ece704b93c911a648cb1d8651d47ae135e4b5236d05-image.png)
