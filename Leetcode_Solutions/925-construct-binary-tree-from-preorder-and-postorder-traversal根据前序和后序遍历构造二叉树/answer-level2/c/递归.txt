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


struct TreeNode* constructFromPrePost(int* pre, int preSize, int* post, int postSize){
    if(preSize==0) return NULL;
    struct TreeNode *root;
    root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=pre[0];
    if(preSize==1){
        root->left=NULL;
        root->right=NULL;
        return root;
    } 
    int i;
    for(i=1;i<preSize;i++){
        if(pre[i]==post[postSize-2]) break;
    }
    root->left=constructFromPrePost(pre+1,i-1,post,i-1);
    root->right=constructFromPrePost(pre+i,preSize-i,post+i-1,postSize-i);
    return root;
}
```