#define MAX_LIMIT 100001
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize)
{
    int iSum = 0;
    int iCurMaxProfit = 0;
    int aiWorkToPrft[MAX_LIMIT] = {0};
    int aiDifToPrft[MAX_LIMIT] = {0};
    /* 记录工作难度到对应收益的映射，注意同样工作难度可能对应不同的收益，所以要取最大值 */
    for (int i = 0; i < difficultySize; i++) {
        aiDifToPrft[difficulty[i]] = MAX(aiDifToPrft[difficulty[i]], profit[i]);
    }
    for (int i = 0; i < MAX_LIMIT; i++) {
        iCurMaxProfit = MAX(iCurMaxProfit, aiDifToPrft[i]); /* 工作难度不超过i时，可以实施的最大收益 */
        aiWorkToPrft[i] = iCurMaxProfit; /* 建立工作难度i到其最大收益的映射 */
    }
    for (int i = 0 ; i < workerSize; i++) { /* 累加每个工人所能获得的最大收益 */
        iSum += aiWorkToPrft[worker[i]];
    }
    return iSum;
}