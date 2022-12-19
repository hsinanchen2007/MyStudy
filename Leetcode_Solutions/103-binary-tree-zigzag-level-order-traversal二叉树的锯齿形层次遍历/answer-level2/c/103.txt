### 解题思路
此处撰写解题思路

### 代码

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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_NODE    5000
struct TreeNode **queue = NULL;
int rear;
int front;

int deQueue(struct TreeNode ** queue){
    if (queue == NULL || front == rear) {
        return -1;
    }
    front = (front + 1) % MAX_NODE;
    return 0;
}

int enQueue(struct TreeNode ** queue, struct TreeNode *node){
    if (queue == NULL || node == NULL || front == (rear + 1) % MAX_NODE) {
        return -1;
    }
    queue[rear] = node;
    rear = (rear + 1) % MAX_NODE;
    return 0;
}

int printQueue(struct TreeNode ** queue, int *res, int flag, int f, int r){
    struct TreeNode *node = NULL;
    int cnt = 0;
    if (flag == 0) {
        while (f != r) {
            node = queue[r - 1];
            res[cnt++] = node->val;
            r = r - 1;
            if (r == -1) {
                r = MAX_NODE - 1;
            }
        }
    }
    else if (flag == 1) {
        while (f != r) {
            node = queue[f];
            res[cnt++] = node->val;
            f = (f + 1) % MAX_NODE;
        }
    }
    
    return cnt;
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int **res = (int **)malloc(sizeof(int *) * MAX_NODE);
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_NODE);
    *returnSize = 0;
    queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX_NODE);

    rear = 0;
    front = 0;
    enQueue(queue, root);

    while (front != rear) {
        res[*returnSize] = (int *)malloc(sizeof(int) * pow(2, *returnSize));
        (*returnColumnSizes)[*returnSize] = printQueue(queue, res[*returnSize], (*returnSize + 1) & 1, front, rear);
        (*returnSize)++;
        int tmp_rear = rear;
        while (front != tmp_rear) {
            enQueue(queue, queue[front]->left);
            enQueue(queue, queue[front]->right);
            deQueue(queue);
        }
    }
    return res;
}
```