### 解题思路
此处撰写解题思路

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
private:
    TreeNode* helper(TreeNode* root) {
        if (!root) return root;
        // 暂存右子树
        TreeNode* right = root->right;
        // 递归左子树，将左子树的结果接在root结点的右侧
        root->right = helper(root->left);
        root->left = NULL;
        // 如果root之前存在右子树
        // 递归右子树结点，接在左子树结果的后面
        if (right) {
            TreeNode* node = root;
            while (node->right) node = node->right;
            node->right = helper(right);
        }
        return root;
    }

public:
    void flatten(TreeNode* root) {
        helper(root);
    }
};
```