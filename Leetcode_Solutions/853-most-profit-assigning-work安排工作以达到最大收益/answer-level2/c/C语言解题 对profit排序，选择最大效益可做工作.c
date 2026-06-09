1. 将工作按照profit降序排列
2. 遍历工人可承受工作难度，再遍历排序后的工作，一旦发现当前工作工人可做，即为可做的能获取最大效益的工作；
3. 将此profit加入最终输出结果，进行下一个工人工作的分配


```
代码块
1. 将工作按照profit降序排列
2. 遍历工人可承受工作难度，再遍历排序后的工作，一旦发现当前工作工人可做，即为可做的能获取最大效益的工作；
3. 将此profit加入最终输出结果，进行下一个工人工作的分配



typedef struct tagWork {
    int difficulty;
    int profit;
} Work;
/* 降序 */
int cmp(const void *a, const void *b) 
{
    return ((Work*)b)->profit - ((Work*)a)->profit;
}
int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize){
    Work work[10000] = {0};
    int i, j;
    int totalProfit = 0;
    int maxProfit;
    for (i = 0; i < difficultySize; i ++) {
        work[i].difficulty = difficulty[i];
        work[i].profit = profit[i];
    }
    
    qsort(work, difficultySize, sizeof(Work), cmp);

    for(i = 0; i<workerSize;i++) {
        for(j = 0; j<difficultySize; j++) {
            if(worker[i] >= work[j].difficulty) {
                totalProfit += work[j].profit;
                break;
            }
        }
    }
    return totalProfit;
}
```