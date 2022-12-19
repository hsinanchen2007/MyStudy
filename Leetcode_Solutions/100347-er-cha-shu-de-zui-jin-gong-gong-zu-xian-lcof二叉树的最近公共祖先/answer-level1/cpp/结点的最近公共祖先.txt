### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    TreeNode* ans = NULL;
    /**这个函数的目的是判断树是否有p,q中的节点
    *只要当前树的根是p,q中一个，而且左子树或
    *右子树中找到了另一个节点，那么当前树的根
    *结点就是答案
    *否则，p,q一定位于两个子树中，当前结点就是答案
    */
    bool func(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root == NULL) return false;
        int left=func(root->left,p,q)?1:0;
        int right=func(root->right,p,q)?1:0;
        int mid=(root==p||root==q)?1:0;
        if(mid+right+left==2) ans = root;
        return (mid+left+right) > 0;
    } 
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        func(root,p,q);
        return ans;
    }
};
```