### 解题思路

#问题可以等效为，一个数组分成两部分，使这两部分的和尽可能的接近
#问题可以进一步化为，从一个数组取出一些数，使他们的和尽可能接近整体的1/2
#问题进一步化为，从一个数组取出一些数，在不大于sum/2的情况下，尽可能的大#动态规划，dp[i][j]表示 数组 前i 个数 在不大于j的情况下 组合可能的最大值。试一试
#dp[i][j] dp[i+1][j]的关系：dp[i+1][j]=max(dp[i][j],stones[i+1]+dp[i][j-stones[i]]) 到了第i+1个的时候判断用不用i+1这个数
#dp[i][j]=max(dp[i-1][j],stones[i]+dp[i-1][j-stones[i]])
#dp[i][j-n]和 dp[i][j]的关系 在从小到大的石头中，判断 取当前这块 和 dp[i][j-stone[i]]这两个循环比较取最大值 

作者：wangyaqi
链接：https://leetcode-cn.com/problems/last-stone-weight-ii/solution/pythondong-tai-gui-hua-by-wangyaqi/


普通01背包

### 代码

```java
class Solution {
    public int lastStoneWeightII(int[] stones) {
        int total = 0;
        int length = stones.length;
        for(int i=0;i<length;i++){
            total+=stones[i];
        }
        //当有i块石头时，包里的最大重量为j
        int[][] dp = new int[length+1][total/2+1];
        for(int i = 1;i<length+1;i++){
            for(int j= 1;j<total/2+1;j++){
                if(stones[i-1]<=j){
                    dp[i][j] = Math.max(dp[i-1][j-stones[i-1]]+stones[i-1],dp[i-1][j]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return total - (2*dp[length][total/2]);

    }
}
```


优化版
class Solution {
    public int lastStoneWeightII(int[] stones) {
        int total = 0;
        int length = stones.length;
        for(int i=0;i<length;i++){
            total+=stones[i];
        }
        //dp[i]当重量上限为i时，包所装入的最大重量
        int[] dp = new int[total/2+1];
        for(int i = 0;i<length;i++){
                int cur = stones[i];
                for(int j=total/2;j>=cur;j--){
                    dp[j] = Math.max(dp[j],dp[j-cur]+cur);
                } 
        }
        return total - (2*dp[total/2]);

    }
}