# 222. 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        if(root != NULL)
        	return ((root->left==NULL)?0:countNodes(root->left))+((root->right==NULL)?0:countNodes(root->right))+1;
        else
        	return 0;
    }
};
```
