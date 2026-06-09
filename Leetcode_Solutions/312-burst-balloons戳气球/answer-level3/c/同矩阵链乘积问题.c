### 解题思路
最初的思路是在第i到j个气球中，考虑第一个戳破的是第k个气球，那么就剩下[i,k-1]以及[k+1,j]两组气球。但是由于第k个气球戳破后，这两组气球之间是相邻的，两个子问题之间并不独立。
为了保持子问题之间的独立性，反过来考虑最后一个戳破第k个气球，在戳破第k个气球之前，需要戳破[i,k-1]和[k+1,j]两组气球。由于计算这两个子问题时第k个气球没有被戳破，两个问题之间相互独立，可以用动态规划的方式解决。即戳破[i,j]这一组气球所能得到的收益等于戳破[i,k-1]组的收益，加上戳破[k+1,j]组的收益，以及最终戳破k的收益。遍历k取最大值即可。
本问题同矩阵链乘积问题实质上相同
https://baike.baidu.com/item/矩阵链乘积/22787885?fr=aladdin

### 代码

```c
int maxCoins(int* nums, int numsSize){
    if(nums == NULL || numsSize < 1) { return 0; }
    int** dp = (int**)malloc(numsSize * sizeof(int*));
    for(int i = 0; i < numsSize; i++) { dp[i] = (int*)malloc(numsSize * sizeof(int)); }
    for(int len = 1; len <= numsSize; len++) {
        for(int i = 0; i <= numsSize - len; i++) {
            int j = i + len - 1;
            int leftBase, rightBase;
            if(i - 1 >= 0) { leftBase = nums[i - 1]; }
            else { leftBase = 1; }
            if(j + 1 <= numsSize - 1) { rightBase = nums[j + 1]; }
            else { rightBase = 1; }
            if(len == 1) {  // Only one element
                dp[i][j] = nums[i] * leftBase * rightBase;
            }
            else {          // More than one element
                for(int k = i; k <= j; k++) {
                    int coins = nums[k] * leftBase * rightBase;
                    if(k > i) { coins += dp[i][k - 1]; }
                    if(k < j) { coins += dp[k + 1][j]; }
                    if(k == i) { dp[i][j] = coins; }
                    else if(coins > dp[i][j]) { dp[i][j] = coins; }
                }
            }
        }
    }
    return dp[0][numsSize - 1];
}
```