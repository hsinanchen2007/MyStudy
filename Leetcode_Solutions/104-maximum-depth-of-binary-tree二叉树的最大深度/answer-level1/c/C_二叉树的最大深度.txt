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
    if(root==0)
        return 0;
    else
    {
        int leftLength=maxDepth(root->left);
        int rightLength=maxDepth(root->right);
        return leftLength>rightLength?leftLength+1:rightLength+1;
    }
}
```