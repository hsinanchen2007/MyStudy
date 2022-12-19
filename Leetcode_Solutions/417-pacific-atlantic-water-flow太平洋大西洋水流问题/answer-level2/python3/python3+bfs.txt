### 解题思路
大家都用的DFS，我贴一个BFS的吧

### 代码

```python3
class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        if not matrix or not matrix[0]: return []
        R = len(matrix)
        C = len(matrix[0])
        res1 = set()
        res2 = set()
        stack1 = [(i,0) for i in range(R)]
        stack1.extend((0,j) for j in range(C))
        stack2 = [(i,C - 1) for i in range(R)]
        stack2.extend((R - 1,j) for j in range(C) )
        while stack1:
            cur = stack1.pop(0)
            res1.add(cur)
            for x,y in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                tmp_x = cur[0] + x
                tmp_y = cur[1] + y
                if 0 <= tmp_x < R and 0 <= tmp_y < C and \
                    matrix[tmp_x][tmp_y] >= matrix[cur[0]][cur[1]] and \
                    (tmp_x,tmp_y) not in res1:
                    stack1.append((tmp_x,tmp_y))
        while stack2:
            cur = stack2.pop(0)
            res2.add(cur)
            for x,y in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                tmp_x = cur[0] + x
                tmp_y = cur[1] + y
                if 0 <= tmp_x < R and 0 <= tmp_y < C and \
                    matrix[tmp_x][tmp_y] >= matrix[cur[0]][cur[1]] and \
                    (tmp_x,tmp_y) not in res2:
                    stack2.append((tmp_x,tmp_y))
        return res1 & res2
```