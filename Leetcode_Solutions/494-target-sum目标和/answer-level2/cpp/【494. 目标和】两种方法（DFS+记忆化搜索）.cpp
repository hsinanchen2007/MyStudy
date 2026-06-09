## 思路一：DFS
### 代码
时间复杂度：O(2^n)
```c++
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0, sum = 0;
        dfs(nums, S, 0, sum, res);
        return res;
    }

    void dfs(vector<int>& nums, int S, int i, int sum, int& res) {
        if (i == nums.size()) {
            if (sum == S) {
                ++res;
            }
            return;
        }                
        dfs(nums, S, i + 1, sum + nums[i], res);
        dfs(nums, S, i + 1, sum - nums[i], res);        
    }
};
```
#### 另一种写法
有点类似树形dp，分别向左右两种情况要满足条件的数目。
```c++
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {        
        return dfs(nums, S, 0, 0);
    }

    int dfs(vector<int>& nums, int S, int i, int sum) {
        if (i == nums.size()) {
            return S == sum ? 1 : 0;
        }                
        return dfs(nums, S, i + 1, sum + nums[i]) + dfs(nums, S, i + 1, sum - nums[i]);        
    }
};
```

## 思路二：记忆化搜索
memo[i][s]：表示到第i个数和为s的情况总数。
**注意：在目标和S上加或减可能超出整数范围，使用long int**
### 代码
```c++
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {       
        vector<unordered_map<int, int>> memo(nums.size()) ;
        return dfs(nums, S, 0, memo);
    }

    int dfs(vector<int>& nums, long int S, int i, vector<unordered_map<int, int>>& memo) {
        if (i == nums.size()) return S == 0;
        if (memo[i].count(S) > 0) return memo[i][S];
        return memo[i][S] = (dfs(nums, S - nums[i], i + 1, memo) + dfs(nums, S + nums[i], i + 1, memo));        
    }
};
```




