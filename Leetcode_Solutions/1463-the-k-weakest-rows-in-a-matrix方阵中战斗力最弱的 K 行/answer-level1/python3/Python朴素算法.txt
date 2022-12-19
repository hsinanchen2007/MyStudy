### 解题思路
定义一个rank列表，存储mat中每一行对应的下标及其1的个数，之后对rank进行稳定排序，最后提取出rank的前k个元素。

### 代码

```python3
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        rank = []
        for i in range(len(mat)):
            rank.append((mat[i].count(1), i))
        for i in range(len(rank) - 1):
            for j in range(i + 1, len(rank)):
                if rank[i][0] > rank[j][0] or (rank[i][0] == rank[j][0] and rank[i][1] > rank[j][1]):
                    rank[i], rank[j] = rank[j], rank[i]
        res = []
        while k:
            res.append(rank.pop(0)[1])
            k -= 1
        return res
```