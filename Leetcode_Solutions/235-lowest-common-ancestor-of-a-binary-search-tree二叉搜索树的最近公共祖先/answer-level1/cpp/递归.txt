```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {  
        if(root==nullptr || p->val>root->val && q->val<root->val || p->val<root->val && q->val>root->val || p->val==root->val || q->val==root->val)
        {
            return root;    // 空指针||异侧||有一个等于根节点的值 则直接返回
        }else
        {
            if(p->val>root->val && q->val>root->val)
            {
                return lowestCommonAncestor(root->right, p, q);  // 同在右侧
            }else
            {
                return lowestCommonAncestor(root->left, p, q);   // 同在左侧
            }
        }
    }
};
```

