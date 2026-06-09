### 解题思路
给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

 

例如：

输入: 原始二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13


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
int sum;
void  dfs(struct TreeNode* root){
    if(root == NULL)
        return 0;

    dfs(root->right);
    sum += root->val;
    root->val = sum;
    dfs(root->left);
}

struct TreeNode* convertBST(struct TreeNode* root){
    sum = 0;
    dfs(root);
    return root;
}
```