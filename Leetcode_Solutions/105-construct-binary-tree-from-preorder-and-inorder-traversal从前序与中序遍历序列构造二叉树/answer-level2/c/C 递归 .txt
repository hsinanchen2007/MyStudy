/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* dfs(int* preorder,int* inorder,int inorderSize){
    if(inorderSize == 0) return 0;
    struct TreeNode *p = malloc(sizeof(struct TreeNode));
    p->val = preorder[0];
    if(inorderSize == 1){
        p->left = 0;
        p->right = 0;
        return p;
    }
    int i;
    for(i= 0; i < inorderSize;i++){
        if(p->val == inorder[i]) break;
    }
    int left_inorderSize = i;
    int right_inorderSize = inorderSize - i - 1;

    p->left = dfs(preorder + 1,inorder,left_inorderSize);
    p->right = dfs(&preorder[i] + 1,&inorder[i] + 1,right_inorderSize);
    return p;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    struct TreeNode* p = dfs(preorder,inorder,inorderSize);
    return p;
}