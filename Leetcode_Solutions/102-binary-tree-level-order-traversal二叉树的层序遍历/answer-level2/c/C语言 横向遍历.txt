### 解题思路
用一个队列保存待处理层的节点，在处理完一层之后，就增加一个结果
![image.png](https://pic.leetcode-cn.com/2d89c74554bb15913ca04aa1bfc28c4b7b3d520fc5302c24caaf5ffa0bfac355-image.png)

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
#define MY_OK 0
#define MY_FAIL (-1)

#define MY_BASE_SIZE 1024
typedef struct {
    struct TreeNode **queue;
    int size;
    int cnt;
    int head;
    int tail; 
} MyQ;
void qFree(MyQ *q)
{
    if (q->queue != NULL) {
        free(q->queue);
        q->queue = NULL;
    }
    return;
}
int qInit(MyQ *q)
{
    q->size = MY_BASE_SIZE;
    q->queue = (struct TreeNode**)calloc(q->size, sizeof(struct TreeNode*));
    if (q->queue == NULL) {
        return MY_FAIL;
    }
    q->cnt = 0;
    q->head = q->tail = 0;
    return MY_OK;
}
void qPush(MyQ *q, struct TreeNode *item)
{
    if (q->cnt == q->size) {
        printf("qPush error\n");
        return;
    }
    q->queue[q->tail] = item;
    q->tail = (q->tail + 1) % q->size;
    q->cnt += 1;
    return;
}
void qPop(MyQ *q, struct TreeNode **item)
{
    if (q->cnt == 0) {
        *item = NULL;
        return;
    }
    *item = q->queue[q->head];
    q->head = (q->head + 1) % q->size;
    q->cnt--;
    return;
}
void qPeekTail(MyQ *q, struct TreeNode **item)
{
    if (q->cnt == 0) {
        *item = NULL;
        return;
    }
    *item = q->queue[(q->head + q->cnt - 1) % q->size];
    return;
}
int qIsEmpty(MyQ *q)
{
    if (q->cnt != 0) {
        return MY_FAIL;
    }
    return MY_OK;
}

typedef struct {
    int **rlt;
    int *returnColumnSizes;
    int cnt;
    int size;
} MyRlt;
void rFree(MyRlt *r)
{
    if (r->rlt != NULL) {
        free(r->rlt);
        r->rlt = NULL;
    }
    if (r->returnColumnSizes != NULL) {
        free(r->returnColumnSizes);
        r->returnColumnSizes = NULL;
    }
    return;
}
int rInit(MyRlt *r)
{
    r->size = MY_BASE_SIZE;
    r->rlt = (int**)calloc(r->size, sizeof(int*));
    if (r->rlt == NULL) {
        return MY_FAIL;
    }
    r->returnColumnSizes = (int*)calloc(r->size, sizeof(int));
    if (r->returnColumnSizes == NULL) {
        free(r->rlt);
        return MY_FAIL;
    }
    r->cnt = 0;
    return MY_OK;
}
int g_cur[MY_BASE_SIZE];
void process(MyRlt *r, MyQ *q)
{
    int curcnt;
    int *curArr = NULL;
    struct TreeNode *cur = NULL;
    struct TreeNode *tail = NULL;
    qPeekTail(q, &tail);
    curcnt = 0;
    while (qIsEmpty(q) != MY_OK) {
        qPop(q, &cur);
        g_cur[curcnt++] = cur->val;
        if (cur->left != NULL) {
            qPush(q, cur->left);
        }
        if (cur->right != NULL) {
            qPush(q, cur->right);
        }
        if (cur == tail) {
            curArr = (int*)calloc(curcnt, sizeof(int));
            if (curArr == NULL) {
                printf("curArr error\n");
                return;
            }
            memcpy(curArr, g_cur, curcnt * sizeof(int));
            r->rlt[r->cnt] = curArr;
            r->returnColumnSizes[r->cnt] = curcnt;
            r->cnt++; 
            qPeekTail(q, &tail);
            curcnt = 0;
        }
    }
    return;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int ret;
    MyRlt r;
    MyQ q;
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    ret = rInit(&r);
    ret |= qInit(&q);
    if (ret != MY_OK) {
        rFree(&r);
        qFree(&q);
        return NULL;
    }
    qPush(&q, root);
    process(&r, &q);
    qFree(&q);
    *returnSize = r.cnt;
    *returnColumnSizes = r.returnColumnSizes;
    return r.rlt;
}
```