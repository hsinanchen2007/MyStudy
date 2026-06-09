### 解题思路


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


int deep(struct TreeNode *root)//用来计算该节点的最深长度
{
    int h = 0;
    if (root == NULL)
        return 0;
    int L = deep(root->left) + 1;
    int R = deep(root->right) + 1;
    h = (L > R) ? L : R;
    return h;
}
int widest(struct TreeNode *root)//计算该节点的最大宽度
{
    int Cur, Max;
    if (root == NULL)
        return 0;
    int Max1 = widest(root->left);
    int Max2 = widest(root->right);
    Cur = deep(root->left) + deep(root->right);
    Max1 = (Max1 > Max2) ? Max1 : Max2;
    Max = (Cur > Max1) ? Cur : Max1;
    return Max;
}
int diameterOfBinaryTree(struct TreeNode *root)
{
    int M = 0;
    if (root != NULL)
        return widest(root);
    else
        return 0;
}


```