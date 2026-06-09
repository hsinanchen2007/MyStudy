```
class Solution {
public:
    bool isbalance = true;
    bool isBalanced(TreeNode* root) {
        treeHeight(root);
        return isbalance;
    }
    
    int treeHeight(TreeNode* root){
        if(root == NULL)
            return 0;
        int l = treeHeight(root->left);
        int r = treeHeight(root->right);
        if(abs(l-r)>1)
            isbalance = false;
        return max(l,r)+1;
    }
};
```
效率不高，最近迷上递归解题，权当提供一个思路吧，欢迎交流