### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    int x;
    int y;
}NODE;

int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, {0, -1 }};
#define DEQUEUE(que) (que[front++])
#define ENQUEUE(que, data) (que[tail++] = data)
#define MAX_QUE 200
#define BAD_ORG 2
#define GOOD_ORG 1
#define EMPTY(que) (front == tail)

int orangesRotting(int** grid, int row, int* size){
    if ((grid == NULL) || (row <= 0) || (size == 0)) {
        return -1;
    }

    int i, j;
    int cnt = 0;
    int time = 0;
    int good = 0;
    int bad = 0;
    int col = size[0];
    int visit[row][col];
    NODE que[MAX_QUE];
    NODE data = { 0 };
    NODE tmp = { 0 };
    int front = 0;
    int tail = 0;
    int new_x, new_y;
    memset(que, 0, sizeof(NODE) * MAX_QUE);
    memset(visit, 0, sizeof(int) * row * col);

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (grid[i][j] == GOOD_ORG) {
                good++;
            } else if (grid[i][j] == BAD_ORG) {
                bad++;
                data.x = i;
                data.y = j;
                visit[i][j] = 1;
                ENQUEUE(que, data);
            }
        }
    }

    if (!good) {
        return 0;
    }
    
    while (!EMPTY(que)) {
        time++;
        cnt = 0;
        for (i = 0; i < bad; i++)
        {
            data = DEQUEUE(que);
            for (j = 0; j < 4; j++) {
                new_x = data.x + dir[j][0];
                new_y = data.y + dir[j][1];

                if ((new_x < 0) || (new_x >= row) || 
                    (new_y < 0) || (new_y >= col) || 
                    (visit[new_x][new_y])) {
                    continue;    
                }

                if (grid[new_x][new_y] == GOOD_ORG) {
                    good--;
                    cnt++;
                    tmp.x = new_x;
                    tmp.y = new_y;
                    visit[new_x][new_y] = 1;
                    ENQUEUE(que, tmp);
                }
            }
        }

        if (good <= 0) {
            break;
        }

        bad = cnt;
    }

    return ((good <= 0) ? time : -1);
}
```