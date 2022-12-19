### 解题思路
递归大法

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


int minDepth(struct TreeNode* root){
    if(root==NULL)return 0;
    int hLeft = minDepth(root->left),hRight = minDepth(root->right);
    if(hLeft==0)return 1+hRight;
    if(hRight==0)return 1+hLeft;
    return 1+(hLeft<hRight?hLeft:hRight);
}
```