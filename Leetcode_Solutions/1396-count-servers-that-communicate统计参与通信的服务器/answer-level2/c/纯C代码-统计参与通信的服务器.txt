### 解题思路
此处撰写解题思路

### 代码

```c
int countServers(int** grid, int gridSize, int* gridColSize){
    bool flag[gridSize];
    int i, j, cnt, cnt1;
    int sum = 0;

    memset(flag, false, sizeof(bool) * gridSize);

    for (i = 0; i < gridSize; i++) {
        cnt = 0;
        for (j = 0; j < *gridColSize; j++) {
            cnt += grid[i][j];
        }
        if (cnt > 1) {
            flag[i] = true;
            sum += cnt;
        }
    }

    for (j = 0; j < *gridColSize; j++) {
        cnt = 0;
        cnt1 = 0;
        for (i = 0; i < gridSize; i++) {
            cnt += grid[i][j];
            if (flag[i] == false) {
                cnt1 += grid[i][j];
            }
        }
        if (cnt > 1) {
            sum += cnt1;
        }
    }

    return sum;
}
```