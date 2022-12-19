开始判断若二叉树为空则返回0，反之递归调用函数求解当前结点的左子树高度与右子树高度，返回更高的子树的高度+当前结点1即为最终二叉树高度，效率一般


```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int L=0,R=0;
        if(root == NULL)
            return 0;
        else
        {    
            L = maxDepth(root->left);
            R = maxDepth(root->right);
            return (L>R?L:R)+1;
        }
    }
};
```

执行用时 :
12 ms
, 在所有 C++ 提交中击败了
73.07%
的用户
内存消耗 :
19.1 MB
, 在所有 C++ 提交中击败了
76.12%
的用户