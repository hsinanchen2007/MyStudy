本题容易溢出，故用long类型
```
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST(TreeNode *root, long low, long high){
        if (root == NULL )
            return true;
        if (low < root->val && root->val < high)
            return (isValidBST(root->left, low, root->val) && isValidBST(root->right, root->val, high));
        else
            return false;
    }
};
```
