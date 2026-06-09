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

int TreeNodeDepth(struct TreeNode*b){
    int left,right;
    if(b==NULL)
    return 0;
    else{
        left=TreeNodeDepth(b->left);
        right=TreeNodeDepth(b->right);
        return (left>right)?(left+1):(right+1);
    }
}
int Convert(int left,int right){
    if(left<right)
    return right-left;
return left-right;
}
bool isBalanced(struct TreeNode* root){
if(!root)
return true;
int left,right;
left=TreeNodeDepth(root->left);
right=TreeNodeDepth(root->right);
return (Convert(left,right)<=1)&&(isBalanced(root->left))&&(isBalanced(root->right));

}
```