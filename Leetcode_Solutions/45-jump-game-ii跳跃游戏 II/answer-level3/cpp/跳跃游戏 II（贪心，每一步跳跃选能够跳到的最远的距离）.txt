### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {  //降阶法，虽然会超时，但是也是一个好的思路。。。
public:           //真正的解法是贪心
        int jump(vector<int>& nums) { 
            int end=0,len=0,step=0;
            for(int i=0;i<nums.size()-1;i++){
                len=max(len,nums[i]+i);
                if(len>=nums.size()-1) { //稍微优化了一下，以前退出。。
                    step++;
                    break;   
                } 
                if(i==end){
                    end=len;
                    step++;
                } 
                   
             }
          return step;
        }

   /* int jump(vector<int>& nums) {  //这个思路时间可能会超时，时间复杂度为O（n^2), 所以可能要使用贪心。。
        //状态转移方程：dp[i]=min(dp[x]) i<x<=i+nums[i]  dp[i]含义：i位置到最后一个位置最少的次数
        if(nums.size()==0) return 0;
        int len=nums.size();
        int dp[len];
        //memset(dp,1000,sizeof(dp));????????????
        for(int i=0;i<len;i++) dp[i]=INT_MAX;
        dp[len-1]=0;
        for(int i=len-2;i>=0;i--){
            for(int j=i+1;j<len&&j<=i+nums[i];j++){
                if(dp[j]>=0)  dp[i]=min(dp[i],dp[j]);
            }
            if(dp[i]==INT_MAX) dp[i]=-1;
            else dp[i]++;
        }
        return dp[0]; 
    }
    */
};
```