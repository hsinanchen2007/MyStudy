### 解题思路

翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1


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

void dfs(struct TreeNode* root){
     if (root == NULL)
        return;
    struct TreeNode * temp = root->left;
    root->left = root->right;
    root->right = temp;
    dfs(root->left);
    dfs(root->right);
}

struct TreeNode* invertTree(struct TreeNode* root){
   dfs(root);
   return root;
}
```