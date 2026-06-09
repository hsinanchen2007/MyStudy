```
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int len=nums.size();
        if(len < 3)
            return true;             //数组内元素个数小于3个时，玩家1总能够获胜
        vector<vector<int>> dp(len,vector<int>(len,0));  //dp[i][j] 表示玩家1在数组 i 到 j 区间内游戏能取得的最大值
        int sum=0;
        for(int i=0;i<len;++i)
        {
            sum+=nums[i];     //总分  用于最后比较两个玩家的分数；
            dp[i][i]=nums[i];    //初始化只有一个元素的情况
        }
        for(int l=1;l<len;++l)  //区间长度         循环次数  n*（n-1）/2
        {
            for(int i=0;i<len-l;++i) //起始位置
            {
                int j=i+l;
                if(l==1)
                    dp[i][j]=max(nums[i],nums[j]); //只有两个值时，玩家1取大值
                else   
                    dp[i][j]=max(nums[i]+min(dp[i+1][j-1],dp[i+2][j]),nums[j]+min(dp[i][j-2],dp[i+1][j-1]));
                      //多于两个值时，分情况讨论，玩家1手中时取max（dp）玩家2选择时取min（dp）

            }         //玩家1 取最左边一个时候考虑玩家2取最右边一个取左边第二个，选择dp较小者和最左边一个做和；
                      //玩家1 取最右边一个时候考虑玩家2取最左边一个和右边第二个，选择do较小者和最右边一个做和；
                      //选择玩家1能获得最大值的方式
        }
        return dp[0][len-1] >= sum-dp[0][len-1];
    }
};
```