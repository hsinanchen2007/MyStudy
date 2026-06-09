思路：
1. 题中已说明叶子节点是指没有子节点的节点。即左右节点均为 NULL 时，满足`叶子节点`要求。
2. 每经过 1 个节点，在路径和上减去该节点 val 值，当 sum 为 0 时，满足`目标和`要求。
3. 综合以上两条，即为返回 true 的条件，简单递归左右子树即可。

```C
bool hasPathSum(struct TreeNode* root, int sum){
    if (!root) return false;
    sum = sum - root->val;
    // 左右节点均为 NULL ，且 sum 为 0 时, 满足条件
    if (!root->left && !root->right && !sum) return true;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}
```
