# 思路

看清楚题目，是子路径不是子树！！！
前缀和 + 回溯

复杂度：
时间复杂度：O(n)
空间复杂度：O(logn)

# 代码(C++)
```cpp
class Solution {
public:
    unordered_map<int, int> accu;
    int target, ans = 0;
    void helper(TreeNode* node, int sum) {
        if (node == nullptr) return;
        sum += node->val;
        if (accu[sum - target]) ans += accu[sum - target];
        accu[sum]++;
        helper(node->left, sum);
        helper(node->right, sum);
        accu[sum]--;
    }
    int pathSum(TreeNode* root, int t) {
        target = t, accu[0] = 1;
        helper(root, 0);
        return ans;
    }
};
```