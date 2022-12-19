借助一个数组，通过大小限制数组的长度，最后数组的长度即为最长上身子序列

```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 1;
        if(n == 0) {
            return 0;
        }
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i = 1; i < n; i++) {
            
            //如果当前元素大于数组最大元素，加入数组
            if(nums[i] > dp[dp.size() - 1]) {
                dp.push_back(nums[i]);
                continue;
            }
            //如果当前元素小于等于最小元素，替换最小的元素
            if(nums[i] <= dp[0]) {
                dp[0] = nums[i];
                continue;
            }
            //找到大于当前等于当前元素的最小索引位置，将其赋值为当前元素
            int l = 0, r = dp.size() - 1;
            while(l < r) {
                int mid = l + (r - l + 1) / 2;
                if(dp[mid] >= nums[i]) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            dp[l+1] = nums[i];

        }
        //数组的长度即为最长上升子序列
        return dp.size();
    }
};
```
