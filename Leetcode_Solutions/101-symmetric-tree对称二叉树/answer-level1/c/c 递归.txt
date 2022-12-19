/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetriclr(struct TreeNode* left, struct TreeNode* right)
{  
    if (!left && !right) return true;
    if (!left || !right) return false;
    if (left->val != right->val) return false;
    return ((isSymmetriclr(left->left,right->right)) && (isSymmetriclr(left->right,right->left)));

}

bool isSymmetric(struct TreeNode* root){
    if (!root) return true; 
    return isSymmetriclr(root->left,root->right);
  
}