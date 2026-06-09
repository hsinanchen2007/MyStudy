### 解题思路
这道题很绕，看了题解才知道和994腐烂的橘子一样。
距离陆地最远的海洋区域：
从陆地扩散，每遇到一个海洋，`Node.lev`记录到该海洋的距离，并将海洋变成陆地，添加到队列里，这样才能继续扩散。
最后一个加入队列的海洋，也是最后一个出队的海洋，即最远的海洋

### 代码

```c
typedef struct {
    int x;
    int y;
    int lev;
} Node;

int maxDistance(int** grid, int gridSize, int* gridColSize){
    int direction[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    Node *queue = (Node *)malloc(sizeof(Node) * gridSize * gridColSize[0]);
    int front = 0;
    int tail = 0;
    int res = 0;
    
    // 陆地先入队
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 1) {
                queue[tail].x = i;
                queue[tail].y = j;
                queue[tail++].lev = 0;
            }
        }
    }
    // 如果全是陆地或者全是海洋，返回-1
    if (tail == front || tail == gridSize * gridColSize[0]) {
        return -1;
    }
    
    while (front < tail) {
        int x = queue[front].x;
        int y = queue[front].y;
        res = queue[front].lev;
        front++;
        
        for (int i = 0; i < 4; i++) {
            int xx = x + direction[i][0];
            int yy = y + direction[i][1];
            if (xx < 0 || xx >= gridSize || yy < 0 || yy >= gridColSize[0] || grid[xx][yy] == 1){
                continue;
            }
            grid[xx][yy] = 1;
            queue[tail].x = xx;
            queue[tail].y = yy;
            queue[tail].lev = res + 1;
            tail++;
        }
    }
    return res;
    
    
}

```