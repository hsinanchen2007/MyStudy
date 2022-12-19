### 思路一：记忆化搜索
对于每个节点root，通过递归找最大值
- 如果取这个节点，则左右节点都不能取，如果左节点（root->left）存在，则递归求其左节点的左孩子（root->left->left）和右孩子（root->left->right）；同理，如果右节点（root->right）存在，则递归求其右节点的左右孩子（root->right->left和root->right->right）。
- 如果不取这个节点，则递归求其左节点和右节点最大值。

### 代码

```cpp
class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> ump;
        return dfs(root, ump);
    }

    int dfs(TreeNode *root, unordered_map<TreeNode*, int> &ump) {
        if (!root) return 0;
        if (ump.count(root) > 0) return ump[root];
        int val = 0;
        if (root->left) {
            val += dfs(root->left->left, ump) + dfs(root->left->right, ump);
        }
        if (root->right) {
            val += dfs(root->right->left, ump) + dfs(root->right->right, ump);
        }
        val = max(root->val + val, dfs(root->left, ump) + dfs(root->right, ump));
        ump[root] = val;
        return val;
    }
};
```