### 解题思路
对当前节点有两种情况:
1. 把当前节点当作路径的开始
2. 把当前节点的左右孩子作为路径的开始

这里用到双递归，值得理解。

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

int dfs(struct TreeNode* root, int sum){
    if( root == NULL ) return 0;

    int count = 0;
    if ( root->val == sum )
        count = 1;
        return count + dfs(root->left, sum-root->val) + dfs(root->right, sum - root->val);
}

int pathSum(struct TreeNode* root, int sum){
    if( root == NULL ) return 0;
    return pathSum(root->left, sum) + pathSum( root->right, sum) + dfs( root, sum );
}

```