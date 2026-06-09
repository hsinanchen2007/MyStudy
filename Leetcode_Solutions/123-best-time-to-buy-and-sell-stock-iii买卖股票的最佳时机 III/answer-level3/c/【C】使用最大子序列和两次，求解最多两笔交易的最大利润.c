参考:https://leetcode-cn.com/problems/maximum-subarray

1. 首先使用每天的价格计算利润
2. 利润求解后，将利润序列划分为两个子序列
    输入序列：     
    [3,3,5,0,0,3,1,4]
    利润序列：     
    [0,2,-5,0,3,-2,3]
    压缩利润序列：  
    [2,-5,3,-2,3] 
3. 子序列划分思路  
    [2,-5,3,-2,3] 可以划分为，[2] [3,-2,3] 、[2,-5][-2,3]、[2,-5,3][3]
4. 求两个子序列的最大子序列和，相加
5. 对于序列[2,-5,3,-2,3] 求最大子序列和，最终求max

```
#ifndef __cplusplus
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))
#endif

void calcProfits(int profitsSize, int *profits, int *prices)
{
    for (int i = 0; i < profitsSize; ++i) {
        profits[i] = prices[i + 1] - prices[i];
    }
}

int mergeProfits(int profitsSize, int *profits)
{
    int mergedProfitIndex = 0;
    int sum = 0;
    bool negativeNum = profits[0] < 0;
    for (int i = 0; i < profitsSize; ++i) {
        if (profits[i] < 0) {
            if (!negativeNum) {
                profits[mergedProfitIndex] = sum;
                ++mergedProfitIndex;
                sum = 0;
            }
            negativeNum = true;
            sum += profits[i];
        } else {
            if (negativeNum) {
                profits[mergedProfitIndex] = sum;
                ++mergedProfitIndex;
                sum = 0;
            }
            negativeNum = false;
            sum += profits[i];
        }
    }
    if (mergedProfitIndex < profitsSize) {
        profits[mergedProfitIndex] = sum;
    }
    return mergedProfitIndex + 1;
}

int maxSubArray(int* nums, int numsSize)
{
    if (nums == NULL || numsSize <= 0) {
        return 0;
    }

    int sum = nums[0];
    int maxSum = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        if (sum > 0) {
            // append
            sum += nums[i];
        } else {
            // clean and reset
            sum = nums[i];
        }
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}

int maxProfit(int* prices, int pricesSize)
{
    if (prices == NULL) {
        return 0;
    }

    if (pricesSize <= 1) {
        return 0;
    }

    int *profits = (int *)malloc(sizeof(int) * pricesSize - 1);
    if (profits == NULL) {
        return 0;
    }

    int profitsSize = pricesSize - 1;
    calcProfits(profitsSize, profits, prices);

    int mergedProfitsSize = 0;
    mergedProfitsSize = mergeProfits(profitsSize, profits);
    int maxProfits = 0;
    for (int i = 1; i < mergedProfitsSize - 1; ++i) {
        int anotherStart = i + 1;
        int anotherLength = mergedProfitsSize - anotherStart;
        maxProfits = max(maxProfits, maxSubArray(profits, i) + maxSubArray(&profits[anotherStart], anotherLength));
    }

    // 只选择一次的结果
    maxProfits = max(maxProfits, maxSubArray(profits, mergedProfitsSize));

    free(profits);
    profits = NULL;

    return maxProfits;
}
```





