如果有看过01背包问题的同学，看到这个题目第一印象应该都觉得应该用动态规划做，问题是如何确定状态转移方程。
仿照01背包问题，首先定义一个二维数组f[i][j]，其物理意义为：
    ***前 i个数中，可以有一种取数方式，使取到的数之和为 j, 如果存在这样一个数则 f[i][j] = true***
如果f[i][j]有了这个物理意义，那么如何确定状态转移方程呢?
还是仿照 0 - 1背包问题，如果存在前 i 个数中有一种方式使得被选中数字之和为 j, 则对于第i个数，可以选或者不选，
 - 如果选中第 i 个数，则有前 i - 1 个数中有一种方式可以让选中数之和为 j - nums[i]，即 f[i - 1][j - nums[i]] = true;
 - 如果不选择第 i 个数，则前 i - 1 个数中存在一种方式可以让选中数之和为 j, 即 f[i - 1][j] = true
 - 上述两种方式无论哪种成立都可以使f[i][j] = true，所以有 f[i][j] = f[i - 1][j - nums[i]] || f[i - 1][j]
 
这里还需要注意的一点是，数组中可能存在一个数大于目标数 j，这样会我们 j - nums[i] < 0，造成越界，对于这种情况，我们从实际物理意义出发，如果有一个数大于目标数j，说明如果选择这个数，则被选中数之和肯定会大于目标数，所以不能选，所以有：
 - if (j < nums[i]) f[i] = f[i - 1][j]
 意义为：前i - 1个数中已经存在一种选择方式使得被选中数之和为j。

这里要把f[i][0]都先赋值为true，物理意义为无论在前 i 个数中怎么选择，始终存在一种**都不选**的方式使得f[i][0] = true
```
class Solution {
public:
    /**
     * 这个问题的i为取前多少数, j为当前取值的之和, t为目标和
     * @param nums
     * @return
     */
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum & 1) return false;
        int t = sum / 2;
        vector<vector<bool>> f(n + 1, vector<bool>(t + 1));
        for (int i = 0; i <= n; ++i) f[i][0] = true;
        for (int i  = 1; i <= n; i++) {
            for (int j = nums[0]; j <= t; j++) {
                if (j - nums[i - 1] < 0) f[i][j] = f[i - 1][j];
                else f[i][j] = f[i - 1][j] || f[i - 1][j - nums[i - 1]];
            }
        }
        bool res = false;
        for (int i = 0; i <= n; ++i) res = res || f[i][t];
        return res;
    }
};
```

可以进一步将二维数组降维，对于每一个i循环，f[j]就是原来的f[i][j],在计算f[j]的值时，由于f[j]所需要的值还没有被这一步的计算值所替换掉，所以可以直接用。

```
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum & 1) return false;
        int t = sum / 2;
        vector<bool> f(t + 1);
        f[0] = true;
        for (int i  = 1; i <= n; i++) 
            for (int j = t; j >= nums[0]; j--)
                if (nums[i - 1] <= j) f[j] = f[j - nums[i - 1]] || f[j];
        return f[t];
    }
};
```

动态规划问题有点类似于高中时候做的那种数列的求通项公式的题目，有n 和 n + 1之间的关系，然后初始条件要弄对。还有，对于动态规划问题要给一个合理的物理意义，这样才能把题目做对，也方便自己理解。

