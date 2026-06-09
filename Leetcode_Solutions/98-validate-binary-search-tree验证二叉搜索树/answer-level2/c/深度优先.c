参考了其人的他题解
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool dfs(struct TreeNode* root, long min, long max) 
{
    if (root == NULL) {
        return true;
    }

    if (root->val <= min || root->val >= max) return false;
    
    bool ret;
    ret = dfs(root->left, min, root->val);
    if (ret == false) {
        return false;
    }

    ret = dfs(root->right, root->val, max);
    if (ret == false) {
        return false;
    }
    
    return true;
}


bool isValidBST(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }

    return dfs(root, LONG_MIN, LONG_MAX);

}