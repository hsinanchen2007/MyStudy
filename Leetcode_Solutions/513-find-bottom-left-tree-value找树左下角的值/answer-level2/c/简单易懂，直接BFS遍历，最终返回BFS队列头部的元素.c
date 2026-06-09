利用广度优先遍历算法遍历所有的子节点，当到达最底层时，所有的节点都无左右字树时直接返回队列头部的元素。
```
#define MAX_BUFFER     10000
int findBottomLeftValue(struct TreeNode* root){
    int index = 0;
    int indexSub = 0;
    int retValue = 0;
    int arriveEndLevel = 1;
    struct TreeNode **fifo = NULL;
    struct TreeNode **fifoTemp = NULL;
    fifo = malloc(MAX_BUFFER * sizeof(struct TreeNode *));
    memset(fifo, 0, MAX_BUFFER * sizeof(struct TreeNode *));
    fifoTemp = malloc(MAX_BUFFER * sizeof(struct TreeNode *));
    memset(fifoTemp, 0, MAX_BUFFER * sizeof(struct TreeNode *));
    fifo[0] = root;
TRY_AGAIN:
    while (fifo[index] != NULL) {
        if (fifo[index]->left != NULL) {
            arriveEndLevel = 0;
            fifoTemp[indexSub++] = fifo[index]->left;
        }
        if (fifo[index]->right != NULL) {
            arriveEndLevel = 0;
            fifoTemp[indexSub++] = fifo[index]->right;
        }
        index++;
    }
    if (arriveEndLevel == 0) {
        /* 还没有到达最底层，继续遍历 */
        memcpy(fifo, fifoTemp, MAX_BUFFER * sizeof(struct TreeNode *));
        memset(fifoTemp, 0, MAX_BUFFER * sizeof(struct TreeNode *));
        arriveEndLevel = 1;
        index = 0;
        indexSub = 0;
        goto TRY_AGAIN;
    } else {
        /* 到达最底层,直接返回fifo队头的数据即可 */
        retValue = fifo[0]->val;
        free(fifo);
        free(fifoTemp);
        return retValue;
    }
}
```
