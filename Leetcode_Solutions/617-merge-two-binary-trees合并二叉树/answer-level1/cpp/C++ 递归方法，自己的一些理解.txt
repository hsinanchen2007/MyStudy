```
/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {//因为如果t1和t2只有一个存在的情况下，（假设t1有t2没有）则t1以及t1的所有子节点t2都会没有（即t2从这个结点开始后面全是空的），所以直接加上t1树后续全部内容即可
        if (!t1)//如果t1为空，直接返回t2
        {
            return t2;
        }
        else if (!t2)//如果t2为空，直接返回t1
        {
            return t1;
        }
        TreeNode *T = new TreeNode(t1->val + t2->val);//t1和t2都不为空，则返回它俩值相加后的结点
        T->left = mergeTrees(t1->left, t2->left);//递归建立新左子树
        T->right = mergeTrees(t2->right, t2->right);//递归建立新的右子树
        return T;//返回树根
    }
};

```
