### 解题思路
递归

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
struct TreeNode * fun(int post_left,int post_right,int in_left,int in_right,int *postorder,int *inorder){
    if(post_left>post_right){
        return NULL;
    }
    struct TreeNode *root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=postorder[post_right];
    int k;
    for(k=in_left;k<=in_right;k++){
        if(postorder[post_right]==inorder[k])
            break;
    }
    int nums_left_node=k-in_left;
    root->left=fun(post_left,post_left+nums_left_node-1,in_left,k-1,postorder,inorder);
    root->right=fun(post_left+nums_left_node,post_right-1,k+1,in_right,postorder,inorder);
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    struct TreeNode *root=fun(0,postorderSize-1,0,inorderSize-1,postorder,inorder);
    return root;
}
```