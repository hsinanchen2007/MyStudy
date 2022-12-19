二叉搜索树特征：左子树<根<右子树
- 若p，q的值均小于root，则都在左子树中，向左子树递归寻找
- 若p，q的值均大于root，则都在右子树中，向右子树递归寻找
- 若p，q的值位于root两侧，则分散于左右子树中，最近公共祖先为root
```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};
```
