借助二叉树搜索树的特性，采用递归算法，最后返回的根结点值介于int p和int q之间;
因此，如果当前结点大于q，则往左结点走（搜索树特性）；
如果当前结点小于p，则往右结点走；
当满足根结点值介于int p和int q之间时，则返回。
```
class Solution {
public:TreeNode* ans;
    TreeNode* search(TreeNode* root,int p,int q){
        if(root->val>=p&&root->val<=q)  ans = root;
        if(root->val<p) search(root->right,p,q);
        if(root->val>q) search (root->left,p,q);
         return ans;
    }     
 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return p->val>q->val?search(root,q->val,p->val):search(root,p->val,q->val);
    }
};
```

