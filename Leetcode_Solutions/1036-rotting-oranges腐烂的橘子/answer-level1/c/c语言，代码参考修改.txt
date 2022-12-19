### 解题思路
执行结果：
通过
显示详情
执行用时 :
4 ms
, 在所有 C 提交中击败了
96.41%
的用户
内存消耗 :
5.3 MB
, 在所有 C 提交中击败了
100.00%
的用户

1、按腐烂的顺序，层次遍历，初始化加入腐烂的橘子到队列,统计新鲜橘子，此是设置时间为0
2、BFS队列中的橘子，队列中橘子遍历完成代表本层完成遍历，时间加1（刚开始要记录队列有多少数据，区分不同层次）
### 代码

```c
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    // 初始化队列
    int queue[gridSize * (*gridColSize)][2];
    int head = 0, rear = 0;
    // 寻找所有初值为2的点，入队
    for(int i = 0; i < gridSize; ++i)
    for(int j = 0; j < *gridColSize; ++j)
        if(grid[i][j] == 2) {

            queue[rear][0] = i;
            queue[rear][1] = j;
            rear++;
        }
    if (rear == 0) { /*初始无腐烂橘子，直接返回*/
        return -1;
    }
    // 时间
    int time = 0;
    // 记录每次感染后队尾位置
    int pos = rear;
    // 开始遍历，队空时说明遍历完毕
    while(head != rear) {
        // head == pos说明一遍感染完毕
        if(head == pos) {
            pos = rear;
            time++;
        }
        // 队头出队
        int row = queue[head][0];
        int col = queue[head][1];
        head++;
        // 判断四个方向是否有好橘子，有则入队，值改为2
        if(row-1 >= 0 && grid[row-1][col] == 1) {   // 上
            grid[row-1][col] = 2;
            // 入队
            queue[rear][0] = row-1;
            queue[rear][1] = col;
            rear++;
        }
        if(row+1 < gridSize && grid[row+1][col] == 1) { // 下
            grid[row+1][col] = 2;
            // 入队
            queue[rear][0] = row+1; 
            queue[rear][1] = col;
            rear++;
        }
        if(col-1 >= 0 && grid[row][col-1] == 1) {   // 左
            grid[row][col-1] = 2;
            // 入队
            queue[rear][0] = row;
            queue[rear][1] = col-1;
            rear++;
        }
        if(col+1 < *gridColSize && grid[row][col+1] == 1) { // 右
            grid[row][col+1] = 2;
            // 入队
            queue[rear][0] = row;
            queue[rear][1] = col+1;
            rear++;
        }
    }
    // 查看是否还有好橘子，有返回-1，没有返回time
    for(int i = 0; i < gridSize; ++i)
    for(int j = 0; j < *gridColSize; ++j)
        if(grid[i][j] == 1)
            return -1;
    return time;
}
```