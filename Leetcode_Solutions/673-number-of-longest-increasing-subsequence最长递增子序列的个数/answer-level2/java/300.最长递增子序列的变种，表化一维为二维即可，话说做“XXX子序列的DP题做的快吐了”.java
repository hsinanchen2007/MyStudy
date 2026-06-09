### 解题思路
![QQ截图20200407172259.png](https://pic.leetcode-cn.com/8816f3ebf5a3ce0419d8883845f77ca9914ee11f98dd68a9e0124f21b3a8ebac-QQ%E6%88%AA%E5%9B%BE20200407172259.png)

时间复杂度O(n^2)
会做300就会做这个，升个维度而已，存“长度”的同时顺带存一下“该长度的个数”就行

dp[i][0]相当于300题里的dp[i]，即“**以nums[i]结尾的**最长递增子序列的长度”，dp[i][1]是这里升的维度，存“**以nums[i]结尾的最长递增子序列的个数**”，即题目所求的数值。l用来保存所有的dp[i][0]的最大值，m用来保存刷新某个dp[i][0]时对应的dp[i][1]。

具体更新dp[i][1]的时候要注意：如果是dp[j][0]+1==dp[i][0]，表示某个nums[j]+nums[i]组成的子序列长度与当前最长长度相等，那么形成**到nums[i]为止的当前最长子序列的方法数**应该**加上**到**nums[j]为止的当前最长子序列的方法数**,即dp[i][1]+=dp[j][1];如果dp[j][0]+1>dp[i][0]，就代表找到了新的最长子序列，那么形成最长子序列的方法数要更新成当前最大，即dp[i][1]=dp[j][1]。

同理：如果l==dp[i][0],那么代表又找到了dp[i][1]种生成最长子序列的方法数，m+=dp[i][1];如果dp[i][0]>l，那么生成最长子序列的方法数要更新，即m=dp[i][1]。

总结一下状态转移方程：
对每一对（i，j):if(nums[j]<nums[i])
{
                    if(dp_num_lis[j][0]+1==dp_num_lis[i][0]) {
                       dp_num_lis[i][1]+=dp_num_lis[j][1];
                    }
                    else if(dp_num_lis[j][0]+1>dp_num_lis[i][0]){
                        dp_num_lis[i][0]=dp_num_lis[j][0]+1;
                        dp_num_lis[i][1]=dp_num_lis[j][1];
                    }
}，其中1<=i<=n-1;0<=j<=i-1.


对每一个i:if(dp_num_lis[i][0]==longest_lis)
{
               most_num+=dp_num_lis[i][1];
            }
            else if(dp_num_lis[i][0]>longest_lis){
                longest_lis=dp_num_lis[i][0];
                most_num=dp_num_lis[i][1];
            }
}

### 代码

```java
class Solution {
    public int findNumberOfLIS(int[] nums) {
         int n=nums.length;
        if(n==0) return 0;
        if(n==1) return 1;
        int [][] dp_num_lis=new int[n][2];//dp[i][0]表示“以nums[i]结尾”的最长递增子序列的长度，dp[i][1]表示对应长度的个数
        dp_num_lis[0][0]=1;
        dp_num_lis[0][1]=1;
        int longest_lis=1;
        int most_num=1;
        for(int i=1;i<n;i++){
            dp_num_lis[i][0]=1;//它自己就是最长的递增子序列
            dp_num_lis[i][1]=1;//只有一个他自己
            for(int j=0;j<=i-1;j++){
                if(nums[j]<nums[i]){
                    if(dp_num_lis[j][0]+1==dp_num_lis[i][0]) {
                       dp_num_lis[i][1]+=dp_num_lis[j][1];
                    }
                    else if(dp_num_lis[j][0]+1>dp_num_lis[i][0]){
                        dp_num_lis[i][0]=dp_num_lis[j][0]+1;
                        dp_num_lis[i][1]=dp_num_lis[j][1];
                    }else{
                        //nothing
                    }
                }else{
                    //nothing
                }
            }
            if(dp_num_lis[i][0]==longest_lis){
               most_num+=dp_num_lis[i][1];
            }
            else if(dp_num_lis[i][0]>longest_lis){
                longest_lis=dp_num_lis[i][0];
                most_num=dp_num_lis[i][1];
            }
        }
        return most_num;

    }
}
```