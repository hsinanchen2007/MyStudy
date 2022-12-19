执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.9 MB, 在所有 C++ 提交中击败了93.02%的用户
```
/*
第一遍思路：把所有可能情况想出来然后对号入座即可。但是耗时还是相对高一些
 */
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        reverTree(root);
        return root;
    }
    void reverTree(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        if (!root->left && !root->right)
        {
            return;
        }
        if (root->left && root->right)
        {
            TreeNode *T = root->left;
            root->left = root->right;
            root->right = T;
        }
        else if (!root->left && root->right) //root左子树为NULL，右子树存在
        {
            root->left = root->right;
            root->right = NULL;
        }
        else
        { //root右子树为NULL，左子树存在
            root->right = root->left;
            root->left = NULL;
        }
        reverTree(root->left);
        reverTree(root->right);
    }
};

```
```
/*
第二遍思路：可以将左子树和右子树有一个不存在的情况统一一下
 */
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        reverTree(root);
        return root;
    }
    void reverTree(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        if (!root->left)
        {
            root->left = root->right;
            root->right = NULL;
        }
        else if (!root->right)
        {
            root->right = root->left;
            root->left = NULL;
        }
        if (root->left && root->right)
        {
            TreeNode *T = root->left;
            root->left = root->right;
            root->right = T;
        }
        reverTree(root->left);
        reverTree(root->right);
    }
};
```

