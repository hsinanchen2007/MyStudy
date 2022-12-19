```
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    int maxSize = 100;
    int *array = malloc(maxSize * sizeof(int));
    if (array == NULL) {
        *returnSize = 0;
        return NULL;
    }
    memset(array, 0, maxSize * sizeof(int));
    
    int i = 0;
    int j = 0;
    struct TreeNode* node = root;
    struct TreeNode* tmp[maxSize];
    struct TreeNode* lastNode;
    while ((node != NULL && i < maxSize) || (i > 0)) {
        while (node != NULL && i < maxSize) {            
            tmp[i++] = node;            
            node = node->left;
        }        
        node = tmp[i-1];
        if (node->right == NULL || node->right == lastNode) {
            array[j++] = node->val;
            i--;
            lastNode = node;
            node = NULL;
        } else {
            node = node->right;    
        }
    }  
    
    *returnSize = j;
    return array;
}
```
