### 解题思路
此处撰写解题思路
dp数组是一个严格递增的序列;
dp[i]代表包括第i+1个元素的前i+1元素中的递增子序列的末尾元素值；
如nums[3] = {2,3,2,4},相应的dp是
{2}
{2,3}
{2,3}
{2,3,4}
最后的dp的长度就是答案

时间复杂度是O（nlog2n）
空间复杂度是O（n）
### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int>dp;
        //dp[i]代表包括第i+1个元素的前i+1元素中的递增子序列的末尾元素值；
        dp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i) {
            //lower_bound找出第一个大于等于nums[i]的元素位置
            int index = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            //dp数组中找到第一个大于等于nums[i]的元素位置
            if(index < dp.size()) {
                dp[index] = nums[i];  //更新元素值
            }
            //nums[i]大于dp数组中的所有元素，则dp尾部加入元素nums[i]
            else dp.push_back(nums[i]);
        }
        return dp.size();
    }
};
```