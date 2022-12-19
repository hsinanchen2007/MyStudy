/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode* root){
    int d1, d2;

    if(root == NULL)
    {
        return 0;
    }
    else
    {
        if((root->left == NULL) && (root->right == NULL))
        {
            return 1;
        }
        else if((root->left == NULL) && (root->right != NULL))
        {
            return minDepth(root->right) + 1;
        }
        else if((root->left != NULL) && (root->right == NULL))
        {
            return minDepth(root->left) + 1;
        }
        else
        {
            d1 = minDepth(root->left);
            d2 = minDepth(root->right);

            return (d1 < d2 ? d1 : d2) + 1;
        }
    }
}