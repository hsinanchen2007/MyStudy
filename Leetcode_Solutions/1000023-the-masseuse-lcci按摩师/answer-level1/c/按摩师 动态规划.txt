### 解题思路
感谢大佬的题解[100%, 空间从O(n)优化到O(1)，包会～](https://leetcode-cn.com/problems/the-masseuse-lcci/solution/100-kong-jian-cong-onyou-hua-dao-o1bao-hui-by-swee/)，这道题和[最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)很相似。

关键代码仍然是`dp[i]=maxVal(dp[i-1],dp[i-2]+nums[i]);` 一定要明确数组dp的含义：[0,i]范围内最长服务时长。

本题和[最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)的递推方程的区别是什么呢？我还不是很明白。

### 代码

```c
int massage(int* nums, int numsSize){
    if(numsSize==0) return 0;
    if(numsSize==1) return nums[0];
    int maxVal(int x,int y);
    int i;
    int *dp=(int*)malloc(numsSize*sizeof(int));
    dp[0]=nums[0];
    dp[1]=maxVal(nums[0],nums[1]);
    for(i=2;i<numsSize;i++){
        dp[i]=maxVal(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[numsSize-1];
}

int maxVal(int x,int y){
    if(x>y) return x;
    else return y;
}
```