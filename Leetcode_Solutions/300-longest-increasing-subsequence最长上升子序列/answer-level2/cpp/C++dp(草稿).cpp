### 解题思路
这道题与最大整除子集很相像但是不用排序

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 采用二分查找处理(0, i)上的上升子序列
        // O(n^2)
        // dp[i]记录以该点为结尾得最长上升子序列长度
        // 初始化为1
        // nums[j] > nums[i] && dp[j] <= dp[i]
        int len = nums.size();
        vector<int> dp(len, 1);
        int rst = 0;
        for(int i=0; i<len; ++i)
        {
            for(int j=0; j<i; ++j)
            {
                if(nums[i] > nums[j] && dp[i] < dp[j]+1) dp[i] = dp[j]+1;
            }
            rst = max(rst, dp[i]);
        }
        return rst;
    }
};
```