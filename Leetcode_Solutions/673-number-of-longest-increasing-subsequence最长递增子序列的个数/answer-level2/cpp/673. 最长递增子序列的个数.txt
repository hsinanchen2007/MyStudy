### 解题思路
面向测试用例，来来回回改了一个多小时，终于过了

### 代码

```cpp
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);//记录上升子序列的个数
        vector<int>cnt(n,1);//记录从头到当前位置，最大子序列的个数
        int maxn=0,count=0;
        int res=0;
        for(int i=0;i<n;i++){
        	count=0;
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    if(dp[i]<dp[j]+1){
                    	dp[i]=dp[j]+1;count=0;//如果dp[i]更新，则要重新计数，因为之前的都不是最长
					}
                    if(dp[j]+1==dp[i]) count+=cnt[j];
                } 
            }
			maxn=max(maxn,dp[i]);
            if(count>1) cnt[i]=count;//只有count修改了才更新
        }
        if(maxn==0) return n;
        for(int i=0;i<cnt.size();i++) if(dp[i]==maxn) res+=cnt[i];
        return res;
    }
};
```