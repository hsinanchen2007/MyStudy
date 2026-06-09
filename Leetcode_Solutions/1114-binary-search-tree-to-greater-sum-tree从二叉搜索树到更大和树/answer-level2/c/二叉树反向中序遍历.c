/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int n;
void ReverseInOrder(struct TreeNode *root) {
    if (root != NULL) {
        ReverseInOrder(root->right);
        root->val += n;
        n =  root->val;
        ReverseInOrder(root->left);
    }
}

struct TreeNode* bstToGst(struct TreeNode* root){
    n = 0;
    ReverseInOrder(root);
    return root;
}