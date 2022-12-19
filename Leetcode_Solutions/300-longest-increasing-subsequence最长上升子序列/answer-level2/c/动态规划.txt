```
int lengthOfLIS(int* nums, int numsSize)
{
    if (numsSize <= 0) {
        return 0;
    }
    if (numsSize == 1) {
        return 1;
    }
    int result = 0;

    // f[i]表示从nums尾部到nums[i]的最长上升子序列的长度
    int *f = (int *)calloc(numsSize, sizeof(int));

    //当前只有一个元素nums[numsSize - 1]，所以f[numsSize - 1]==1
    f[numsSize - 1] = 1;
   
    //从倒数第2个元素开始往前考察
    for (int i = numsSize - 2; i >= 0; i--) {
        int j;
        int max = 0;

        //当前考察元素nums[i]后面的最大的上升子序列长度是多少？
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] < nums[j]) {
                max = f[j] > max ? f[j] : max;
            } 
        }
        //当前考察元素的上升子序列的长度是它后面的最长长度加上1
        f[i] = max + 1;

        //持续刷新最终的长度
        if (f[i] > result) {
            result = f[i];
        }
    }
    return result;
}
```
