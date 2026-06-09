### 解题思路


### 代码

```cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        DFS(nums, 1, S, nums[0]);
        DFS(nums, 1, S, -nums[0]);
        return ans;
    }
    void DFS(vector<int>& nums, int ind, int S, int sum)
    {
        if(ind == nums.size())
        {
            if(sum == S)
                ans++;
            return ;
        }
        DFS(nums, ind + 1, S, sum + nums[ind]);
        DFS(nums, ind + 1, S, sum - nums[ind]);
    }
private:
    int ans = 0;
};
```