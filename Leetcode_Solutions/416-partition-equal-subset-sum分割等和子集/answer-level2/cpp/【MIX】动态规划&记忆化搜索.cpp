### 解题思路
可以转化为背包问题, 使用动态规划或者记忆化递归求解

### 代码

**动态规划**
```java []
class Solution {
    public boolean canPartition(int[] nums) {
        // 动态规划
        // dp[i]表示是否存在和为i的组合
        int n = nums.length;
        if(n<=1)
            return false;

        int sum = 0x00;
        for(int i=0; i<n; ++i)
            sum += nums[i];

        if(sum % 2==1)
            return false;
        
        int C = sum>>1;
        boolean []dp = new boolean[C+1];
        // 初始化 : 仅使用元素nums[0]
        for(int i=0; i<=C; ++i)
            dp[i] = (nums[0]==i);

        // 更新dp, 添加新元素的使用
        for(int i=1; i<n; ++i)
            for(int j=C; j>=nums[i]; --j)
                dp[j] = dp[j] || dp[j-nums[i]];

        return dp[C];
    }
}
```
```python []
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        # 动态规划
        # dp[i]表示存在和为i的组合
        N = len(nums)
        S = sum(nums)
        if S & 0x01:
            return False
        C = S//2

        dp = [False for _ in range(C+1)]
        for i in range(1, C+1):
            dp[i] = (nums[0]==i)

        for i in range(1, N):
            for j in range(C, nums[i]-1, -1):
                dp[j] = dp[j] or dp[j-nums[i]]

        return dp[C]
```
```c++ []
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 动态规划
        if(nums.size() <=1)
            return false;
        auto Sum = accumulate(nums.begin(), nums.end(), 0);
        if(Sum & 0x01)
            return false;

        int C = Sum>>1;

        // dp[i]表示和为i的组合是否存在
        vector<bool> dp(C+1, false);
        for(int i=0; i<=C; ++i)
            dp[i] = (nums[0] == i);
        for(int i=1; i<nums.size(); ++i)
            // 更新dp数组, 更新规则：dp[j]存在或者nums[i]+dp[j-nums[i]]存在
            for(int j=C; j>=nums[i]; --j)
                dp[j] = dp[j] || dp[j-nums[i]];
        return dp[C];
    }
};
```
```c++ []
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 背包问题
        int Sum = accumulate(nums.begin(), nums.end(), 0);
        if(Sum & 0x01)
            return false;

        int C = Sum/2;

        // 问题划归：nums中的数值能都拼出C --> 背包型DP
        // f[i][j], 使用前i个数, 能否拼出值j
        int N = nums.size();
        vector<vector<bool>> f = vector<vector<bool>>(N+1, vector<bool>(C+1, false));
        f[0][0] = true;

        for(int i=1; i<=N; ++i)
            for(int j=0; j<=C; ++j){
                f[i][j] = f[i-1][j];
                if(j >= nums[i-1])
                    f[i][j] = f[i][j] || f[i-1][j-nums[i-1]];
            }

        return f[N][C];
    }
};
```

**记忆化递归**
```java []
class Solution {
    public boolean canPartition(int[] nums) {
        // 记忆化递归
        if(nums.length<=1)
            return false;
        int sum = 0x00;
        for(int i=0; i<nums.length; ++i)
            sum += nums[i];

        if(sum % 2 == 1)
            return false;
        int C = sum>>1;
        // 初始化记录
        memo = new int[C+1][nums.length];
        for(int i=0; i<=C; ++i)
            for(int j=0; j<nums.length; ++j)
                memo[i][j] = -1;
        return knapsack(nums, nums.length-1, C);
    }

    // 在nums[0...index]中是否存在和为C的组合
    private boolean knapsack(int []nums, int index, int C){
        if(C == 0)
            return true;
        if(index < 0 || C < 0)
            return false;
        if(memo[C][index] != -1)
            return memo[C][index]==1;

        memo[C][index] = (knapsack(nums, index-1, C) || knapsack(nums, index-1, C-nums[index]))?1:0;
        return memo[C][index]==1;
    }

    // 记录表: -1表示未计算， 0不存在, 1表示存在
    private int [][]memo;
}
```
```python []
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        # 记忆化递归
        N = len(nums)
        if N <= 1:
            return False
        S = sum(nums)
        if S & 0x01:
            return False
        C = S//2
        # 记录表, -1表示未计算, 0表示不存在, 1表示组合存在
        self.memo = [[-1 for _ in range(N)] for _ in range(C+1)]

        return self.knapsack(nums, N-1, C)

    # nums[0...index]中是否存在和为C的组合
    def knapsack(self, nums, index, C):
        if C == 0:
            return True
        if index < 0 or C < 0:
            return False

        if self.memo[C][index] != -1:
            return self.memo[C][index]

        self.memo[C][index] = self.knapsack(nums, index-1, C) or self.knapsack(nums, index-1, C-nums[index])
        return self.memo[C][index]

```
```c++ []
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 背包问题的变种-->在n个数字中选出部分数字, 使得其和为sum/2
        // 记忆化递归
        if(nums.size() <= 1)
            return false;
        int Sum = accumulate(nums.begin(), nums.end(), 0);
        if(Sum & 0x01)
            return false;
        int C = Sum/2;
        
        memo = vector<vector<int>>(nums.size(), vector<int>(C+1, -1));
        // 设置状态转移方程 F(i, C) = F(i-1, C) || F(i-1, C-w(i))
        return knapsack(nums, nums.size()-1, C);
    }

private:
    // 返回nums中从[0...index]是否存在和为C的数
    bool knapsack(const vector<int> &nums, int index, int C){
        if(C == 0)
            return true;
        if(C < 0 || index < 0)
            return false;
        if(memo[index][C] != -1)
            return memo[index][C];
        memo[index][C] = knapsack(nums, index-1, C) || knapsack(nums, index-1, C-nums[index]);
        return memo[index][C];
    }

private:
    // memo[i][c]表示使用索引为[0...i]的元素, 是否可以完全填充一个容量为C的背包
    // -1表示未计算, 0表示不可以填充, 1表示可以填充
    vector<vector<int>> memo;
};
```