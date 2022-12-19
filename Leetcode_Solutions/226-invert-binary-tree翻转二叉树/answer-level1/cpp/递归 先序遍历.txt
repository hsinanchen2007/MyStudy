### 解题思路
递归 先序遍历
时间百分百

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
            return root;
        else {
            if (root->left != NULL || root->right != NULL) {
                TreeNode* temp;
                temp = root->left;
                root->left = root->right;
                root->right = temp;
                if (root->left != NULL)
                    invertTree(root->left);
                if (root->right != NULL)
                    invertTree(root->right);
            }
            return root;
        }
    }
};
```