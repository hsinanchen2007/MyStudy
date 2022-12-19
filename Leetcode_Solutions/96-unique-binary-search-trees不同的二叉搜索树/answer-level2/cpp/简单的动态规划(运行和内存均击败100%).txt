### 解题思路
备忘录形式的动态规划，空间复杂度为O(n)，memo[i]中表示以1...i为节点组成的二叉搜索树总数，状态转移方程为：
memo[i] = \Sigma_{j=1}^{j=i} (memo[j-1]*memo[i-j]); (解释：第j项表示以j为根节点，左子树个数为：memo[j-1]；右子树个数为memo[i-j]，相乘即为以j为根节点且数总节点数为i的二叉搜索数种数)。

### 代码

```cpp
class Solution {
public:
    int numTrees(int n) {
        if (n <= 2) return n;
        int memo[n+1] = {0};
        memo[0] = 1;
        memo[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                memo[i] += (memo[j-1]*memo[i-j]);
            }
        }
        return memo[n];
    }
};
```