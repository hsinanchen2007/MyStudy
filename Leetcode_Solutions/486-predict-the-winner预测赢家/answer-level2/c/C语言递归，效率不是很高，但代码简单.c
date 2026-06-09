递归，每次计算不管己方和对方都认为是最优策略，每步计算自己能够达到的最大差值。
代码很已于理解

```
#define MAX_TEMP (20 * 20)
int ScoreDiff(int* nums, int isCalcDiff[MAX_TEMP], int diffTmp[MAX_TEMP], int start, int end)
{
	if (start == end) {
		return nums[start];
	}

    int tmpIndex = start * 20 + end; // 缓存start、end对应的值，避免重复计算，数组规则太少，效果不明显
    if (isCalcDiff[tmpIndex]) {
        return diffTmp[tmpIndex];
    } 
	
    // 计算选头、选尾两种方案对应的最大分值差异
	int calcStart = nums[start] - ScoreDiff(nums, isCalcDiff, diffTmp, start + 1, end);
	int calcEnd = nums[end] - ScoreDiff(nums, isCalcDiff, diffTmp, start, end - 1);
	
    // printf("[%d->%d]:%d %d\n", start, end, calcStart, calcEnd);

    int result = (calcStart > calcEnd) ?calcStart : calcEnd;
    isCalcDiff[tmpIndex] = 1;
    diffTmp[tmpIndex] = result;

	return result;
}

bool PredictTheWinner(int* nums, int numsSize){
    int isCalcDiff[MAX_TEMP] = {0};
    int diffTmp[MAX_TEMP] = {0};
    // 如果最终两个玩家的分数相等，那么玩家1仍为赢家
	return (ScoreDiff(nums, isCalcDiff, diffTmp, 0, numsSize - 1) >= 0);
```
