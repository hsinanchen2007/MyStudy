### 解题思路
DFS

### 代码
```
class Solution {
public:
    //#Brute Force# #DFS#
    int findTargetSumWays(vector<int>& nums, int S) {
        ways = 0;
        findTargetSumWay(nums, 0, 0, S, true);
        findTargetSumWay(nums, 0, 0, S, false);
        return ways;
    }

private:
    void findTargetSumWay(vector<int>& nums, int depth, int sum, int& S, bool opt){
        if(opt == true)
            sum += nums[depth];
        else
            sum -= nums[depth];
        if(depth == nums.size()-1){
            if(sum == S){
                ways++;
            }
            return;
        }
        findTargetSumWay(nums, depth+1, sum, S, true);
        findTargetSumWay(nums, depth+1, sum, S, false);
    }
    int ways;
};
```





### 解题思路
DP
![image.png](https://pic.leetcode-cn.com/140576e6708704cb96ffc44ae7ab21d856d8890ffbdb4f1314fd42289f4364e9-image.png)
附一个别人的代码，但是递推公式没有看明白（和官方题解相同）：
https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-494-target-sum/

### 代码

```cpp
class Solution {
public: 
    //#DP# #可以转化为背包问题?#
    //dp[i][j]: 前i个数组成和j的方法数
    //dp[i][j] = dp[i-1][j-nums[i]] + dp[i-1][j+nums[i]]
    //需要处理j-nums[i]为负值的情况，需要处理[j+/-nums[i]]越界问题
    //初始化dp[0][offset]的时候需要注意第一个数nums[0]是否为0
    int findTargetSumWays(vector<int>& nums, int S) {
        int size = nums.size();
        int sum = 0;
        for(int v : nums){
            sum += v;
        }
        if(size == 1 && sum != abs(S) || sum < abs(S)){
            return 0;
        }
        int offset = sum;
        vector<vector<int>> dp(nums.size(),vector<int>(2*sum+1, 0));
        if(nums[0] == 0) dp[0][offset] = 2;
        else{
        dp[0][offset + nums[0]] = 1;
        dp[0][offset - nums[0]] = 1;
        }
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j <= 2*sum; j++){
                dp[i][j] = (j-nums[i] >= 0 ? dp[i-1][j-nums[i]] : 0) + (j + nums[i] <= 2*sum ? dp[i-1][j + nums[i]] : 0);
            }
        }
        return dp[size-1][offset+S];
    }
};
```