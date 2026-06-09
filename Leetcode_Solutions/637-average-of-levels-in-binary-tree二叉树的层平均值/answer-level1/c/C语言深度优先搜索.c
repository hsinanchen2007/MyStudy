### 解题思路
深度搜索遍历每层，每层的数据使用一个链表保存（提前知道最大深度可以直接用数组）。

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
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define PRINTF printf
typedef struct stAvaNode {
    double val;
    int size;
    struct stAvaNode *pNext;
}STAVANODE;
int maxDeepth = 0;
STAVANODE * NewInitNode()
{
    STAVANODE *pNode = (STAVANODE *)malloc(sizeof(STAVANODE));
    pNode->val = 0;
    pNode->size = 0;
    pNode->pNext = NULL;
    return pNode;
}
void * FreeNode(STAVANODE *pCur)
{
    if (pCur == NULL) {
        return;
    }
    FreeNode(pCur->pNext);
    free(pCur);
}
void DfsSearch(STAVANODE *pAvaNode, struct TreeNode* pCurNode, int *pDeepth)
{
    if(pCurNode == NULL) {
        return;
    }
    PRINTF("%p\n",pAvaNode);
    pAvaNode->val += pCurNode->val;
    (pAvaNode->size)++;
    if(pAvaNode->pNext == NULL){
        pAvaNode->pNext = NewInitNode();
    }
    (*pDeepth)++;
    maxDeepth = MAX(maxDeepth, *pDeepth);
    DfsSearch(pAvaNode->pNext, pCurNode->left, pDeepth);
    DfsSearch(pAvaNode->pNext, pCurNode->right, pDeepth);
    (*pDeepth)--;
}
double* averageOfLevels(struct TreeNode* root, int* returnSize)
{
    STAVANODE stAvaNode = {0, 0, NULL};
    int iDeepth = 0;
    maxDeepth = 0;
    DfsSearch(&stAvaNode, root, &iDeepth);
    *returnSize = maxDeepth;
    if (maxDeepth == 0) {
       return NULL; 
    }
    double* pRet = (double *)malloc(maxDeepth * sizeof(double));
    STAVANODE* pCurAvaNode = &stAvaNode;
    int index = 0;
    while((pCurAvaNode != NULL) && (maxDeepth > 0)){
        pRet[index] = ((pCurAvaNode->val) / (pCurAvaNode->size));
        index++;
        pCurAvaNode = pCurAvaNode->pNext;
        maxDeepth--;
    }
    FreeNode(pCurAvaNode->pNext);
    return pRet;
    
}
```