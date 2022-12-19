

坏橘子作为队列的第一层。首先记录需要感染的橘子，最后多一下判断是否全部感染。

```c
struct orange {
    int x;
    int y;
    int step;
};

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int book[11][11] = {0};
    int cnt = 0;
    struct orange que[101] = {0};
    int next[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    int head = 1;
    int tail = 1;
    int i, j, k, nextx, nexty, result;

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[0]; ++j) {
            if (grid[i][j] == 1) {
                cnt++;
            }
            if (grid[i][j] == 2) {
                /* 入队 */
                que[tail].x = i;
                que[tail].y = j;
                que[tail].step = 0;
                tail++;
                book[i][j] = 1;
            }
        }
    }

    while (head < tail) {
        for (k = 0; k < 4; k++) {
            nextx = que[head].x + next[k][0];
            nexty = que[head].y + next[k][1];

            if (nextx < 0 || nextx >= gridSize || nexty < 0 || nexty >= gridColSize[nextx]) {
                continue;
            }

            if (grid[nextx][nexty] == 1 && book[nextx][nexty] == 0) {
                grid[nextx][nexty] == 2;
                book[nextx][nexty] = 1;
                cnt--;
                que[tail].x = nextx;
                que[tail].y = nexty;
                que[tail].step = que[head].step + 1;
                tail++;
            }
        }
        head++;
        result = que[tail - 1].step;
    }

    if (cnt == 0) {
        return result;
    } else {
        return -1;
    }
}
```