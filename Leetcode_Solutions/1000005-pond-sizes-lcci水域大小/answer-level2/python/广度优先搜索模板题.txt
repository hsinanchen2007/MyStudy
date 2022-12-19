### 解题思路
见注释，终于没见到用卷积神经网络做题的狼人了

### 代码

```python3
class Solution:
    def pondSizes(self, land: List[List[int]]) -> List[int]:
        areas = []      # 水域面积存储数组
        visit = [[0 for _ in range(len(land[0]))] for _ in range(len(land))]        # 记录访问数组
        steps = [[1, 0], [1, 1], [0, 1], [-1, 1], [-1, 0], [-1, -1], [0, -1], [1, -1]]      # 八个方向

        def bfs(x, y):
            area = 1        # 存在水域才会调用bfs，所以初始水域面积为1
            q = [[x, y]]    # 广度优先搜索
            visit[x][y] = 1
            while q:
                p = q.pop(0)
                for i in steps:
                    dx, dy = p[0] + i[0], p[1] + i[1]
                    if 0 <= dx < len(land) and 0 <= dy < len(land[0]) and land[dx][dy] == 0 and visit[dx][dy] == 0:
                        q.append([dx, dy])
                        area += 1
                        visit[dx][dy] = 1
            areas.append(area)

        for i in range(len(land)):
            for j in range(len(land[0])):
                if land[i][j] == 0 and visit[i][j] == 0:
                    bfs(i, j)       # 对每个符合条件的水域调用bfs

        return sorted(areas)        #返回排序后的结果
```