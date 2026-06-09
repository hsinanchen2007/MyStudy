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

int isBalancedCheck(struct TreeNode* root)
{
    int ldepth, rdepth, maxDepth;

    if(!root){
        return 0;
    }

    ldepth = isBalancedCheck(root->left);
    rdepth = isBalancedCheck(root->right);

    if(ldepth < 0 || rdepth < 0){
        return -1;
    }

    if(abs(ldepth - rdepth) > 1){
        return -1;
    }

    maxDepth = ldepth > rdepth ? ldepth: rdepth;

    return maxDepth + 1;
}

bool isBalanced(struct TreeNode* root){
    
    if(isBalancedCheck(root) < 0){
        return false;
    }

    return true;
}
```