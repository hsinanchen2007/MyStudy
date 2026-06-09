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


int maxDepth(struct TreeNode* root){
    if(root==NULL)
    return 0;
    int leftNode=maxDepth(root->left);
    int rightNode=maxDepth(root->right);
    return leftNode>rightNode?leftNode+1:rightNode+1;

}
```