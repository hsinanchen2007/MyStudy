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


struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    if(preorderSize==0) return NULL;
    struct TreeNode *root;
    root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=preorder[0];
    root->left=NULL;
    root->right=NULL;
    int i;
    for(i=1;i<preorderSize;i++)
        if(preorder[i]>preorder[0]) break;
    root->left=bstFromPreorder(preorder+1,i-1);
    if(i<preorderSize){
        root->right=bstFromPreorder(preorder+i,preorderSize-i);
    }
    return root;
}
```