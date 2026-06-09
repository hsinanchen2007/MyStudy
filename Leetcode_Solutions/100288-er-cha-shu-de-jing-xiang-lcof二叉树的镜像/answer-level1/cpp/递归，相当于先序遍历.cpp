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
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root)return nullptr;
        swap(root->left, root->right);  //对根节点操作
        root->left = mirrorTree(root->left);  //对左子树操作
        root->right = mirrorTree(root->right);  //对右子树操作
        return root;
    }
};
```