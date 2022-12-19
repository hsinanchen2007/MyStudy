### 解题思路


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
    int leftnum , rightnum;
    
    if(root == NULL)
    {
        return 0;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    leftnum = maxDepth(root->left);
    rightnum = maxDepth(root->right);

    return leftnum>rightnum ? leftnum+1 : rightnum+1;
   
}
```