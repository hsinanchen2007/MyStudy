```
#define MY_MAX(a, b) ((a) > (b) ? (a) : (b))

static int GetTreeHeight(struct TreeNode *tree)
{
    int result;
    
    if (tree == NULL) {
        return 0;
    }
    
    result = 1;
    result += MY_MAX(GetTreeHeight(tree->left), GetTreeHeight(tree->right));
    return result;
}

bool isBalanced(struct TreeNode* root){
    int leftHeight;
    int rightHeight;
    bool result;
    
    if (root == NULL) {
        return true;
    }
    
    result = isBalanced(root->left);
    if (result == false) {
        return false;
    }
    result = isBalanced(root->right);
    if (result == false) {
        return false;
    }
    
    leftHeight = GetTreeHeight(root->left);
    rightHeight = GetTreeHeight(root->right);
    //printf("left = %d, right = %d\n", leftHeight, rightHeight);
    if (abs(leftHeight - rightHeight) > 1) {
        return false; 
    }
    
    return true;
}
```
