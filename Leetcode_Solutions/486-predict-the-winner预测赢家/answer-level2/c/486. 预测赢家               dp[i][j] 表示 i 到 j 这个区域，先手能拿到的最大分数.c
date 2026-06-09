### 解题思路
给定一个表示分数的非负整数数组。 玩家1从数组任意一端拿取一个分数，随后玩家2继续从剩余数组任意一端拿取分数，然后玩家1拿，……。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。

给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。

示例 1:

输入: [1, 5, 2]
输出: False
解释: 一开始，玩家1可以从1和2中进行选择。
如果他选择2（或者1），那么玩家2可以从1（或者2）和5中进行选择。如果玩家2选择了5，那么玩家1则只剩下1（或者2）可选。
所以，玩家1的最终分数为 1 + 2 = 3，而玩家2为 5。
因此，玩家1永远不会成为赢家，返回 False。



1、如果是偶数个，玩家1一定能赢；
2、如果是奇数个：
动态规划，状态 dp[i][j] 表示 i 到 j 这个区域，先手能拿到的最大分数。

初始已知状态：
只有一个数的情况：最大分数为 dp[i][i] = nums[i]; 

dp[i][j] = MAX(nums[j]-dp[i][j-1], nums[i] - dp[i+1][j]);
i
状态方程里  dp[i][j] 依赖于dp[i+1][j]  所以i从大到小来递推
记得i<j  即可

### 代码

```c
#define MAX(a,b) ((a)>(b)?(a):(b))
bool PredictTheWinner(int* nums, int numsSize){
     int i,j;
     int dp[1000][1000];

     memset(dp,0,100*100*sizeof(int));
     //dp = (int *)malloc(numsSize*numsSize*sizeof(int));

     dp[numsSize-1][numsSize-1] = nums[numsSize-1];
     for(i=numsSize-2;i>=0;i--){
         dp[i][i] = nums[i];
         for(j=i+1;j<numsSize;j++){
             dp[i][j] = MAX(nums[j]-dp[i][j-1], nums[i] - dp[i+1][j]);
         }
     }

     return dp[0][numsSize-1] >= 0;
}
```