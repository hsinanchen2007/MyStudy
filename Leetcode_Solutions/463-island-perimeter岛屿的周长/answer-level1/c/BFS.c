### 解题思路
广度优先，从第一个为1的网格开始搜索，先默认边长为4，接着搜索其周边的四个方向：
如果为1且没有访问过，加入队列，然后减去重叠的1个边；
如果为1已经访问过，不再加入队列，然后减去重叠的1个边；
直到队列为空，说明没有相邻的陆地，返回总周长。题目说只有一个岛屿，所以可此时可以直接返回。

### 代码

```c
struct str {
    int x;
    int y;
};
// BFS
int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
struct str dir[4] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
    struct str queen[10000];
    int front = 0;
    int rear = 0;
    int len = 0;
    int i, j;
    int dx, dy;
    struct str curr;

    int **visited = (int **)malloc(sizeof(int *) * gridSize);
    for (i = 0; i < gridSize; i++) {
        visited[i] = (int *)malloc(sizeof(int) * gridColSize[0]);
        for (j = 0; j < gridColSize[0]; j++) {
            visited[i][j] = 0;
        }
    }

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 0) {
                continue;
            }
            queen[rear].x = i;
            queen[rear++].y = j;
            visited[i][j] = 1;

            while (front < rear) {
                curr = queen[front++];
                len += 4;
                for (int k = 0; k < 4; k++) {
                    dx = curr.x + dir[k].x;
                    dy = curr.y + dir[k].y;
                    if (dx >= 0 && dx < gridSize && dy >= 0 && dy < gridColSize[0] && grid[dx][dy] == 1) {
                        if (visited[dx][dy] == 0) {
                            queen[rear].x = dx;
                            queen[rear++].y = dy;
                            visited[dx][dy] = 1;
                        }
                        len = len - 1;                   
                    }
                }
            }

            return len;
        }
    }

    return len;
}
```