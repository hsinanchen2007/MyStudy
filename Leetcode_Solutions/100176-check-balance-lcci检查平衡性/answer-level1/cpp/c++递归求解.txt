### 解题思路
此处撰写解题思路
作为刚开始刷力扣题的菜鸟，也想该总结一下思路，力扣中很多关于二叉树的题都是用了递归的方法求解。但是作为刚开始的菜鸟递归这东西着实很难理解。在此推荐一篇大佬写的博客：https://lyl0724.github.io/2020/01/25/1/  希望能帮到更多像我这样的算法初学者.关于这题总的思路就是先求树的最大深度，然后由于递归的自顶而下的思想中，树只有三个结点，根节点，左孩子，右孩子，那么主程序中需要先保持根节点是平衡的，也就是左子树最大深度-右子树最大深度<=1就能保住这一点。然后我们需要同时保证左子树也是平衡的，那么我们假设isBalanced(root->left)就能解决这个问题（不用想为啥，你只需要知道这么调用这个函数就能解决左子树是不是平衡的）.注意千万不要思考递归的过程!!!!这是大忌！！不然就会乱掉!!!!!好了有了这个假定之后问题就轻松多了，同样我们需要右子树也是平衡的，依照上述左子树的方法.那么如果这三个条件同时满足，就是符合题目要求的。初次分享题解，主要侧重递归的理解上，算法也不算啥好算法，大佬勿看。
### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int Get_Deep(TreeNode *root)
    {
        if(root==NULL)
        return 0;
        return max(Get_Deep(root->left),Get_Deep(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        return true;
        int left_deep=Get_Deep(root->left);
        int right_depp=Get_Deep(root->right);
        return isBalanced(root->left)&&isBalanced(root->right)&&(abs(right_depp-left_deep)<=1);
    }
};
```