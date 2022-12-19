### 解题思路
这道题思路比较简单。首先处理数组为空或只有一个数的情况。然后创建一个大小为nums数组大小的dp数组，用于存放连续序列的长度。dp[0]显然为1，若相邻元素相差1，说明连续，dp递增；若相邻元素相等，dp不变；若相邻元素不等，说明不连续，dp重新计1.最后返回dp数组的最大值即为题解。
![QQ截图20200207153739.png](https://pic.leetcode-cn.com/5b885c10b58d481b95be1f2e49dfc37b5eaed1375db556be85714df9699af2c9-QQ%E6%88%AA%E5%9B%BE20200207153739.png)

### 代码

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 0);
        if(nums.size()==1)
            return 1;
        dp[0] = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1)
                dp[i] = dp[i-1]+1;
            else if(nums[i] == nums[i-1])
                dp[i] = dp[i-1];
            else
                dp[i] = 1;
        }
        auto maxPosition = max_element(dp.begin(), dp.end());
        return *maxPosition;
    }
};
```