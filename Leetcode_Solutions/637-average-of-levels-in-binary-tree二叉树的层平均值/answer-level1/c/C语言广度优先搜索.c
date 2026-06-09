### 解题思路
广度优先搜索，层序遍历每一层
需要注意，这里入队列的是指针

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
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXSIZE 2000
#define PRINTF // printf
typedef struct stQue{
    int size;
    int head;
    int rear;
    struct TreeNode **pNode;
}STQUE;
typedef struct stNode{
    double val;
    struct stNode *pNext;
}STNODE;
STNODE* InitNode()
{
    STNODE* pRet = (STNODE*)malloc(sizeof(STNODE));
    pRet->val = 0;
    pRet->pNext = NULL;
    return pRet;
}
void FreeNode(STNODE* pCurNode)
{
    if(pCurNode == NULL) {
        return;
    }
    FreeNode(pCurNode->pNext);
    free(pCurNode);
}
STQUE* InitQueon()
{
    STQUE* pQue = (STQUE*)malloc(sizeof(STQUE));
    pQue->size = MAXSIZE;
    pQue->head = 0;
    pQue->rear = 0;
    pQue->pNode = (struct TreeNode **)malloc(MAXSIZE * sizeof(struct TreeNode *));
    for(int i = 0; i < MAXSIZE; i++) {
        pQue->pNode[i] = NULL;
    }
    return pQue;
}
void FreeQueon(STQUE* pQue)
{
    if(pQue == NULL) {
        return;
    }
    free(pQue->pNode);
    free(pQue);
}
bool PushQue(STQUE* pQue, struct TreeNode *pCur)
{
    if(((pQue->rear + 1) % pQue->size)  == pQue->head) 
    {
        return false;
    }
    pQue->pNode[pQue->rear] = pCur;
    pQue->rear = ((pQue->rear + 1) % pQue->size);
    return true;
}
void PopQue(STQUE* pQue, struct TreeNode **pCur)
{
    *pCur = pQue->pNode[pQue->head];
    pQue->head = ((pQue->head + 1) % pQue->size);
    return;
}
bool EmptyQue(STQUE* pQue)
{
    if(pQue->head == pQue->rear) 
    {
        return true;
    }
    return false;
}
bool FullQue(STQUE* pQue)
{
    if(((pQue->rear + 1) % pQue->size)  == pQue->head) 
    {
        return true;
    }
    return false;
}
inline int SizeQue(STQUE* pQue)
{
    return ((pQue->rear + pQue->size - pQue->head) % pQue->size);
}
void BfsSearch(struct TreeNode* pCurTree, STQUE* pQue, STNODE *pCurNode, int *pDeepth)
{
    if(pCurTree == NULL) {
        return;
    }
    PushQue(pQue, pCurTree);
    while (EmptyQue(pQue) == false) {
        int curSize = SizeQue(pQue);
        int curNum = curSize;
        PRINTF("%d\n", curSize);
        (*pDeepth)++;
        while(curSize > 0){
            struct TreeNode* pCur = NULL;
            PopQue(pQue, &pCur);
            pCurNode->val += pCur->val;
            if(pCur->left != NULL){
                (void)PushQue(pQue, pCur->left);
            }
            if(pCur->right != NULL){
                (void)PushQue(pQue, pCur->right);
            }
            curSize--;
        }
        pCurNode->val /= curNum;
        if (pCurNode->pNext == NULL) {
            pCurNode->pNext = InitNode();
        }
        pCurNode = pCurNode->pNext;
    }
}
double* averageOfLevels(struct TreeNode* root, int* returnSize){
    STQUE* pQue = InitQueon();
    STNODE stNode = {0, NULL};
    int iDeepth = 0;
    BfsSearch(root, pQue, &stNode, &iDeepth);
    *returnSize = 0;
    if(iDeepth == 0) {
        return NULL;
    }
    *returnSize = iDeepth;
    double *pRet = (double *)malloc(iDeepth * sizeof(double));
    int curIndex = 0;
    STNODE *pCur = &stNode;
    int index = 0;
    for(index = 0; index < iDeepth; index++) {
        if(pCur->pNext == NULL){
            break;
        }
        pRet[index] = pCur->val;
        pCur = pCur->pNext;
    }
    FreeNode(stNode.pNext);
    FreeQueon(pQue);
    *returnSize = index;
    return pRet;
}


```