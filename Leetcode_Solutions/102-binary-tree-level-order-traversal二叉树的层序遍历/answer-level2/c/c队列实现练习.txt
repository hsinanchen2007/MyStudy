### 解题思路
此处撰写解题思路
c队列实现练习

### 代码

```c
#define MAX_SIZE 1000
typedef struct {
    int front;
    int rear;
    int qsize;
    struct TreeNode *data[MAX_SIZE];
} Queue;

void QueIn(Queue *q, struct TreeNode *node)
{
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = node;
    (q->qsize)++;
}

 struct TreeNode *QueOut(Queue *q)
{
    q->front = (q->front + 1) % MAX_SIZE;
    (q->qsize)--;
    return q->data[q->front];
}

void QueInit(Queue *q)
{
    q->front = -1;
    q->rear = -1;
    q->qsize = 0;
    memset(q->data, 0, sizeof(struct TreeNode *) * MAX_SIZE);
}

int GetTreeDepth(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }

    int left = GetTreeDepth(root->left);
    int right = GetTreeDepth(root->right);

    return (left > right) ? left + 1 : right + 1;
}

void FillArr(Queue *q, struct TreeNode* root, int **result, int** returnColumnSizes)
{
    int curDepth = 0;
    int curDepthIdx = 0;
    int curQueLen = 0;
    struct TreeNode *node;
    QueIn(q, root); //root 入队

    while(q->qsize != 0) {
        curQueLen = q->qsize;
        (*returnColumnSizes)[curDepth] = curQueLen;
        result[curDepth] = (int *)malloc(sizeof(int) * curQueLen);
        if (result[curDepth] == NULL) {
            return ;
        }

        curDepthIdx = 0;
        while (curQueLen != 0) {
            node = QueOut(q);
            result[curDepth][curDepthIdx] = node->val;
            curDepthIdx++;

            if (node->left != NULL) {
                QueIn(q, node->left);
            }

            if (node->right != NULL) {
                QueIn(q, node->right);
            }

            curQueLen--;
        }

        curDepth++;        
    }

}
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
Queue q;

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL || returnColumnSizes == NULL) {
        *returnSize = 0;
        return NULL;
    }

    if (returnSize == NULL) {
        return NULL;
    }

    int treeDepth = GetTreeDepth(root);
    *returnSize = treeDepth;
    *returnColumnSizes = (int *)malloc(sizeof(int) * treeDepth);

    int **result = (int **)malloc(sizeof(int *) * treeDepth);

    QueInit(&q);
    FillArr(&q, root, result, returnColumnSizes);
    return result;

}
```