### 解题思路
广度搜索+两个剪枝
1 构建邻接矩阵：matrix[i][j]表示i至j的航班价格，初始化0表示两个航班线路不通
2 广度优先搜索：从起点开始，层次搜索。
3 两个剪枝条件：超过K次，以及价格超过当前全局最大

### 代码

```c
#define MAXFLY 100
#define MAXQUESIZE 10000000
#define COL 3
#define MAXPRICE 10000
#define MINPRICE 1
typedef struct stFly {
    int curPos;
    int curPri;
    int curNum;
}STFLY;
STFLY pQuene[MAXQUESIZE] = {0};
#define MIN(a, b) ((a < b) ? a : b)
#define PRINTF // printf
int g_rear = 0;
int g_head = 0;
int g_size = 0;
void PushQue(STFLY *pQuene, int curPos, int curPri, int curNum)
{
    if (g_rear == (g_head - 1) % MAXQUESIZE) { // 队列已满
        PRINTF("Push Failed %d %d %d\n",g_rear, g_head,g_size);
        return;
    }
    pQuene[g_rear].curPos = curPos;
    pQuene[g_rear].curPri = curPri;
    pQuene[g_rear].curNum = curNum;
    g_size++;
    g_rear = ((g_rear + 1) % MAXQUESIZE);
}

void PopQue(STFLY *pQuene, int *curPos, int *curPri, int *curNum)
{
    if(g_head == g_rear) { // 队列已空
        PRINTF("Pop Failed\n");
        return;
    }
    *curPos = pQuene[g_head].curPos;
    *curPri = pQuene[g_head].curPri;
    *curNum = pQuene[g_head].curNum;
    g_size--;
    g_head = ((g_head + 1) % MAXQUESIZE);    
}

bool InitMatrix(int **pMatrix, int** flights, int flightsSize)
{
    bool bRet = false;
    // 构造邻接矩阵，pArray[i][j]表示i至j的航班线路价格，0表示线路不通。
    for(int i = 0; i < flightsSize; i++) { // 构建邻接矩阵，
        if ((flights[i][2] > MAXPRICE) || (flights[i][2] < MINPRICE)) {
            goto ERR;
        }
        pMatrix[flights[i][0]][flights[i][1]] = flights[i][2]; // A至B的价格
    }
    bRet = true;
ERR:
    return bRet;
}
void BfsSearch(int **pMatrix, int size, int src, int dst, int K, int *pminTotPri)
{
    int curPos = src;
    int curPri = 0;
    int curNum = 0;
    PushQue(&pQuene[0], curPos, curPri, curNum);
    while (g_rear != g_head) { // 队列不为空
        PopQue(&pQuene[0], &curPos, &curPri, &curNum);
        if (curNum > K) { // 超过K次中转
            return;
        }
        for(int nextPos = 0; nextPos < size; nextPos++) {
            if(pMatrix[curPos][nextPos] == 0) { // 无效航线
                continue;
            }
            int updatPri = curPri + pMatrix[curPos][nextPos];
            if(nextPos == dst) { // 已到达终点,更新当前最便宜的航班价格
                *pminTotPri = MIN((*pminTotPri), updatPri);
                continue;
            }
            if (updatPri >= (*pminTotPri)) { // 价格超过当前记录的最小值剪枝掉
                continue;
            }
            PushQue(&pQuene[0], nextPos, updatPri, (curNum + 1)); // i 为当前航班号
        }
    }
}

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int K){
    int minTotPri = INT_MAX;
    g_rear = 0; // 初始化
    g_head = 0; // 初始化
    g_size = 0;
    if ((n > MAXFLY) || (flightsSize > (n * (n - 1) / 2)) || (K >= n)) {
        goto END;
    }
    int matrix[MAXFLY][MAXFLY] = {0};
    int *pMatrix[MAXFLY] = {};
    for (int i = 0; i < MAXFLY; i++) {
        pMatrix[i] = matrix[i];
    }
    PRINTF("%d %d %d %d %d\n", n, flightsSize, src, dst, K);
    bool bRet = InitMatrix(pMatrix, flights, flightsSize);
    if (bRet == false) {
        goto END;
    }
    BfsSearch(pMatrix, n, src, dst, K, &minTotPri); // 广度优先搜索遍历查询K次中转的航班价格，取最便宜的航班线路
END:
    if(minTotPri == INT_MAX) {
        return -1;
    }
    return minTotPri;
}
```