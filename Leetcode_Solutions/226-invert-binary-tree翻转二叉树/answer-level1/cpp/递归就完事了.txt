### 解题思路
递归就完事了，注意不要写成这样就行。
Tree->right = invertTree(root->left);
Tree->left = invertTree(root->right);


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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;

        TreeNode *Tree = root;
        TreeNode *right = invertTree(root->right);
        TreeNode *left = invertTree(root->left);
        Tree->left = right;
        Tree->right = left;
        
        return Tree;
    }
};
```