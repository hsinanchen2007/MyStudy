### 解题思路
 
 1 交换左右子树的地址
 2 递归调用交换后的左右子结点，继续交换左右子结点的左右子结点的地址
 3 递归终止条件：当结点地址为空时终止递归
 
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
        if (root==NULL) {
            return NULL;
        }

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};
```