### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        int *dp=(int*)malloc(n*sizeof(int));
        memset(dp,0,n*sizeof(int));
        dp[0]=1;
        int ans=1;
        for(int i=1;i<n;++i){
            int aans=1;
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j])aans=max(aans,dp[j]+1);
            }
            dp[i]=aans;
            ans=max(aans,ans);
        }
        return ans;
    }
};
```