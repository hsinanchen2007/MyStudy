使用各个牢房状态定义数组，这样就可以计算出当下次该状态再出现时的周期是多少，代码简单易懂：
```
#define MAX_CELLS_LEN 8
int dp[2][2][2][2][2][2][2][2];
void CellsOneStep(int *cells, int cellsSize)
{
    int i;
    int cellTemp[MAX_CELLS_LEN];
    for (i = 0; i < MAX_CELLS_LEN; i++) {
        cellTemp[i] = cells[i];
    }
    if (cellTemp[0] == 1) {
        cells[0] = 0;
    }
    for (i = 1; i < MAX_CELLS_LEN - 1; i++) {
        if (cellTemp[i - 1] == cellTemp[i + 1]) {
            cells[i] = 1;
        } else {
            cells[i] = 0;
        }
    }
    if (cellTemp[i] == 1) {
        cells[i] = 0;
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* prisonAfterNDays(int* cells, int cellsSize, int N, int* returnSize){
    int i, j;
    int period = 0;
    int *result = NULL;
    *returnSize = 0;
    if (cellsSize != MAX_CELLS_LEN) {
        return NULL;
    }
    *returnSize = MAX_CELLS_LEN;
    result = (int *)malloc(sizeof(int) * MAX_CELLS_LEN);
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }
    (void)memset(dp, -1, sizeof(dp));
    for (i = 0; i < N; i++) {
        if (dp[cells[0]][cells[1]][cells[2]][cells[3]][cells[4]][cells[5]][cells[6]][cells[7]] != -1) {
            period = i - dp[cells[0]][cells[1]][cells[2]][cells[3]][cells[4]][cells[5]][cells[6]][cells[7]];
            j = N / period;
            while (i + j * period > N) {
                j--;
            }
            i += j * period;
            if (i >= N) {
                break;
            }
            CellsOneStep(cells, cellsSize);
            continue;
        }
        dp[cells[0]][cells[1]][cells[2]][cells[3]][cells[4]][cells[5]][cells[6]][cells[7]] = i;
        CellsOneStep(cells, cellsSize);
    }
    for (i = 0; i < MAX_CELLS_LEN; i++) {
        result[i] = cells[i];
    }
    return result;
}
```
