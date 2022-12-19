### 解题思路


### 代码

```c
struct str {
    int x;
    int y;
};

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    struct str dir[4] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
    struct str queen[2500];
    int front = 0;
    int rear = 0;
    int max = 0;
    int i, j;
    int dx, dy;
    struct str curr;

    // 定义数组用于判断当前区域是否已经被访问
    int **visited = (int **)malloc(sizeof(int *) * gridSize);
    for (i = 0; i < gridSize; i++) {
        visited[i] = (int *)malloc(sizeof(int) * gridColSize[0]);
        for (j = 0; j < gridColSize[0]; j++) {
            visited[i][j] = 0;
        }
    }

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; j++) {
            if (visited[i][j] == 1 || grid[i][j] == 0) {
                continue;
            }
            queen[rear].x = i;
            queen[rear++].y = j;
            visited[i][j] = 1;

            int area = 0;
            // 以当前坐标开始，不停的BFS，将所有满足条件的区域加进来，直到队列为空
            while (front < rear) {
                curr = queen[front++];
                area++;
                for (int k = 0; k < 4; k++) {
                    dx = curr.x + dir[k].x;
                    dy = curr.y + dir[k].y;
                    if (dx >= 0 && dx < gridSize && dy >= 0 && dy < gridColSize[0] && visited[dx][dy] == 0 && grid[dx][dy] == 1) {
                        queen[rear].x = dx;
                        queen[rear++].y = dy;
                        visited[dx][dy] = 1;
                    }
                }
            }
            // 更新最大值
            max = max > area ? max : area;
        }
    }

    return max;
}
```