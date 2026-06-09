```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root, int *data, int *index) {
    if (root == NULL) {
        return;
    }
    
    if (data == NULL) {
        return; 
    }
    
    if (index == NULL) {
        return;
    }
    inorder(root->left, data, index);
    
    *(data + *index) = root->val;
    ++(*index);
    
    inorder(root->right, data, index);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    
    if (returnSize == NULL) {
        return NULL;
    }  

    if (root == NULL) {
        *returnSize = 0;
        return NULL; 
    }
    
    int *data = (int *)malloc(sizeof(int ) * 1024);
    if (data == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    memset(data, 0, sizeof(int ) * 1024);
    
    int index = 0;
    inorder(root, data, &index); 
    *returnSize = index;
    return data;
}





```
