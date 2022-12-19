整体上还是比较简单，但是实现中还是有很多小坑，小节上容易想不明白。需要根据数据相互认证调试下。

 输入（3x3）：
 |    -2      -3      3 
 |    -5      -10     1 
 |    10      30     -5 
 
 思路：
 每一格的逻辑是进入右下刚好死，并且保障在当前格刚好死，需要几点血
 当前格子进入右下刚好死，从最后一个格子向左上逆推到第一个刚好死。最终第一格加个1就好了，规则：
      当前格子自身是正 v=min(右，下)-自身， 但如果v<0, 那么 v 至少保证是0点血。
      当前格子自身是负 v=min(右，下)-自身。
 可以看出不用判断正负。
 
 实现：
      多申请一行一列，全部用max标示。
      但是右下角相邻两格设置为0，标示进入这两个地方均需要至少0点血。
 实现的最少step表格（4x4）[刚好死，刚好不死需要左上角+1]：
 |    6       4       1       MAX
 |    5       14      4       MAX
 |    0       0       5       0 
 |    MAX     MAX     0       ANY



如下为代码

```c
#define STEP(r, c) steps[(r) * (col + 1) + (c)]
#define DUN(r, c)  dungeon[r][c]
#define MIN(a, b)  (((a) > (b)) ? (b) : (a))
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))

#ifndef INT_MAX
#define INT_MAX ((int)(((unsigned int)-1) >> 1))
#endif

int _calculateMinimumHP(int **dungeon, int *steps, const int row, const int col)
{
    int r, c, right, bottom, current, value;
    // init externed col
    for (r = 0; r < row; r++) {
        STEP(r, col) = INT_MAX;
    }
    // init externed row
    for (c = 0; c < col; c++) {
        STEP(row, c) = INT_MAX;
    }
    value = DUN(row - 1, col - 1);
    STEP(row, col - 1) = STEP(row - 1, col) = 0;
    for (r = row - 1; r >= 0; r--) {
        for (c = col - 1; c >= 0; c--) {
            right = STEP(r, c + 1);
            bottom = STEP(r + 1, c);
            current = DUN(r, c);
            value = MIN(right, bottom) - current;
            STEP(r, c) = (value < 0) ? 0 : value;
        }
    }
    value = STEP(0, 0) + 1;
    return value;
}

int calculateMinimumHP(int **dungeon, int dungeonSize, int *dungeonColSize)
{
    int ret = -1;
    if (dungeon == NULL || dungeonColSize == NULL || dungeonSize <= 0 || *dungeonColSize <= 0) {
        return ret;
    }
    int *steps = calloc(sizeof(int), (dungeonSize + 1) * (1 + *dungeonColSize));
    if (steps == NULL) {
        return -1;
    }
    ret = _calculateMinimumHP(dungeon, steps, dungeonSize, *dungeonColSize);
    free(steps);
    return ret;
}

```
