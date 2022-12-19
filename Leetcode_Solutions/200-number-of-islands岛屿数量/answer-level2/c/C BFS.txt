### 解题思路
经典广度搜索，需注意这里的每个是字符，不是数字

### 代码

```c
struct str {
    int x;
    int y;
};
// BFS
int numIslands(char** grid, int gridSize, int* gridColSize){
    if (gridSize == 0) {
        return 0;
    }
    struct str dir[4] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
    struct str queen[gridSize*gridColSize[0]];
    int front = 0;
    int rear = 0;
    int cnt = 0;
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
            if (grid[i][j] == '0' || visited[i][j] == 1) {
                continue;
            }
            queen[rear].x = i;
            queen[rear++].y = j;
            visited[i][j] = 1;
            while (front < rear) {
                curr = queen[front++];
                for (int k = 0; k < 4; k++) {
                    dx = curr.x + dir[k].x;
                    dy = curr.y + dir[k].y;
                    if (dx >= 0 && dx < gridSize && dy >= 0 && dy < gridColSize[0] && grid[dx][dy] == '1' && visited[dx][dy] == 0) {
                        queen[rear].x = dx;
                        queen[rear++].y = dy;
                        visited[dx][dy] = 1;
                    }
                }
            }
            cnt++;
        }
    }

    return cnt;
}


```