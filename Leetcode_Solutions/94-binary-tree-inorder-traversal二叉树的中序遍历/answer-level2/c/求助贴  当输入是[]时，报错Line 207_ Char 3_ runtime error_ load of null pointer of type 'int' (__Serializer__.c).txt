void search(struct TreeNode* root, int * returnSize, int *res) {
    if (root == NULL)
        return;
    search(root->left, returnSize, res);  
    res[*returnSize] = root -> val;
    (*returnSize)++;
    search(root->right, returnSize, res);
    
    

} 
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    if(root == NULL || returnSize == NULL)
        return NULL;
    int *res = malloc(sizeof(int) * 100000);
    *returnSize = 0;
    search(root, returnSize, res);
    return res;

}