### 解题思路
需要返回 1 最少的前 k 行，1 一样多的先返回下标小的。

1. 统计每行有几个 1。
2. 排序
3. 返回前 k 个下标

### 代码

```python
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        n = len(mat)
        m = len(mat[0])
        x = [[sum(l)*(n+1)+(i),i] for i,l in enumerate(mat)]
        x.sort(key=lambda x:x[0])
        return [x[i][1] for i in range(k)]
```