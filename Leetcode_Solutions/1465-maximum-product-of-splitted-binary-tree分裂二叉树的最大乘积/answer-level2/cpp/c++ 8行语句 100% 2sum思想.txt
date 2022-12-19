之前复杂化了 存一个 prev 变量表示从上面传下来的和, 会爆栈

改成总和-当前和就行了

```
class Solution {
public:
    int maxProduct(TreeNode* rt) {
        unordered_map<TreeNode *, long long> sum;
        long long ans = -1, MOD = 1e9 + 7, all_sum = helper(rt, sum);;
        for (auto &[p, s] : sum) {
            ans = max(ans, (all_sum - s) * s);
        }
        return ans % MOD;
    }
    long long helper(TreeNode *rt, unordered_map<TreeNode *, long long> &sum) {
        if (!rt) return 0;
        return sum[rt] = rt->val + helper(rt->left, sum) + helper(rt->right, sum);
    }
};
```
unordered_map可以进一步优化 换成 unordered_set, vector 等等