![image.png](https://pic.leetcode-cn.com/39f165c12d04d64b9749acfc2844fa05222a0ffb3f9a1376f6af7cd1ee670b9b-image.png)

工人和工作一起升序排列，工人的前面的工作都可以做，选最大收益的
```
typedef struct {
    int difficulty;
    int profit;
}Work;

// 升序
int comp(const void *a, const void *b)
{
    return ((Work *)a)->difficulty - ((Work *)b)->difficulty;
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize){
    Work work[20000] = {0};
    int workNum = difficultySize;

    for (int i = 0; i < difficultySize; i++) {
        work[i].difficulty = difficulty[i];
        work[i].profit = profit[i]; 
    }

    for (int i = 0; i < workerSize; i++) {
        work[workNum++].difficulty = worker[i];
    }

    qsort(work, workNum, sizeof(Work), comp);

    int maxProfit = 0;
    int result = 0;
    for (int i = 0; i < workNum; i++) {
        if (work[i].profit == 0) {
            result += maxProfit;
            continue; 
        }

        if (work[i].profit > maxProfit) {
            maxProfit = work[i].profit;
        }
    }

    return result;
}
```
