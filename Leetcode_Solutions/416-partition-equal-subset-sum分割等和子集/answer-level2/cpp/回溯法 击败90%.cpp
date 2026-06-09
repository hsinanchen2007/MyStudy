### 解题思路
回溯法，visited记录nums中每个元素是否被访问过。不过只有这个会超时。
visitedsum记录曾经计算过的和。如果之前计算过就不在重复计算了。

### 代码

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto n : nums)
        {
            sum += n;
        }
        if(sum % 2) return false;
        vector<bool>visited(nums.size(),false);
        map<int,int>visitedsum;
        sort(nums.begin(),nums.end());
        return dfs(nums,sum / 2,visited,visitedsum);
    }
    bool dfs(vector<int>& nums,int sum,vector<bool>&visited,map<int,int>&visitedsum)
    {
        if(sum == 0) return true;
        for(int i = 0;i < nums.size();i++)
        {
            int m = sum - nums[i];
            if(visited[i] || visitedsum[m] == 1 || m < 0) continue;
            else if(m == 0) return true;
            visited[i] = true;
            visitedsum[m] = 1;
            if(dfs(nums,m,visited,visitedsum))
                return true;
            visited[i] = false;
        }
        return false;
    }
};
```