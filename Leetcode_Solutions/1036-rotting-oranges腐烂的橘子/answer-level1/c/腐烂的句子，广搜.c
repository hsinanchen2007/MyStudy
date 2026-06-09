typedef struct {
    int x;
    int y;
} Node;
#define MAXN 10000
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    Node queue[MAXN];
    int head = 0;
    int rear = 0;
    int i, j;
    int ans = 0;

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 2) {
                queue[rear].x = i;
                queue[rear].y = j;
                rear++;
            }
        }
    }

    while (head < rear) {
        int curX = queue[head].x;
        int curY = queue[head].y;
        head++;

        for (i = 0; i < 4; i++) {
            int tmpX = curX + dir[i][0];
            int tmpY = curY + dir[i][1];
            if (tmpX >= 0 && tmpY >= 0 && tmpX < gridSize && tmpY < *gridColSize && grid[tmpX][tmpY] == 1) {
                queue[rear].x = tmpX;
                queue[rear].y = tmpY;
                grid[tmpX][tmpY] = grid[curX][curY] + 1;
                rear++;
                ans = fmax(ans, grid[tmpX][tmpY] - 2);
            }
        }
    }
    
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return ans;
}