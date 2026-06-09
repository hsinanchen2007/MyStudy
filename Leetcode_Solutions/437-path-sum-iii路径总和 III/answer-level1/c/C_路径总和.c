### 解题思路
递归+递归

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

int path(struct TreeNode* Root,int Sum,int Num)
{
    if(Root==0)return 0;
    if(Sum+Root->val==Num)
        return 1+path(Root->left,Sum+Root->val,Num)+path(Root->right,Sum+Root->val,Num);
    else
        return path(Root->left,Sum+Root->val,Num)+path(Root->right,Sum+Root->val,Num);
}

int pathSum(struct TreeNode* root, int sum){
    if(root==0)return 0;
    return path(root,0,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
}

```