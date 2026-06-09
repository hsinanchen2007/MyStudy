
```
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
    int minDepth(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        int count = 1;
        if ((root->left != NULL && root->right == NULL) || 
            (root->left == NULL && root->right != NULL) ) {
            return count += max(minDepth(root->left), minDepth(root->right));
        }
        return count += min(minDepth(root->left), minDepth(root->right));
    }
};
```

当只有左树或右树时，累加左子树或右子树深度；否则累加左子树或右子树的最小深度