### 动态规划
1. 数据结构说明
    * dp数组，dp[i]表示以nums[i]结尾的最长摆动序列长度
    * directioins数组，dirctions[i]表示nums[i]结尾的最长摆动序列末尾元素的方向：0表示是起始点,1表示上升，2表示下降
2. 算法
    * 要计算以nums[i]结尾的最长摆动序列，就要变量j=1~i-1，能够加长只有两种情况
        1. nums[j]<nums[i]&&directions[j]!=上升
        2. nums[j]>nums[i]&&directions[j]!=下降

        保存符合条件的最优j，就是i的最佳前缀子序列
```
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return n;
        int*dp=new int[n];//dp[i]表示以i结尾的最长摆动序列
        int *directions=new int[n];//0:初始点, 1:up , 2:down
        dp[0]=1;
        directions[0]=0;
        int max_res=0;
        for(int i=1;i<n;++i){
            int max_pre_idx=-1;
            int max_len=0;//前缀子串长度
            int direx=0;
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i]&&directions[j]!=1){
                    if(max_len<dp[j]){
                        max_len=dp[j];
                        max_pre_idx=j;
                        direx=1;
                    }
                }
                else if(nums[j]>nums[i]&&directions[j]!=2){
                    if(max_len<dp[j]){
                        max_len=dp[j];
                        max_pre_idx=j;
                        direx=2;
                    }
                }
            }
            if(max_pre_idx!=-1){
                dp[i]=max_len+1;
                directions[i]=direx;
            }
            else
            {
                dp[i]=1;
                directions[i]=0;
            }
            max_res=max(max_res,dp[i]);
        }
        return max_res;
    }
};
```
