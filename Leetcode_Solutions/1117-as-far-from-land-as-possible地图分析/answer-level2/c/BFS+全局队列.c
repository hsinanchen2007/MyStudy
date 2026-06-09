### 解题思路
将已经为1的节点入度，step为1
再遍历每个队列里的step 不为0的节点，每遍历一个节点，记录下当前最大的step

### 代码

```c
struct dpData {
    int x;
    int y;
    int step;
};

#define MAX_LEN 10001
struct dpData queueD[MAX_LEN];
int pop = 0;
int max = 0;

void insert(int** grid, int x, int y, int step, int value)
{
    if (grid[x][y] == value) {
        queueD[pop].x = x;
        queueD[pop].y = y;
        queueD[pop].step = step;
        max = max > step ? max : step;
        grid[x][y] = 1;
        pop++;
    }
    return;
}

int maxDistance(int** grid, int gridSize, int* gridColSize){
    int index = 0;
    
    pop = 0;
    max = 0;
    memset(queueD, 0, sizeof(struct dpData) * MAX_LEN);

    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < *gridColSize; y++) {
            if (grid[x][y] == 1) {
                insert(grid, x, y, 1, 1);
            }            
        }
    }

    while (queueD[index].step != 0) {
        if (queueD[index].x >= 1) {
            insert(grid, queueD[index].x - 1, queueD[index].y, queueD[index].step + 1, 0);
        }

        if (queueD[index].x < (gridSize - 1)) {
            insert(grid, queueD[index].x + 1, queueD[index].y, queueD[index].step + 1, 0);
        }

        if (queueD[index].y >= 1) {
            insert(grid, queueD[index].x, queueD[index].y - 1, queueD[index].step + 1, 0);
        }

        if (queueD[index].y < (*gridColSize - 1)) {
            insert(grid, queueD[index].x, queueD[index].y + 1, queueD[index].step + 1, 0);
        }
        index++;
    }
    max = max > 1 ? max - 1 : -1;
    return max;
}
```