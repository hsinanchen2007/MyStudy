用两个变量来进行滚动的动态规划。
cur'表示目前以nums[i]结尾的前i个元素的最大子序和，pre表示前i-1个元素的最大子序和，result是保留过程是以i结尾的最大子序和的最大值，也就是整个数组的最大子序和。
```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MIN,pre = 0;
        for(int i = 0;i<n;i++)
        {
            int cur = max(pre+nums[i],nums[i]);
            result = max(result,cur);
            pre = cur;
        }

        return result;
    }
};
```
