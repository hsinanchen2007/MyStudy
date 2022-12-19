### 解题思路
该题的难点在于递归的实现，需要找到递归的终止条件。同时，需要将原二叉树看做左子树和右子树进行对比。
终止条件：
1 左右子节点的值都为空 true
2 左右子节点 一个非空，一个为空 false
3 左右子节点均非空，但两节点的值不同 false
4 两节点值相等，则继续递归

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

bool isMirror(struct TreeNode *t1, struct TreeNode *t2)
{
    if((t1 == NULL) && (t2 == NULL))
    {
        return true;
    }
    else if((t1 != NULL) && (t2 != NULL))
    {
        if(t1->val != t2->val)
        {
            return false;
        }
        else
        {
            return (isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left));
        }
    }
    else
    {
        return false;
    }
}

bool isSymmetric(struct TreeNode* root)
{
    if(root == NULL)
    {
        return true;
    }
    return isMirror(root->left, root->right);
}
```