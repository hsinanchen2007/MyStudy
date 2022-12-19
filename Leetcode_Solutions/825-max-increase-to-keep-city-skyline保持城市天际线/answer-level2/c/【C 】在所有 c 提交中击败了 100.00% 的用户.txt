就是算天际线呗！
```
#define max(a, b) (((a) > (b)) ? (a) : (b))
int min(int a, int b)
{
    if (a < b) {
        return a;
    }
    return b;
}
// 就是算天际线呗
int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize)
{
    int maxColSize = 0;
    for (int i = 0; i < gridSize; i++) {
        maxColSize = max(gridColSize[i], maxColSize);
    }
    int* vertical = (int*)malloc(sizeof(int) * maxColSize);
    int* horizontal = (int*)malloc(sizeof(int) * gridSize);
    // 求每一行的最大值
    for (int i = 0; i < gridSize; i++) {
        int maxHeight = -1;
        for (int j = 0; j < gridColSize[i]; j++) {
            maxHeight = max(maxHeight, grid[i][j]);
        }
        horizontal[i] = maxHeight;
    }
    // 求每一列的最大值
    for (int i = 0; i < maxColSize; i++) {
        int maxHeight = -1;
        for (int j = 0; j < gridSize; j++) {
            if (gridColSize[j] < i + 1) {
                break;
            }
            maxHeight = max(maxHeight, grid[j][i]);
        }
        vertical[i] = maxHeight;
    }
    for (int i = 0; i < gridSize; i++) {
        printf("%d ", horizontal[i]);
    }
    printf("\n");
    for (int i = 0; i < maxColSize; i++) {
        printf("%d ", vertical[i]);
    }
    printf("\n");
    // 计算结果
    int res = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            res += min(horizontal[i], vertical[j]) - grid[i][j];
        }
    }
    free(horizontal);
    free(vertical);
    return res;
}

```
![image.png](https://pic.leetcode-cn.com/676d7bf2e1ee27ac2747d8a3ed225962195c87930617512aa5cdcb51b58fd478-image.png)
