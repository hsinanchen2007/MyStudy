### 解题思路
关于二叉树的问题解决方法就是递归，解决思路如下：
1 计算出二叉树每个节点的左右子树高度，并比较两者之差是否大于1
2 利用计算二叉树最大深度的函数，来计算左右子树的高度
3 比较每个节点左右子树是否均符合高度小于1的条件

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
int maxDepth(struct TreeNode *root)
{
    //递归终止条件
    if(root == NULL)
    {
        return 0;
    }
    int left = maxDepth(root->left)+1;
    int right = maxDepth(root->right)+1;
    return (left > right ? left : right);
}

bool isBalanced(struct TreeNode* root)
{
    //递归终止条件
    if(root == NULL)
    {
        return true;
    }
    else
    {
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        //递归终止条件
        if(abs(left-right) > 1)
        {
            return false;
        }
    }
    return isBalanced(root->left) && isBalanced(root->right);
}
```