# 标题
这道题目考察的其实是对二叉搜索树的认知，左子树小于根，右子树大于根，那么根据这个特性，就可以知道两个点的最近公共祖先就是恰好满足条件的那个点了
```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val <= p->val && root->val >= q->val)
        {
            return root;
        }
        else if(root->val >= p->val && root->val <= q->val)
        {
            return root;
        }
        else{
            if(q->val > root->val)
                return  lowestCommonAncestor(root->right, p, q);
            else
                return  lowestCommonAncestor(root->left, p, q);       
        }

    }
};
```
