### 解题思路
被秀了一脸，自以为只用将根节点左右子树的最大路径相加就好，没想到要对每一个节点都要判断。考虑的不严谨。

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

// len(root->left) + len(root->right) + 2;
int dfs(struct TreeNode* root, int *max){
    if( root == NULL ) return 0;
    int leftLen = dfs(root->left, max);
    int rightLen = dfs(root->right, max);
    if( leftLen + rightLen > *max) {
        *max = leftLen + rightLen;
    }
    return leftLen > rightLen ? leftLen + 1 : rightLen + 1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    if( root == NULL ) return 0;
    int max = 0;
    dfs(root, &max);
    return max;
}
```