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
    
    bool symmetricBinaryTree(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;
        else if(root1 == NULL || root2 == NULL)
            return false;
        else
        {
            if(root1->val != root2->val)
                return false;
            else
            {
                // 镜像：树1的左孩子的值 == 树2的右孩子的值，树1的右孩子的值 == 树2的左孩子的值
                bool leftFlag = symmetricBinaryTree(root1->left,root2->right);
                bool rightFlag = symmetricBinaryTree(root1->right,root2->left);
                return leftFlag && rightFlag;
            }
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        else
            return symmetricBinaryTree(root->left, root->right);
    }
};

```