- 方法一：栈（深度优先搜索）
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int stackSize = 10;
    struct TreeNode** stack = (struct TreeNode**)malloc(stackSize * sizeof(struct TreeNode*));
    int top = -1;
    
    
    int arrSize = 10;
    int* arr = (int*)malloc(arrSize * sizeof(int));
    int p = -1;

    stack[++top] = root;
    while (top != -1) {
        struct TreeNode* node = stack[top--];
        if (p == arrSize - 1) {
            arr = (int*)realloc(arr, (arrSize += 10) * sizeof(int));
        }
        arr[++p] = node->val;
        
        if (node->right != NULL) {
            if (top == stackSize - 1) {
                stack = (struct TreeNode**)realloc(stack, (stackSize += 10) * sizeof(struct TreeNode*));
            }
            stack[++top] = node->right;
        }
        
        if (node->left != NULL) {
            if (top == stackSize - 1) {
                stack = (struct TreeNode**)realloc(stack, (stackSize += 10) * sizeof(struct TreeNode*));
            }
            stack[++top] = node->left;
        }
    }
    free(stack);
    stack = NULL;
    *returnSize = p + 1;
    arr = realloc(arr, (*returnSize) * sizeof(int));
    return arr;
}
```
- 方法二：Morris方法
```c
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int outSize = 1;
    int* output = (int*)malloc(outSize * sizeof(int));
    int p = -1;

    struct TreeNode* node = root;
    while (node != NULL) {
        if (node->left == NULL) {
            if (p == outSize - 1) {
                output = (int*)realloc(output, (outSize += 1) * sizeof(int));
            }
            output[++p] = node->val;
            node = node->right;
        }
        else {
            struct TreeNode* predecessor = node->left;
            while (predecessor->right != NULL && predecessor->right != node) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL) {
                if (p == outSize - 1) {
                    output = (int*)realloc(output, (outSize += 1) * sizeof(int));
                }
                output[++p] = node->val; 
                predecessor->right = node;   
                node = node->left;            
            }
            else {
                predecessor->right = NULL;
                node = node->right;
            }
        }
    }
    *returnSize = p + 1;
    return output;
}
```

