### 解题思路
BFS正常会比DFS快，所以用这个，由于状态转化互斥，所以我们可以从全0空间状态开始，
逐步扩展到所有可到达的状态，类似迪杰斯特拉最短路径法，逐步往外扩散。
直到找到目标状态，或者没有新的状态。

### 代码

```python
class Solution(object):
    def minFlips(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        s = 0
        N = len(mat)
        M = len(mat[0])
        target = 0
        for i in range(N):
            for j in range(M):
                if mat[i][j] == 1:
                    target = target | (1 << (i * M + j))
        if target == 0:
            return 0

        source = [0]
        old = set(source)
        while source:
            new_source = []
            s += 1
            for pattern in source:
                for i in range(N):
                    for j in range(M):
                        new_pattern = pattern
                        new_pattern = new_pattern ^ (1 << (i * M + j))
                        if i > 0:
                            new_pattern = new_pattern ^ (1 << ((i-1) * M + j))
                        if i < N-1:
                            new_pattern = new_pattern ^ (1 << ((i+1) * M + j))
                        if j > 0:
                            new_pattern = new_pattern ^ (1 << (i * M + j - 1))
                        if j < M-1:
                            new_pattern = new_pattern ^ (1 << (i * M + j + 1))
                        if new_pattern == target:
                            return s
                        if new_pattern not in old:
                            new_source.append(new_pattern)
                            old.add(new_pattern)
            source = new_source
        return -1
```