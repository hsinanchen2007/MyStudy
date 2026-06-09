可以简单的看出来，一个节点的直径即为左右子树的高度之和再加上2

因为在计算树高的时候要对左右子树的高度进行比较

那么只要在计算树高的同时顺便把左右子树的高度之和计算出来就可以了。


```
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
    int max=INT_MIN;//用于记录直径最大值
    int getheight(TreeNode* node)
    {
        if(node==NULL)      //空节点高度为-1
        return-1;
        else
        { 
            int lh=getheight(node->left);//左子树高度
            int rh=getheight(node->right);//右子树高度
            if((lh+rh)>max)  //求左右子树的和，如果比最大值大则覆盖
                max=lh+rh;
            return lh>rh?lh+1:rh+1;//树节点的高度为左右子树高度的最大值+1
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        return 0;
        else
        getheight(root);
        return max+2;//结果为左右子树之和再加上2
    }
};
```
