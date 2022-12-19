感觉C++没什么牌面，写的人不多，就用C++写了（C好像在这里更没有牌面。。）
其实跟其他大佬写的递归差不多。


**递归：**


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
         return 0;
        int ldepth=maxDepth(root->left);
        int rdepth=maxDepth(root->right);
        if(ldepth>rdepth)
            return ldepth+1;
        else
            return rdepth+1;
    }
};