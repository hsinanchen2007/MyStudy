暴力破解法的小小优化：如果新进来的比最大值要大，直接取新值，否则看旧窗口出去的那个值：1.比旧最大值小，则最大值不变；2.若相等，则在新窗口下暴力findmax。
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int findMax(int *arr, int i, int j)
{
    int max = arr[i];

    for (int k = i + 1; k <= j; k++) {
        max = max > arr[k] ?  max : arr[k];
    }
    return max;
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if((nums == NULL) || (numsSize == 0) || (k == 0)) {
        *returnSize = 0;
        return NULL;
    }

    if (k==1){
        *returnSize=numsSize;
        return nums;}


    int* dp=(int*)malloc(sizeof(int)*(numsSize));
    *returnSize=numsSize-k+1;
    int i,j;
    dp[0]=findMax(nums,0,k-1);
    for (j=1;j<*returnSize;j++){
        i=j+k-1;
        if (nums[i]>=dp[j-1]){
            dp[j]=nums[i];
        }
        else{
            if (nums[j-1]<dp[j-1]){
                dp[j]=dp[j-1];
            }
            if (nums[j-1]==dp[j-1]){
                    dp[j]=findMax(nums,j,k+j-1);
                    }
            }
        }
    return dp;
}
```
