### 解题思路
自底向上

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return dfs(root, depth);
    }

    bool dfs(TreeNode* root, int& depth)
    {
        if(!root) return true;
        int ld = 0, rd = 0;
        if(!dfs(root->left, ld) || !dfs(root->right, rd) || abs(ld - rd) > 1) return false;
        depth = max(ld,rd) + 1;
        return true;
    }
};
```