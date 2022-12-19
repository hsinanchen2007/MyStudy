![image.png](https://pic.leetcode-cn.com/783fcffad68ef0d3ef5d66764fb5750d6aaa505de1fb6ac9044e7a06e55dbc64-image.png)


```
from typing import List
from collections import deque
from copy import deepcopy
from pprint import pprint
class Solution:

    def getCode(self, mat: List[List[int]]):
        m, n = len(mat), len(mat[0])
        val = 0
        for i in range(m):
            for j in range(n):
                if mat[i][j]:
                    val |= (1 << i * n + j)
        return val


    def minFlips(self, mat: List[List[int]]) -> int:
        que = deque()
        visited = set()

        que.append(mat)
        visited.add(self.getCode(mat))

        m, n = len(mat), len(mat[0])
        steps = 0
        while len(que) > 0:
            node_num = len(que)
            for _ in range(node_num):
                cur = que.popleft()
                if self.getCode(cur) == 0:
                    return steps

                for i in range(m):
                    for j in range(n):
                        new_mat = deepcopy(cur)
                        new_mat[i][j] = 1 - new_mat[i][j]
                        for ii, jj in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
                            if ii >= 0 and ii < m and jj >= 0 and jj < n:
                                new_mat[ii][jj] = 1 - new_mat[ii][jj]

                        #pprint(new_mat)
                        code = self.getCode(new_mat)
                        if code not in visited:
                            visited.add(code)
                            que.append(new_mat)
            steps += 1

        return -1
```
