/* 主要是利用前序数组的每一个元素作为中序数组的分界线，分界线的左边是左子树，分界线的右边是右子数，一直递归。*/
/* 递归的终止条件有两个：1、中序数组中的子树为空。2、前序数组全部元素遍历完成 */

struct TreeNode* helper(int* preorder, int preorderSize, int *ind, int* inorder, int inBegin, int inEnd) {
    if ((*ind) == preorderSize) {
        return NULL;
    }
    
    if (inBegin > inEnd) {
        return NULL;
    }
    
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    root->val = preorder[*ind];
    
    int temp = *ind;
    (*ind)++;
    int i = 0;
    for (i = inBegin; i <= inEnd; i++) {
        if (inorder[i] == preorder[temp]) {   //找到分界线
            root->left = helper(preorder, preorderSize, ind, inorder, inBegin, i - 1);
            root->right = helper(preorder, preorderSize, ind, inorder, i+1, inEnd); 
        }
    }
    
    return root;
} 

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if ((preorderSize == 0) || (inorderSize == 0)) {
        return NULL;
    }
    struct TreeNode* result = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int ind = 0;
    
    result = helper(preorder, preorderSize, &ind, inorder, 0, inorderSize - 1);

    return result;
}