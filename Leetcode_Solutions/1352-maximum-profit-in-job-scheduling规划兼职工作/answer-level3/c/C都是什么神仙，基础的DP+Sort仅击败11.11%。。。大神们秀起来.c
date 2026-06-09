#define MAX_DP(a, b) (a) > (b) ? (a) : (b)

void sortSync(int* endTime, int* startTime, int* profit, int start, int end)
{
    int i,j,tmp, tmp2, tmp3;

    for(i = start + 1; i <= end; i++)
    {
        tmp = endTime[i];
        tmp2 = startTime[i];
        tmp3 = profit[i];

        for(j = i; j > start && tmp < endTime[j - 1]; j--)
        {
            endTime[j] = endTime[j - 1];
            startTime[j] = startTime[j - 1];
            profit[j] = profit[j - 1];
        }
        endTime[j] = tmp;
        startTime[j] = tmp2;
        profit[j] = tmp3;
    }
}

int jobScheduling(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int* profit, int profitSize){
    int i;
    int *dp;
    int dp_index = 0;
    int max_current = 0;
    // 按结束时间从小到大排序
    // 也试过qsort和mergeSort，优化不大
    sortSync(endTime, startTime, profit, 0, endTimeSize - 1);
    dp = (int *)malloc(sizeof(int) * endTime[endTimeSize-1] + sizeof(int));
    // dp(i) = max(dp[i-1], profit[i] + dp[start[i]])
    for(i = 0; i < endTimeSize; i++)
    {
        if(dp_index == endTime[i])
        {
             max_current = MAX_DP(dp[endTime[i]], profit[i] + dp[startTime[i]]);
        }
        else{
            while(dp_index < endTime[i])
            {
                dp[dp_index++] = max_current;
            }
            //max_current= MAX_DP(dp[endTime[i]-1], profit[i] + dp[startTime[i]]);
            max_current= MAX_DP(max_current, profit[i] + dp[startTime[i]]);
            dp[dp_index] = max_current;
        }        
    }
    free(dp);
    dp = NULL;
    return max_current;
}