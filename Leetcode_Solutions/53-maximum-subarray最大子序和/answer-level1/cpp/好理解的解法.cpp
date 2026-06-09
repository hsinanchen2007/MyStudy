```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int minsum=0;
        int asum=0;
        int maxd=INT_MIN;
        for(int i=0;i<nums.size();i++){
            asum=asum+nums[i];
            maxd=max(maxd,asum-minsum);
            minsum=min(minsum,asum);
        }
        return maxd;
    }
};
```
