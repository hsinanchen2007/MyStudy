1.直接采用递归回溯的方法搜索会超时
直觉来说，肯定是尽可能多地用大面值的硬币，然后再用小的.如果采用大面值硬币不能组成所需的硬币,就减少数量直至0.
可以看出这是一种贪心+递归回溯的搜索策略.
代码如下
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans=INT_MAX;
        //逆序排序，选择尽可能大面值的硬币
        sort(coins.rbegin(),coins.rend());
        dfs(0,coins,amount,0,ans);
        return ans==INT_MAX?-1:ans;
    }

    void dfs(int index,vector<int>&coins,int amount,int cnt,int &ans){
        //递归基
        if(amount==0){
            ans=min(ans,cnt);
            return;
        }
        //递归基+剪枝
        if(index==coins.size()||amount<0)
            return;
        int times=amount/coins[index];
        //如果没有cnt+count<ans这一句代码会超时
        //可以看出这个剪枝操作也很关键~
        for(int count=times;count>=0&&cnt+count<ans;count--){
            dfs(index+1,coins,amount-count*coins[index],cnt+count,ans);
        }
    }
};
```
上面的代码跑的很快~
2.下面是一开始想到的状态转移方程
定义`dp[n][m]`为利用前`n`个硬币获得`m`金钱所需的最少硬币数量.容易得到状态转移方程为
`dp[n][m] = min{dp[n-1][m-coins[n-1] * k] + k | 0 <= k <= m/coins[n-1]}`,也就是说第`n`个硬币分别取`0,1,2,...,k`次.
代码如下，效率比较低.大概为$O(nm^2)$?
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>&nums=coins;
        vector<vector<int>> dp(n+1,vector<int>(amount+1,INT_MAX));
        int count=amount/nums[0];
        for(int k=0;k<=count;k++)
            dp[1][k*nums[0]]=k;
        

        for(int i=2;i<=n;i++){
            for(int j=amount;j>=0;j--){
                count=j/nums[i-1];
                for(int k=0;k<=count;k++){
                    if(dp[i-1][j-k*nums[i-1]]!=INT_MAX){
                        dp[i][j]=min(dp[i][j],k+dp[i-1][j-k*nums[i-1]]);
                    }
                }
                // cout<<"i: "<<i<<"j: "<<j<<"dp: "<<dp[i][j]<<endl;
            }
        }
        return dp[n][amount]==INT_MAX?-1:dp[n][amount];
    }
};
```
3.看了部分题解，发现自己的状态转移方程定义复杂了
因为本题每个硬币可以取多次,可以直接定义`dp[m]`为获取`m`金币所需的最少硬币，那么状态转移方程为
`dp[m] = min{dp[m-coins[i]]+1|0 <= i < n}`.
代码如下
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int j=1;j<=amount;j++){
            for(int i=0;i<n;i++){
                if(j>=coins[i]&&dp[j-coins[i]]!=INT_MAX)
                    dp[j]=min(dp[j],dp[j-coins[i]]+1);          
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};
```
时间复杂度为$O(nm)$