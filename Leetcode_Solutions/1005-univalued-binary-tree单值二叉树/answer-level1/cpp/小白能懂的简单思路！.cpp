### 解题思路
1.先跟左节点比较
2.再跟右节点比较
3.递归

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
   
    bool isUnivalTree(TreeNode* root) {
         if (root == NULL) {
            return true;
        }
        if (root->left != NULL && root->val != root->left->val) {
            return false;
        }
        if(root->right != NULL && root->val != root->right->val) {
            return false;
        }
        return isUnivalTree(root->left) && isUnivalTree(root->right);

    }
};
```