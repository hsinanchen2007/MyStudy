![image.png](https://pic.leetcode-cn.com/9b5582a610a6437e60ade8911ff6b3c3482c41d91f92223c150b42a1809c9ff7-image.png)

总之就是每次最贪心覆盖

```
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <=1) return 0;
        int dp[nums.size()];
        memset(dp,0,sizeof(dp));
        int basic = 0;
        int localmax = nums[0];
        int i=0;
        while(i<nums.size()){
            int nextmax = 0;
            while(i<=localmax and i<nums.size()){
                dp[i] = basic + 1;
                nextmax = max(nums[i]+i,nextmax);
                i++;
            }         
            localmax = nextmax;
            basic ++;
        }
        return dp[nums.size()-1];
    }
};
```
