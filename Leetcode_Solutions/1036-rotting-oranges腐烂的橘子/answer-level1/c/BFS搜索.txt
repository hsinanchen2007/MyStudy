### 解题思路
套用题解中参考模板

depth = 0 # 记录遍历到第几层
while queue 非空:
    depth++
    n = queue 中的元素个数
    循环 n 次:
        node = queue.pop()
        for node 的所有相邻结点 m:
            if m 未访问过:
                queue.push(m)


### 代码

```c
typedef struct 
{
    int x;
    int y;
} Node;

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int col = gridColSize[0];
    int direction[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    Node *queue = (Node *)malloc(sizeof(Node) * gridSize * col);


    int front = 0;
    int tail = 0;
    int count = 0;
    int time = 0;

    // 坏的橘子加入队列
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == 2) {
                queue[tail].x = i;
                queue[tail++].y = j;
             } else if (grid[i][j] == 1) {
                count++;
            }
        }
    }

    while (front < tail) {
        if (count > 0) {
            time++;
        }
        
        int end = tail;
        for (;front < end; front++) {
            int x = queue[front].x;
            int y = queue[front].y;

            for (int i = 0; i < 4; i++) {
                int xx = x + direction[i][0];
                int yy = y + direction[i][1];

                if (xx < 0 || xx >= gridSize ||
                    yy < 0 || yy >= col ||
                    grid[xx][yy] == 0 ||
                    grid[xx][yy] == 2) {
                        continue;
                }

                grid[xx][yy] = 2;
                queue[tail].x = xx;
                queue[tail].y = yy;
                tail++;
                count--;
            } 
        }
    }

    return count ? -1 : time;
}
```