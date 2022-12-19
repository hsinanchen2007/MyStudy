### 解题思路

![image.png](https://pic.leetcode-cn.com/f93e9189a4c250b90489b66d2c337efe208883ed74621673bd29131ffa194fa4-image.png)

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
#define MY_MAX_DEP 1024
typedef struct {
    int cur[MY_MAX_DEP];
    int cnt;
    int size;
} MyStatus;

void sInit(MyStatus *s)
{
    s->cnt = 0;
    s->size = MY_MAX_DEP;
    return;
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
    r->cnt = 0;
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
int rAdd(MyRlt *r, MyStatus *s)
{
    int *newItem = NULL;
    newItem = (int*)calloc(s->cnt, sizeof(int));
    if (newItem == NULL) {
        return MY_FAIL;
    }
    memcpy(newItem, s->cur, s->cnt * sizeof(int));
    r->returnColumnSizes[r->cnt] = s->cnt;
    r->rlt[r->cnt] = newItem;
    r->cnt++;
    return MY_OK;
}
bool isLeaf(struct TreeNode* node)
{
    return (node->left == NULL) && (node->right == NULL); 
}
void process(struct TreeNode* node, MyRlt *r, MyStatus *s, int left)
{
    int ret, cnt;
    if (node == NULL) {
        return;
    }
    cnt = s->cnt;
    s->cur[cnt] = node->val;
    s->cnt++;
    if (s->cnt == s->size) {
        printf("status buffer is not enough\n");
        return;
    }
    left -= node->val;
    if (left == 0 && isLeaf(node)) {
        ret = rAdd(r, s);
        if (ret != MY_OK) {
            printf("radd error\n");
            rFree(r);
        }
        s->cnt = cnt;
        return;
    }
    
    if (node->left != NULL) {
        process(node->left, r, s, left);
    }
    if (node->right != NULL) {
        process(node->right, r, s, left);
    }
    s->cnt = cnt;
    return;
}
void traceR(MyRlt *r)
{
    int i, j;
    printf("r->cnt = %d\n", r->cnt);
    for (i = 0; i < r->cnt; i++) {
        printf("returnColumnSizes[%d] = %d, ", i, r->returnColumnSizes[i]);
        for (j = 0; j < r->returnColumnSizes[i]; j++) {
            printf(" %d,", r->rlt[i][j]);
        }
        printf("\n");
    }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    int ret;
    MyRlt r;
    MyStatus s;
    sInit(&s);
    ret = rInit(&r);
    if (ret != MY_OK) {
        *returnSize = 0;
        return NULL;
    }
    process(root, &r, &s, sum);
    //traceR(&r);
    *returnSize = r.cnt;
    *returnColumnSizes = r.returnColumnSizes;
    return r.rlt;
}
```