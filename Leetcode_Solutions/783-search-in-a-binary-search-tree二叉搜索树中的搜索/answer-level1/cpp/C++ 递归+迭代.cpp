```
/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
/*
递归
 */
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
        {
            return root;
        }
        if (val > root->val)
        {
            return searchBST(root->right, val);
        }
        else if (val < root->val)
        {
            return searchBST(root->left, val);
        }
        else
            return root;
    }
};
/*
迭代
 */
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root != NULL)
        {
            if (val > root->val)
            {
                root = root->right;
            }
            else if (val < root->val)
            {
                root = root->left;
            }
            else
            {
                return root;
            }
        }
        return NULL;
    }
};

```
