/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



int find(struct TreeNode* root, int Min, int Max){

    int ret = 0;
    if (root == NULL) {
        return 0;
    }
    
    if (root->left != NULL) {
        if (Max != -1 && root->left->val <= Max) {
            return 1;
        }
        if (root->left->val < root->val) {
            ret += find(root->left, root->val, Max);
        } else {
            return 1;
        }
    }

    if (root->right != NULL) {
        if (Min != -1 && root->right->val >= Min) {
            return 1;
        }

        if (root->right->val > root->val) {
            ret += find(root->right, Min, root->val);
        } else {
            return 1;
        }
    }
    
    return ret;
}


bool isValidBST(struct TreeNode* root){

    int ret;
    ret = find(root, -1, -1);
    if (ret != 0) {
        return false;
    }
    return true;
}


