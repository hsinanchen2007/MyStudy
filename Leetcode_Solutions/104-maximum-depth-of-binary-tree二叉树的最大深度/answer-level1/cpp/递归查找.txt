向下递归查找，若是一个叶子结点则其深度返回为1
之后向上返回，不断取两孩子节点中的较深者的深度并加一，最后即是最大深度

注意防范退化情况
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;//叶
        return  1 + max(maxDepth(root->left),maxDepth(root->right));//向下递归
    }
};