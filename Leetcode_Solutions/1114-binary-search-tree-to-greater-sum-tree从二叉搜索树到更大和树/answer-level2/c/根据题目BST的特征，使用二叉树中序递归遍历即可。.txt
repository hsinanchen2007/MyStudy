### 解题思路
根据题目BST的特征，使用二叉树中序递归遍历即可。
同时需要注意的是，递归累加的数值在每一步都会改变，因此要用传址的方式填入。
最开始我直接传入 val，解题是错误的。

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
//BST的特点是左<根<右，因此用中序遍历累加即可。
struct TreeNode* InOrderSearch(struct TreeNode* root, int *val)
{
    if (root) {
        InOrderSearch(root->right, val); //先遍历右子树到底
        *val += root->val;
        root->val = *val;
        InOrderSearch(root->left, val); //右子树的左子树也比原始树中的节点大，因此也要遍历当前节点的左子树
    }
    return root;
}

struct TreeNode* bstToGst(struct TreeNode* root)
{
    int val = 0;
    return InOrderSearch(root, &val);
}
```