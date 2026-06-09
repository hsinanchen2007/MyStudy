### 解题思路
实际是找到树的深度

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
int res = 0;

int DFS(struct TreeNode* root){
    if(!root) return 0;
    int left = DFS(root->left);
    int right = DFS(root->right);
    res = res > (left + right) ? res : (left +right);
    return (left > right ? left : right) + 1;// 返回当前节点子树的最大高度，+1是当前节点的深度
}
int diameterOfBinaryTree(struct TreeNode* root){
    if(!root) return 0;
    res = 0;
    int h = DFS(root);
    return res;
}
```