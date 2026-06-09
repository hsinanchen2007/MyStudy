### 解题思路
关键是保存临时的子节点，root->left=invertTree(root->right);这个过程会把root->left更改。

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
    TreeNode* invertTree(TreeNode* root) 
    {
        if (!root)
        {
            return root;
        }
        TreeNode *tmpLeft = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmpLeft);
        return root;
    }
};
```