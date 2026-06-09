### 解题思路
6个牢房，组合值最多为64种可能，做一个大的循环，如果判断某一个值出现2次，那后面基本就会按照这个规律来回出现，将剩余的次数模上周期，就意味着在周期里面的值是不变的，只需要计算余数的值即可。

### 代码

```c
#define CELL_NUM 8
#define MAX_CYCLE_NUM 64

int g_tempCycleVal[CELL_NUM] = {0};
int g_cellSize = 0;

int g_cellTimes[MAX_CYCLE_NUM] = {0};
int g_cellLastIndex[MAX_CYCLE_NUM] = {0};

int *GetReturnResult(int* returnSize)
{
    *returnSize = 0;

    int *returnArray = malloc(g_cellSize * sizeof(int));
    if (returnArray == NULL) {
        return NULL;
    }

    *returnSize = g_cellSize;

    for (int i = 0; i < g_cellSize; i++) {
        returnArray[i] = g_tempCycleVal[i];
    }

    return returnArray;
}

void Init(int* cells, int cellsSize)
{
    int i;

    g_cellSize = cellsSize;

    for (i = 0; i < g_cellSize; i++) {
        g_tempCycleVal[i] = cells[i];
    }

    for (i = 0; i < MAX_CYCLE_NUM; i++) {
        g_cellLastIndex[i] = 0;
        g_cellTimes[i] = 0;
    }
}

void ArrayCpy(int *dst, int *src, int num)
{
    for (int i = 0; i < num; i++) {
        dst[i] = src[i];
    }
    return;
}


int IsArrayEqual(int *array1, int *array2, int num)
{
    int equalNum = 0;
    for (int i = 0; i < num; i++) {
        if (array2[i] == array1[i]) {
            equalNum++;
        }
    }

    if (equalNum == num) {
        return 1;
    }

    return 0;
}


void CalcCycleN(int cycleNum)
{
    int i;
    int temp[CELL_NUM] = {0};

    ArrayCpy(temp, g_tempCycleVal, g_cellSize);

    for (int k = 0; k < cycleNum; k++) {
        for (i = 1; i < g_cellSize - 1; i++) {
            if (temp[i - 1] == temp[i + 1]) {
                g_tempCycleVal[i] = 1;
            } else {
                g_tempCycleVal[i] = 0;
            }
        }
        ArrayCpy(temp, g_tempCycleVal, g_cellSize);
    }

}

int CalcCellVal(int *array)
{
    int sum = 0;

     for (int k = 1; k < g_cellSize - 1; k++) {
         sum += array[k] << (g_cellSize - k - 2);
     }
     return sum;
}

void FindFirstCycleTimes(int N)
{
    int tempLast[CELL_NUM] = {0};
    int timers = 0;
    int cycleTimers = 0;
    int cycleFlag = 0;
    int k;

     for (k = 0; k < N; k++) {
        ArrayCpy(tempLast, g_tempCycleVal, g_cellSize);

        timers = CalcCellVal(g_tempCycleVal);
        g_cellTimes[timers]++;
        if (g_cellTimes[timers] <= 1) {
            g_cellLastIndex[timers] = k;
        } else {
            cycleTimers = k - g_cellLastIndex[timers];
            cycleFlag = 1;
            break;
        }

        CalcCycleN(1);

        if (IsArrayEqual(g_tempCycleVal, tempLast, g_cellSize) == 1) {
            return;
        }
     }

    if (cycleFlag == 1 && cycleTimers > 0) {
        cycleTimers = (N - k) % cycleTimers;
        CalcCycleN(cycleTimers);
    }
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* prisonAfterNDays(int* cells, int cellsSize, int N, int* returnSize){

    if (cellsSize != CELL_NUM) {
        return NULL;
    }

    Init(cells, cellsSize);

    if (N <= 0) {
        return GetReturnResult(returnSize);
    }

    CalcCycleN(1);

    int iterNum = N;

    iterNum--;

    g_tempCycleVal[0] = 0;
    g_tempCycleVal[cellsSize - 1] = 0;

    if (iterNum > 0) {
        FindFirstCycleTimes(iterNum);
        return GetReturnResult(returnSize);
    } else {
        return GetReturnResult(returnSize);
    }
}
```