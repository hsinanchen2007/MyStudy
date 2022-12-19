对于一般的树,`r`是`p`和`q`的最近公共祖先当前仅当`p`和`q`分别在`r`的左右子树中.
本题是二叉搜索树,判断是否在左右子树中只需要比较节点值的大小.
代码如下
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        if(root->val>p->val&&root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val<p->val&&root->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else
            return root;
    }
};
```