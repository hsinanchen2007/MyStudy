### 解题思路
此处撰写解题思路

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


int heightOfTree(struct TreeNode* root, int *max)
{
    if(!root) return 0;
    int left = heightOfTree(root->left, max);
    int right = heightOfTree(root->right, max);
    if(left + right > *max)
        *max = left + right;
    return (left > right ? left:right) + 1;
}
int diameterOfBinaryTree(struct TreeNode* root){
    int max = 0;
    heightOfTree(root, &max);
    return max;
}
```