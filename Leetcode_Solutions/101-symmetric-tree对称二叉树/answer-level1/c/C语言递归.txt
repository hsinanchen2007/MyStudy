```
ool Check(struct TreeNode *left, struct TreeNode *right)
{
    if (left == NULL && right == NULL) {
        return true;
    }

    if (left != NULL && right != NULL) {
        if (left->val == right->val) {
            return Check(left->left, right->right) && Check(right->left, left->right);
        }
        return false;
    }
    return false;
}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }
    return Check(root->left, root->right);
}
```
