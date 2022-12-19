### 解题思路
用一个哈希表存储已经枚举过的结果，广搜每次能够反转的情况，如果没有出现过，将新状态放入队列中。

### 代码

```python3
class Solution:
    def minFlips(self, mat: List[List[int]]) -> int:
        from collections import deque
        import numpy as np
        mat = np.array(mat)

        row = len(mat)
        col = len(mat[0])
        visit = set()

        def list_to_tuple(mat):
            return tuple(tuple(x) for x in mat)

        queue = deque()
        queue.appendleft(mat)
        visit.add(list_to_tuple(mat))

        res = 0
        while queue:
            n = len(queue)
            for _ in range(n):
                cur = queue.pop()
                if cur.sum() == 0:
                    return res

                for i in range(row):
                    for j in range(col):
                        cur_copy = cur.copy()
                        cur_copy[i][j] = 1 - cur_copy[i][j]

                        if 0 <= i - 1 <= row - 1 and 0 <= j <= col - 1:
                            cur_copy[i - 1][j] = 1 - cur_copy[i - 1][j]
                        if 0 <= i + 1 <= row - 1 and 0 <= j <= col - 1:
                            cur_copy[i + 1][j] = 1 - cur_copy[i + 1][j]
                        if 0 <= i <= row - 1 and 0 <= j - 1 <= col - 1:
                            cur_copy[i][j - 1] = 1 - cur_copy[i][j - 1]
                        if 0 <= i <= row - 1 and 0 <= j + 1 <= col - 1:
                            cur_copy[i][j + 1] = 1 - cur_copy[i][j + 1]

                        cur_tuple = list_to_tuple(cur_copy)
                        if cur_tuple not in visit:
                            visit.add(cur_tuple)
                            queue.appendleft(cur_copy)

            res += 1
        return -1
```