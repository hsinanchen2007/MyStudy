### 解题思路
此处撰写解题思路

### 代码

```c
struct node {
    int x;
    int y;
};

int calSum(int x, int y)
{
    int s = 0;
    while (x > 0) {
        s += x % 10;
        x = x / 10;
    }
    while (y > 0) {
        s += y % 10;
        y = y / 10;
    }
    return s;
}

int movingCount(int m, int n, int k){
    int i, j, dx, dy;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int visited[100][100] = {0};
    int sum;
    int total = 0;
    struct node queen[10002];
    struct node curr;
    int front = -1;
    int rear = 0;

    queen[0].x = 0;
    queen[0].y = 0;
    front = 0;
    rear = 1;
    total++;
    visited[0][0] = 1;

    while (front < rear) {
        curr = queen[front++];
        for (i = 0; i < 4; i++) {
            dx = curr.x + dir[i][0];
            dy = curr.y + dir[i][1];
            sum = calSum(dx, dy);
            if (dx >= 0 && dx < m && dy >= 0 && dy < n && sum <= k && visited[dx][dy] == 0) {
                queen[rear].x = dx;
                queen[rear].y = dy;
                rear++;
                total++;
                visited[dx][dy] = 1;
            }
        }
    }
    return total;
}
```