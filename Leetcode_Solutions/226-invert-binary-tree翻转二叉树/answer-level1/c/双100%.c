### 解题思路
递归双100
![image.png](https://pic.leetcode-cn.com/a0cf72bfb8933488101c4dbc6582ba78faac12733d91c109da415c2a66ff6b77-image.png)


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


struct TreeNode* invertTree(struct TreeNode* root){
    if(root==NULL){
        return NULL;
    }
    struct TreeNode*rightTree=root->right;
    root->right=invertTree(root->left);
    root->left=invertTree(rightTree);
    return root;

}
```