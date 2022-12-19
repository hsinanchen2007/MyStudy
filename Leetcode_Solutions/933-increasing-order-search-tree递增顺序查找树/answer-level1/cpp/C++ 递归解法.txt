```
class Solution {
public:
    /*
     核心思路：
     递归。
     如果 root 没有左子树，则无需改造，直接返回
     递归地改造 root->left, root->right
     记录递归后的 root->left 为 result，然后将 root 变为 root->left 最右边子树的右子树
     修改 root->left = NULL 指空，返回 result
     **/
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return NULL;
        if (!root->left) return root;
        
        root->left = increasingBST(root->left);
        if(root->right) root->right  = increasingBST(root->right);
        
        TreeNode *result = root->left;
        TreeNode *p = result;
        while (p->right) p = p->right;
        root->left = NULL;
        p->right = root;
        return result;
    }
};
```
