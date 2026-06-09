### 解题思路
用数组模拟队列，先将初始烂橘子入队后，每层遍历mins++，注意可能会出现没有橘子可污染的情况，这时候会
出队但是不会入队，不能加时间
而在广度优先遍历过程中队列需要一个start和一个end，但是由于进队出队的时候start和end会变，
所以一开始要用两个flag记录这两个值用于for循环

### 代码

```c

void bfs(int** grid, int gridSize, int* gridColSize, int **queue, int start, int end, int *mins)
{
    int i;
    int qLen = end - start;
    int startFlag = start;
    int endFlag = end;
    int x, y;
    // 如果队列为空，则返回
    if (qLen == 0) {
        return;
    }
    // 遍历队列中的烂橘子，把上下左右污染
    for (i = startFlag; i < endFlag; i++) {
        x = queue[i][0];
        y = queue[i][1];
        if (x - 1 >= 0 && grid[x - 1][y] == 1) {
            queue[end] = (int *)malloc(sizeof(int) * 2);
            queue[end][0] = x - 1;
            queue[end][1] = y;
            grid[x - 1][y] = 2;
            end++;
        }
        if (x + 1 < gridSize && grid[x + 1][y] == 1) {
            queue[end] = (int *)malloc(sizeof(int) * 2);
            queue[end][0] = x + 1;
            queue[end][1] = y;
            grid[x + 1][y] = 2;
            end++;
        }
        if (y - 1 >= 0 && grid[x][y - 1] == 1) {
            queue[end] = (int *)malloc(sizeof(int) * 2);
            queue[end][0] = x;
            queue[end][1] = y - 1;
            grid[x][y - 1] = 2;
            end++;
        }
        if (y + 1 < gridColSize[0] && grid[x][y + 1] == 1) {
            queue[end] = (int *)malloc(sizeof(int) * 2);
            queue[end][0] = x;
            queue[end][1] = y + 1;
            grid[x][y + 1] = 2;
            end++;
        }
        // 污染后的橘子出队
        start++;
    }
    // 如果队列空了就不要增加时间了
    if (start != end) {
        (*mins)++;
    }
    // 继续广度优先遍历
    bfs(grid, gridSize, gridColSize, queue, start, end, mins);
    return;
}
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int mins = 0;
    // 模拟队列的数组，存储烂橘子坐标
    int **queue = (int **)malloc(sizeof(int *) * 100);
    int i, j;
    int qLen = 0;
    // 先将初始烂橘子装入队列
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 2) {
                queue[qLen] = (int *)malloc(sizeof(int) * 2);
                queue[qLen][0] = i;
                queue[qLen][1] = j;
                qLen++;
            }
        }
    }
    int start = 0;
    int end = qLen;
    // 广度优先搜索
    bfs(grid, gridSize, gridColSize, queue, start, end, &mins);
    // 污染完所有能污染的橘子后看是否还有好橘子，如果有返回-1，否则返回时间
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return mins;
}
```