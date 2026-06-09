```
typedef struct TreeNode TreeNode;

bool TreeSearch(TreeNode *treeNode, long long int lower, long long int upper) {
    long long int val;
    if (treeNode == NULL) {
        return true;
    }
    val = (long long int)treeNode->val;
    if ((val <= lower) || (val >= upper)) {
        return false;
    }

    if (TreeSearch(treeNode->left, (long long int)lower, (long long int)val) == false) {
        return false;
    }
    if (TreeSearch(treeNode->right, (long long int)val, (long long int)upper) == false) {
        return false;
    }

    return true;
}

bool isValidBST(struct TreeNode* root){
    bool returnValue;
    long long int lower = -0x7fffffffffffffff;
    long long int upper = 0x7fffffffffffffff;

    printf("lower: %lld\n", lower);
    printf("upper: %lld\n", upper);
    
    if (root == NULL) {
        return true;
    }

    returnValue = TreeSearch(root, lower, upper);

    return returnValue;
}
```
