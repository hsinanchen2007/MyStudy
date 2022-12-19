```
class Solution {
    class Pos {//定义结构
        int i, j, dis;
        public Pos(int _i, int _j, int _dis) {
            i = _i;
            j = _j;
            dis = _dis;//距离 什么时候遍历完
        }
    }
    int[][] dir = { {-1,0},{1,0},{0,-1},{0,1} };
    public int maxDistance(int[][] grid) {
        int row = grid.length;//行
        int col = grid[0].length;//列
        int dis = 0;//结果
        Queue<Pos> queue = new LinkedList<>();//Pos作为变量，三个量
        for(int i = 0; i < row; i++) {//找出岛屿
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    queue.add(new Pos(i, j, dis));//添加岛屿全部的进去
                }
            }
        }
        if(queue.size() == row*col) return -1;//判断是否全是1
        while(!queue.isEmpty()) {
            Pos pos = queue.poll();
            dis = pos.dis;
            for(int k = 0; k < 4; k++) {//判断周边的海洋
                int ni = pos.i + dir[k][0];
                int nj = pos.j + dir[k][1];
                if(ni >= 0 && ni < row && nj >= 0 && nj < col && grid[ni][nj] == 0) {
                    grid[ni][nj] = 1;//转为岛屿1，重新赋值
                    queue.add(new Pos(ni, nj, dis + 1));//添加新元素进去，进行下一遍历
                }
            }
        }
        for(int[] tmp : grid) {//判断是否全为0，正常在这里已经全部是1了，若存在0说明只能全是岛屿
            for(int j: tmp) {
                if(j == 0) {
                    return -1;
                }
            }
        }
        return dis;
    }
}
```
```
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        dis = 0
        queue = []
        dir = [(0, 1), (1, 0), (-1, 0), (0, -1)]
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    queue.append((i, j, dis))
        if len(queue) == row*col:
            return -1
        while queue:
            i, j, dis = queue.pop(0)
            for k in range(4):
                ni = i + dir[k][0]
                nj = j + dir[k][1]
                if ni >= 0 and ni < row and nj >= 0 and nj < col and grid[ni][nj] == 0:
                    grid[ni][nj] = 1;
                    queue.append((ni, nj, dis + 1))
        for tmp in grid:
            for k in tmp:
                if k == 0:
                    return -1
        return dis
```
