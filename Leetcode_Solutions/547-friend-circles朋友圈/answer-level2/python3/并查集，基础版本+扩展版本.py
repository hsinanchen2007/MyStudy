基础版本：
```python []
class Solution:
    def _find(self, k, parent):
        while k != parent[k]:
            k = parent[k]
        return k

    def _union(self, i, j, parent, rank):
        i_root = self._find(i, parent)
        j_root = self._find(j, parent)
        if i_root == j_root:
            return 0

        if rank[i_root] > rank[j_root]:
            parent[j_root] = i_root
        elif rank[i_root] < rank[j_root]:
            parent[i_root] = j_root
        else:
            parent[j_root] = i_root
            rank[i_root] += 1
        return 1


    def findCircleNum(self, M: List[List[int]]) -> int:
        n = len(M)
        count = n
        parent = [i for i in range(n)]
        rank = [0 for i in range(n)]

        for i in range(n):
            for j in range(i, n):
                if M[i][j] == 0:
                    continue
                count -= self._union(i, j, parent, rank)

        return count
```
扩展版


