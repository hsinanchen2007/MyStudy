### 解题思路
此处撰写解题思路
码，动态规划
### 代码

```c
int lengthOfLIS(int* nums, int numsSize){
    int *dp = (int*)malloc(numsSize * sizeof(int));     // store the length
    int longest = 0;
    for(int i = 0, max = 0; i < numsSize; i++, max = 0){
        for(int j = 0; j < i; j++){
            max =((nums[j] < nums[i] && max <= dp[j])) ? dp[j] : max;
        }
        dp[i] = max+1;
        longest = longest < dp[i] ? dp[i] : longest;
    }
    free(dp);
    return longest;
}
```