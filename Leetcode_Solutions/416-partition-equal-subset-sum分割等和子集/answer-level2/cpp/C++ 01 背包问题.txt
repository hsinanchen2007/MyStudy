### 解题思路
这是个典型的背包问题， 即要找到 i 个物品将容量为 sum(nums)/2 的背包完全填满（注意是完全填满）， 其中 i ∈ [0, nums.size() - 1]
能够拆成两个和相同的子集， 那么每个子集的和就为 sum(nums)/2 ， 也就是说如果可以选出 i 个物品， 让这 i 个物品的和为 sum(nums)/2 那么此题就有解. 
动态转移方程为：
`f(n, c) = f(n-1, c) || f(n-1, c - nums[n]) `
f(n, c) 表示nums[0: n] 中是否存在组合其和为 c, 本题 c 为 sum(nums)/2， n 为 nums.size()

f(n-1, c) || f(n-1, c - nums[n]) 表示:
- `f(n-1, c) `: 如果考虑 nums 中  [0, n-1] 个数字的时候， 就发现存在和为 c 的组合， 那么只要索引第 n 个数值不参与求和计算， [0, n] 个数值中就可以找到和为 c 的组合 
- `f(n-1, c - nums[n]) `:如果考虑 nums 中 [0, n-1] 个数字的时候,  没有发现存在和为 c 的组合， 但是发现了和为 c - nums[n]的组合， 那么只要索引第 n 个数值参与求和计算， [0, n] 个数值中就可以找到和为 c 的组合

### 代码

```cpp

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += nums[i];
        if(sum % 2 != 0) // 能分成相等的两份， 数组总和一定是偶数
            return false;

        vector<bool> memo(sum + 1, false); // memo[i] 表示是否存在和为 i 的组合， i ∈ [0, sum(nums)/2]
        sum /= 2;
        for(int i = 0; i <= sum; i++){// 只考虑第一个元素， 那么也就是 nums[0] == i 代表存在
            memo[i] = nums[0] == i;
        }
           
        for(int i = 1; i < n; i++)
            for(int j = sum; j - nums[i] >= 0; j--)
                memo[j] = memo[j] || memo[j - nums[i]];

        return memo[sum];
    }
};
```