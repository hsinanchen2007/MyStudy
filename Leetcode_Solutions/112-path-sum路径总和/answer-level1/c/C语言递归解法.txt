### 解题思路
递归中下一次传入函数的num等于当前的num-root->val。

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


bool hasPathSum(struct TreeNode* root, int sum){
    if(root==NULL)return false;
    if(root->right==NULL&&root->left==NULL){
        if(root->val==sum)return true;
        else return false;
    } 

    bool isLeft=hasPathSum(root->left,sum-root->val);
    bool isRight=hasPathSum(root->right,sum-root->val);
    return (isLeft||isRight);
}
```