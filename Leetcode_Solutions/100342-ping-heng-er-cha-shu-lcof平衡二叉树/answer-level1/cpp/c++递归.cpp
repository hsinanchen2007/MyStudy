定义全局变量res保存结果
求解深度的同时判断是否为平衡二叉树

```
class Solution {
public:
    bool res = true;
    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        return res;
    }
    int maxDepth(TreeNode* root){
        if(root == NULL) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        int dif = leftDepth - rightDepth;
        if(dif > 1 || dif < -1)
            res = false;
        if(leftDepth >= rightDepth)
            return leftDepth + 1;
        else return rightDepth + 1;
    }
};
```
