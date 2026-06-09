### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> memo;
    bool tryPartition(vector<int>& nums, int index, int sum) {
        if(index < 0 || sum < 0)
            return false;
        if (sum==0)
            return true;

        if (memo[index][sum]!=-1)
            return memo[index][sum]==1;
        memo[index][sum] = (tryPartition(nums, index-1,sum)
                            ||tryPartition(nums,index-1,sum-nums[index])) ? 1:0;

        return memo[index][sum]==1;
    }
    bool canPartition(vector<int>& nums) {
        if (nums.empty())
            return true;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        }
        memo = vector<vector<int>>(nums.size(),vector<int>(sum/2+1,-1));
        return tryPartition(nums, nums.size()-1, sum/2);


    }
};
```