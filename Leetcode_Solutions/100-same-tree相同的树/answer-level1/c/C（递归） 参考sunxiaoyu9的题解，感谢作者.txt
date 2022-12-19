### 解题思路
此处撰写解题思路
新手上路，借题解记录一下自己的思路。
1：关于二叉树，其实就相当于是列表，只不过用left和right节点（或者其他类型）表示其链表连接方式，相当于next节点
2：递归思路，要确定边界条件，然后重复调用其自身，直到满足边界条件。

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
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL) return true; 
    else if (p == NULL || q == NULL) return false;
         else if (p->val != q->val) return false;
               else return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
}

```