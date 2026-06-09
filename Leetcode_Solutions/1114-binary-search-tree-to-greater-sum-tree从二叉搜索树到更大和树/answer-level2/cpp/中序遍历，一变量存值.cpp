利用二叉搜索树的特性，最大的在最右边，而题目要求比当前结点相等或大的数字之和，那么就从最右边开始遍历，因为没人比它大，然后中序遍历，因为二叉搜索树的特征就是小中大 从大的数据到小的数据，路上把每个结点的数据存起来，到每个结点就和当前结点加一下然后给它。
``` c++
class Solution {
public:
    int val = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if (root) {
            bstToGst(root->right);
            val += root->val;
            root->val = val;
            bstToGst(root->left);
        }
        return root;
    }
};
```