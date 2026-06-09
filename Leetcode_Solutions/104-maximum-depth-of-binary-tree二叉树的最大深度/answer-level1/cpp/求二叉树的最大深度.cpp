```
class Solution {
public:
    //递归求解
    int maxDepth(TreeNode* root) {
        if(!root) //考虑特殊情况 根节点为空
            return 0;
        int left_depth = maxDepth(root->left)+1; //递归求左子树深度
        int right_depth = maxDepth(root->right)+1; //递归求右子树深度
        return left_depth>right_depth ? left_depth:right_depth; //最后比较 取较大的那个
    }
};
```
