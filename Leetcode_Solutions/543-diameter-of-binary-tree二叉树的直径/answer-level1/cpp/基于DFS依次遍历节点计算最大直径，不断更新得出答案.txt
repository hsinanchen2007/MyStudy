### 解题思路


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
    int max_dia=0;
    int dfs(TreeNode*root)//计算树最大直径
    {
        if(root==nullptr)
            return 0;
        int level_l=dfs(root->left);
        int level_r=dfs(root->right);
        max_dia=max(max_dia,level_l+level_r);
        return max(level_l,level_r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return max_dia;
    }
};
```