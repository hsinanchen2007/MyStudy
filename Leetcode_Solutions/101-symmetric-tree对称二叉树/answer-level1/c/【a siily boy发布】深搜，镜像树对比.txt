```
typedef struct TreeNode TreeNode;

bool compareOrder(TreeNode *root1, TreeNode *root2) {
    if ((root1 == NULL) && (root2 == NULL)) {
        return true;
    }
    if ((root1 == NULL) && (root2 != NULL)) {
        return false;
    }
    if ((root1 != NULL) && (root2 == NULL)) {
        return false;
    }

    if ((root1->val) != (root2->val)) {
        return false;
    }
    if (compareOrder(root1->left, root2->right) == false) {
        return false;
    }
    if (compareOrder(root1->right, root2->left) == false) {
        return false;
    }
    return true;
}

bool isSymmetric(struct TreeNode* root){
    bool returnValue;
    returnValue = compareOrder(root, root);

    return returnValue;
}
```
