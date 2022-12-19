执行用时 :36 ms, 在所有 C++ 提交中击败了89.44%的用户内存消耗 :25.1 MB, 在所有 C++ 提交中击败了100.00%的用户

![](https://pic.leetcode-cn.com/ea9b53671a04784240d3847d3f7a707f79b885e01f65a1a06609bf7907263aa7-%E5%8A%A8%E6%80%81%E9%93%BE%E8%A1%A8LCA.png)

```
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
//递归边界返回空或者返回存在的那个结点
        if(root==NULL||root==p||root==q) return root;
//左边找一找
        TreeNode* L=lowestCommonAncestor(root->left,p,q);
//右边找一找
        TreeNode* R=lowestCommonAncestor(root->right,p,q);
//返回NULL或者有的那一侧
        if(L==NULL)return R;
        if(R==NULL)return L;
//当前祖先左边有p，右边有q
        return root;  
    }
```