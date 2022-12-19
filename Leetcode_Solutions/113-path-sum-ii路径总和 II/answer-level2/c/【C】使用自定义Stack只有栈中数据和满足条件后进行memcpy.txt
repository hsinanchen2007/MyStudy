1.使用前序遍历
2.使用stack存储路径
3.stack中路径和满足条件后memcpy
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct IntStack {
    int capacity;
    int top;
    int *data;
    int matchedCount;
};

struct IntStack *createIntStack()
{
    struct IntStack *stack = (struct IntStack *)malloc(sizeof(struct IntStack));
    if (stack == NULL) {
        return NULL;
    }
    
    memset(stack, 0, sizeof(struct IntStack));
    stack->capacity = 1024;
    stack->top = -1;
    stack->data = (int *)malloc(sizeof(int) * stack->capacity);
    stack->matchedCount = 0;
    if (stack->data == NULL) {
        free(stack);
        stack = NULL;
        return NULL;
    }
    return stack;
}

void destoryIntStack(struct IntStack *stack) {
    if (stack == NULL) {
       return;
    } 
    if (stack->data != NULL) {
        free(stack->data);
        stack->data = NULL;
    }
    free(stack);
    stack = NULL;
}

void pushIntStack(struct IntStack *stack, int x) {
    if (stack == NULL) {
        return;
    }
    stack->data[++stack->top] = x;
}

void popIntStack(struct IntStack *stack) {
    if (stack == NULL) {
        return;
    }
    if (stack->top < 0) {
        return;
    }
    --stack->top;
}

int sizeOfIntStack(struct IntStack *stack) {
    if (stack == NULL) {
        return 0;
    }  
    
    return stack->top + 1;
}

void printfIntStack(struct IntStack *stack,                     
                    int **data,
                    int *returnColumnSizes) {
    if (stack == NULL) {
        return;
    } 
    int i = stack->matchedCount;
    int dataCount = sizeOfIntStack(stack);
    data[i] = malloc(sizeof(int) * dataCount);
    if (data[i] == NULL) {
        return;
    }
    memset(data[i], 0, sizeof(int) * dataCount);
    memcpy(data[i], stack->data, sizeof(int) * dataCount);
    returnColumnSizes[i] = dataCount;
    
    stack->matchedCount++;
}

void cleanIntStack(struct IntStack *stack) {
    if (stack == NULL) {
        return;
    } 
    stack->top = -1;
}

bool isLeafNode (struct TreeNode* root) {
    if (root == NULL) {
       return false; 
    }

    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    return false;
}

void pathSumMatched(struct TreeNode* root, 
                    struct IntStack *stack, 
                    int **data,
                    int *returnColumnSizes,
                    int currentSum, 
                    int sum) {
    if (root == NULL || stack == NULL) {
       return; 
    }
    
    pushIntStack(stack, root->val);
    if (isLeafNode(root)) {
        if ((currentSum + root->val) == sum ) {    
            printfIntStack(stack, data, returnColumnSizes);
        }
        return;
    }
    pathSumMatched(root->left, stack, data, returnColumnSizes, currentSum + root->val, sum);
    if (root->left != NULL) {
       popIntStack(stack); 
    }
    
    pathSumMatched(root->right, stack, data, returnColumnSizes, currentSum + root->val, sum);
    if (root->right != NULL) {
       popIntStack(stack); 
    }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pathSum(struct TreeNode* root, 
              int sum, 
              int* returnSize, 
              int** returnColumnSizes){
    if (returnColumnSizes == NULL) {
        return NULL; 
    }
    if (returnSize == NULL) {
        *returnColumnSizes = NULL;
        return; 
    }
    if (root == NULL) {
        *returnColumnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }
    
    *returnColumnSizes = NULL;
    *returnSize = 0;
    
    int currentSum = 0;
    
    struct IntStack *stack = createIntStack();
    if (stack == NULL) {
        return NULL;
    }
    
    int **data = (int **)malloc(sizeof(int *) * 1024);
    if (data == NULL) {
        return NULL;
    }
    memset(data, 0, sizeof(int *) * 1024);
    
    *returnColumnSizes = (int *)malloc(sizeof(int) * 1024);
    if (*returnColumnSizes == NULL) {
        return NULL;
    }
    memset(*returnColumnSizes, 0, sizeof(int) * 1024);
    
    pathSumMatched(root, stack, data, *returnColumnSizes, 0, sum);
    *returnSize = stack->matchedCount;
    
    destoryIntStack(stack);
    stack = NULL;
    return data;
}

```
