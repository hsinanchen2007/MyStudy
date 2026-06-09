```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool Deep(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    int n1 = 1 + Deep(root->left);
    int n2 = 1 + Deep(root->right);
    return abs(n1-n2) < 2;

}
bool isBalanced(struct TreeNode* root)
{
    if(root == NULL)
        return true;
    return  Deep(root) && isBalanced(root->left) && isBalanced(root->right);
}
```
