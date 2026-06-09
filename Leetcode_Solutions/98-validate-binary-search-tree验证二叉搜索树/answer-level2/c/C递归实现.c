### 解题思路
利用二叉搜索树性质
左树的最右叶节点是左数最大节点
右树的最右叶节点是右树最小节点
再使用递归性质
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


bool isValidBST(struct TreeNode* root)
{
    if(root == NULL)
        return true;
    if(root->left != NULL)
    {
        struct TreeNode* p = root->left;
        if(!isValidBST(p))
            return false;
        while(p->right != NULL)
            p = p->right;
        if(p->val >= root->val)
            return false;
    }
    if(root->right != NULL)
    {
        struct TreeNode* p = root->right;
        if(!isValidBST(p))
            return false;
        while(p->left != NULL)
            p = p->left;
        if(p->val <= root->val)
            return false;
    }
    return true;
}
```