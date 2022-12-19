```
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int queue[200], head = -1, tail = -1; // 队列，由于grid的元素最多100个，此处queue要存储坐标，所以分配200个int大小的空间
    int goodOrangeCnt = 0; // 记录当前grid中存在的没有腐烂的橘子
    int xs[4] = {-1, 0, 1, 0};
    int ys[4] = {0, -1, 0, 1};
    int timeTable[gridSize][*gridColSize]; // 记录grid中每个橘子腐烂的时间
    int ans = 0; // 保存答案

    memset(timeTable, -1, sizeof(timeTable)); // 将初始时间设置为-1

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 2) {
                queue[++tail] = i; // 腐烂橘子的位置入队列
                queue[++tail] = j;
                timeTable[i][j] = 0; // 首先腐烂的橘子的时间记为0
            }
            else if (grid[i][j] == 1) {
                goodOrangeCnt++;
            }
        }
    } 

    while (head != tail) { // 队列不为空，则进行后续操作
        int x = queue[++head]; // (x, y)为当前腐烂橘子的位置，并将其排除队列之外
        int y = queue[++head];
        for (int i = 0; i < 4; i++) { // 对每个腐烂橘子的上下左右四个位置进行搜索
            int tx = x + xs[i];
            int ty = y + ys[i];
            if (tx >= 0 && tx < gridSize && ty >= 0 && ty < *gridColSize && grid[tx][ty] == 1) { //  倘若存在未腐烂的橘子
                queue[++tail] = tx; // 坐标进入队列
                queue[++tail] = ty;
                timeTable[tx][ty] = timeTable[x][y] + 1; // 记录当前橘子的腐烂时间
                ans = timeTable[tx][ty];
                goodOrangeCnt--; 
                grid[tx][ty] = 2; // 将其标记为腐烂
            }   
        }
    } 
    return goodOrangeCnt > 0 ? -1 : ans;  
}
```
