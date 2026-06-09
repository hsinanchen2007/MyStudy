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
    if(root==NULL){
        return 0;
    }
    int count=maxDepth(root->left);
    int t=maxDepth(root->right);
    return count>t?count+1:t+1;

}
```