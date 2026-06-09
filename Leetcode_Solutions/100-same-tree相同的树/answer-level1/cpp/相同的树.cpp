看完题目后的第一想法就是递归， 判断同为空或非空及其值， 左比左，右比右。一级一级向下比较。

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ( !p && !q ) return true;
        if ( !p || !q ) return false;

        return  p->val == q->val && \
            isSameTree(p->left, q->left) && \
            isSameTree(p->right, q->right);
    }
};
