- 方法一：基于栈
```c
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    int stackSize = 5;
    struct TreeNode** stack = (struct TreeNode**)malloc(stackSize * sizeof(struct TreeNode*));
    int topOfStack = -1;
    
    int arrSize = 1;
    int* arr = (int*)malloc(arrSize * sizeof(int));
    int p = -1;
    
    struct TreeNode* node = root;
    while (topOfStack != -1 || node != NULL) {
        while (node != NULL) {
            if (topOfStack == stackSize - 1) {
                stack = (struct TreeNode**)realloc(stack, (stackSize += 5) * sizeof(struct TreeNode*));
            }
            stack[++topOfStack] = node;
            node = node->left;
        }
        node = stack[topOfStack--];
        if (p == arrSize - 1) {
            arr = (int*)realloc(arr, (arrSize += 1) * sizeof(int));
        }
        arr[++p] = node->val;
        node = node->right;
    }
    free(stack);
    stack = NULL;
    *returnSize = p + 1;
    return arr;
}
```
- 方法二：Morris方法
```c
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    int outSize = 1;
    int* out = (int*)malloc(outSize * sizeof(int));
    int p = -1;
    
    struct TreeNode* node = root;
    while (node != NULL) {
        if (node->left == NULL) {
            if (p == outSize - 1) {
                out = (int*)realloc(out, (outSize += 1) * sizeof(int));
            }
            out[++p] = node->val;
            node = node->right;
        }
        else {
            struct TreeNode* pre = node->left;
            while (pre->right != NULL && pre->right != node) {
                pre = pre->right;
            }

            if (pre->right == NULL) {  
                pre->right = node; 
                node = node->left;           
            }
            else {
                if (p == outSize - 1) {
                    out = (int*)realloc(out, (outSize += 1) * sizeof(int));
                }
                out[++p] = node->val;  
                pre->right = NULL;
                node = node->right;
            }
        }
    }
    *returnSize = p + 1;
    return out;
}
```

