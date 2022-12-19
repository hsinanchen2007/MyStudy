### 简单的回溯算法
简单的回溯算法那

### 代码

```c
#define MAX_LEN  100
int g_grids[100][100];

void intialGlobal()
{
    memset(g_grids, 0, sizeof(int) * MAX_LEN * MAX_LEN);
}

void step(int i, int j, int m, int n, int k) {
    int iTenBit = i / 10;
    int iBit = i % 10;
    int jTenBit = j / 10;
    int jBit = j % 10;

    if (i < 0 || j < 0 || i > m || j > n || g_grids[i][j] == 1) {
        return;
    }

    if ((iTenBit + iBit + jTenBit + jBit) > k) {
        return;
    }

    g_grids[i][j] = 1;

    step(i - 1, j, m, n, k);
    step(i + 1, j, m, n, k);
    step(i, j - 1, m, n, k);
    step(i, j + 1, m, n, k);
    return;
}

int movingCount(int m, int n, int k){
    int sumCount = 0;
    intialGlobal();
    step(0, 0, m, n, k);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if (g_grids[i][j] == 1) {
                sumCount++;
            }
        }
    }
    return sumCount;
}
```