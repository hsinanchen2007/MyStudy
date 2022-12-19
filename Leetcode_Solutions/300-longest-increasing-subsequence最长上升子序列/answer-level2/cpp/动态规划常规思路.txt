用一次遍历出错了，有部分测试用例无法通过。
还是只能用动态规划，求dp[0],dp[1]...
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        map<int,int> m;
        m[nums[0]]=1;
        int re=1;
        for(int i=1;i<nums.size();++i){
            int tmp=INT_MIN,dp=0;
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i] && m[nums[j]]>dp) {
                    tmp=nums[j];
                    dp=m[nums[j]];
                }
            }
            m[nums[i]]=dp+1;
            re=max(re,m[nums[i]]);
        }
        return re;
    }
};
```
