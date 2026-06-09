# 迭代

```
// struct TreeNode {
//     int val;
//     struct TreeNode* left;
//     struct TreeNode* right;
// };
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 1000
int** levelOrder(struct TreeNode* root,
                 int* returnSize,
                 int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    struct TreeNode *qu[MaxSize], *p;  //环形队列
    int front = 0, rear = 0, k = 0, i, sum;
    int** result = (int**)malloc(sizeof(int*) * MaxSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * MaxSize);
    rear = (rear + 1) % MaxSize;
    qu[rear] = root;
    while (front != rear) {
        sum = (rear - front + MaxSize) % MaxSize;
        (*returnColumnSizes)[k] = sum;
        result[k] = (int*)malloc(sizeof(int)*sum);
        for (i = 0; i < sum; i++) {
            front = (front + 1) % MaxSize;
            p = qu[front];
            result[k][i] = p->val;
            if (p->left != NULL) {
                rear = (rear + 1) % MaxSize;
                qu[rear] = p->left;
            }
            if (p->right != NULL) {
                rear = (rear + 1) % MaxSize;
                qu[rear] = p->right;
            }
        }
        k++;
    }
    *returnSize = k;
    return result;
}

```

# 递归
写得有点繁琐……
```

//   Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     struct TreeNode* left;
//     struct TreeNode* right;
// };
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 1000
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
void helper(struct TreeNode* root, int** result, int* ColumnSizes, int i, int* maxh) {
    if (root != NULL) {
        result[i][ColumnSizes[i]] = root->val;
        ColumnSizes[i]++;
        if(i+1>*maxh)
            *maxh = i+1;
        helper(root->left, result, ColumnSizes, i + 1, maxh);
        helper(root->right, result, ColumnSizes, i + 1, maxh);
    }
}
int** levelOrder(struct TreeNode* root,
                 int* returnSize,
                 int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * MaxSize);
    int i;
    for (i = 0; i < MaxSize; i++)
        result[i] = (int*)malloc(sizeof(int) * MaxSize);
    *returnColumnSizes = (int*)calloc(MaxSize, sizeof(int));
    *returnSize = 0;
    if(root==NULL)
        return NULL;
    helper(root, result, *returnColumnSizes, 0, returnSize);
    return result;
}

```
