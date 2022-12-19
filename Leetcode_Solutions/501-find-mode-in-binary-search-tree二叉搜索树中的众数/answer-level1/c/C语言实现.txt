C语言实现
```C []
void findMaxSum(struct TreeNode* root, int *prev, 
                int *curr_size, int* max_size, int* res, int* returnSize){
    if (NULL == root) return;
    findMaxSum(root->left, prev, curr_size, max_size, res, returnSize);
    if (*prev == root->val) {     
        *curr_size += 1;      
    } else {
        *curr_size = 1;
        *prev = root->val;
    }
    if (*curr_size == *max_size){
        res[(*returnSize)++] = *prev;
    }
    if (*curr_size > *max_size){
        *max_size = *curr_size;
        *returnSize = 0;
        res[(*returnSize)++] = *prev;
    }
    
    findMaxSum(root->right, prev, curr_size, max_size, res, returnSize);
}
int* findMode(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (NULL == root) return NULL;
    int *res = (int*)malloc(10240 * sizeof(int));
    int max_size = -1;
    int curr_size = 0;
    int prev = root->val;
    findMaxSum(root, &prev, &curr_size, &max_size, res, returnSize);
    return res;
}
```
