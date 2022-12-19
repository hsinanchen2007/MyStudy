### 代码

```cpp

class Solution {
public:
    //递归法，从上往下遍历，找到第一个满足p<val<q的结点即为最近公共祖先
    //类似于修剪二叉查找树
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //不满足条件的跳跃到继续搜索他的子树
        if(root->val > p->val && root->val > q->val)return lowestCommonAncestor(root->left,p,q);
        if(root->val < p->val && root->val < q->val)return lowestCommonAncestor(root->right,p,q);       
        //满足条件的第一个就是
        return root;
    }
};
```