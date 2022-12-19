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


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if(postorderSize==0||inorderSize==0) return NULL;
    struct TreeNode *root;
    root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=postorder[postorderSize-1];
    if(inorderSize==1){
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    int i;
    for(i=0;i<inorderSize;i++)
        if(inorder[i]==root->val) break;
    root->left=buildTree(inorder,i,postorder,i);
    root->right=buildTree(inorder+i+1,inorderSize-i-1,postorder+i,postorderSize-i-1);
    return root;
}
```