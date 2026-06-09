![377](https://pic.leetcode-cn.com/852288577e6bf8d9fe7fae6d5e64e004566612ed0455aacd6aab8083deaf9b4c-377.PNG)

### 解题思路
动态规划。
定义状态memo[i]表示取走一个数后和为i有几种方式，状态转移方程：$memo[i] = \sum_{j=1}^{nums.size()}memo[i - nums[j]]$

### 代码

```cpp
typedef unsigned long long ull;
class Solution {//memo(i)表示取走一个数后和为i有几种方式
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.size() == 0)return 0;
        vector<ull>memo(target + 1, 0);
        memo[0] = 1;//注意这句代码的含义
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i - nums[j] >= 0)
                    memo[i] += memo[i - nums[j]];
            }
        }
        return memo[target];
    }
};
```