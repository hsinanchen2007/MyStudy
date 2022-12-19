### 解题思路
二叉树的问题基本都需要使用递归，递归实现的重点是找到递归的终止条件。
1 当节点为NULL时，递归终止
2 当节点非空时，递归继续，并将深度加1
3 获取节点左右子树的深度，然后返回最大值
### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root)
{
    //判断节点是否为空
    if(root == NULL)
    {
        return 0;
    }
    //判断左子树
    int left = maxDepth(root->left)+1;
    int right = maxDepth(root->right)+1;

    return (left > right ? left : right);
}
```