### 解题思路
拓扑排序
1 构建邻接矩阵
2 广度搜索入度为0的顶点

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct stCourses{ // 当前课程编号通过索引确定
    int depNum; // 当前节点被依赖个数
    int conNum; // 子节点的个数
    int *pCourses; // 子节点信息
}STCOURSES;
#define PRINTF // printf
typedef struct stQueon{
    int head;
    int rear;
    int maxQueon;
    int *val;
}STQUEON;

void FreeQueon(STQUEON *pQueon)
{
    if((pQueon == NULL) || (pQueon->val == NULL)) {
        return;
    }
    free(pQueon->val);
}
bool InitQueon(STQUEON *pQueon, int num)
{
    if(pQueon == NULL) {
        return false;
    }
    pQueon->head = 0;
    pQueon->rear = 0;
    pQueon->maxQueon = (num + 1);
    pQueon->val = (int *)malloc((num + 1) * sizeof(int));
    if(pQueon->val == NULL) {
        return false;
    }
    return true;
}
bool PushQueon(STQUEON *pQueon, int courseNum)
{
    if((pQueon == NULL) || (((pQueon->rear + 1) % (pQueon->maxQueon)) == pQueon->head)) {
        PRINTF("PushQueon:%d %d\n", pQueon->head, pQueon->rear);
        return false;
    }
    pQueon->val[pQueon->rear] = courseNum;
    pQueon->rear = ((pQueon->rear + 1) % (pQueon->maxQueon));
    return true;
}
bool PopQueon(STQUEON *pQueon, int *courseNum)
{
    if((pQueon == NULL) || ((pQueon->rear) == (pQueon->head))) {
        return false;
    }
    *courseNum = pQueon->val[pQueon->head];
    pQueon->head = ((pQueon->head + 1) % (pQueon->maxQueon));
    return true;
}
void FreeCourses(int count, STCOURSES *pCourses, int *pRet)
{
    if(pRet != NULL) {
        free(pRet);
    }
    if(pCourses == NULL) {
        return;
    }
    for(int i = 0; i < count; i++) {
        if(pCourses[i].pCourses != NULL) {
            free(pCourses[i].pCourses);
        }
    }
    free(pCourses);
}
bool InitCourses(int count, STCOURSES **pCourses, int **pRet)
{
    if ((pCourses == NULL) || (pRet == NULL)) {
        return false;
    }
    *pCourses = (STCOURSES *)malloc(count * sizeof(STCOURSES));
    if(*pCourses == NULL) {
        goto ERR;
    }
    for (int i = 0; i < count; i++) {
        (*pCourses)[i].pCourses = (int *)malloc(count * sizeof(STCOURSES));
        if((*pCourses)[i].pCourses == NULL) {
            goto ERR;
        }
        (*pCourses)[i].depNum = 0;
        (*pCourses)[i].conNum = 0;
    }
    *pRet = (int *)malloc(count * sizeof(int));
    if (*pRet == NULL) {
        goto ERR;
    }
    return true;
ERR:
    FreeCourses(count, *pCourses, *pRet);
    return false;
}

bool DfsFindOrder(STCOURSES *pCourses, int numCourses, int* returnSize, int *pRet)
{
    STQUEON pQueon = { 0 };
    *returnSize = 0;
    int bRet = InitQueon(&pQueon, numCourses);
    if(bRet == false) {
        goto ERR;
    }
    for(int i = 0; i < numCourses; i++) {
        if(pCourses[i].depNum != 0) { // 被依赖，不能开始
            continue;
        }
        bRet = PushQueon(&pQueon, i);
        if((bRet == false) || ((*returnSize) >= numCourses)) {
            goto ERR;
        }
        PRINTF("Push 1:%d %d\n",i, pCourses[i].depNum);
    }
    while((pQueon.rear) != (pQueon.head)){
        int curCount = 0;
        bRet = PopQueon(&pQueon, &curCount);
        if(bRet == false) {
            PRINTF("Pop 1 failed!\n");
            goto ERR;
        }
        pRet[(*returnSize)] = curCount;
        (*returnSize)++;
        for (int j = 0; j < pCourses[curCount].conNum; j++) { //刷新依赖关系
            int childCoures = pCourses[curCount].pCourses[j];
            pCourses[childCoures].depNum--;
        }
        PRINTF("Pop 1:%d\n",curCount);
        int curCountNum = pCourses[curCount].conNum; // 当期子节点个数
        for(int i = 0; i < curCountNum; i++){
            int subCount = pCourses[curCount].pCourses[i];
            if(pCourses[subCount].depNum != 0) { // 子节点被依赖了，不能作为开始
                continue;
            }
            bRet = PushQueon(&pQueon, subCount);
            if((bRet == false) || ((*returnSize) > numCourses)) {
                PRINTF("Push failed!%d %d\n",numCourses, *returnSize);
                goto ERR;
            }
            PRINTF("Push 2:%d\n",subCount);
        }

    }
    if (*returnSize != numCourses) {
        bRet = false;
        goto ERR;
    }
ERR:
    FreeQueon(&pQueon);
    return bRet;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    STCOURSES *pCourses = NULL;
    int *pRet = NULL;
    *returnSize = 0;
    if ((prerequisitesColSize == NULL) && (*prerequisitesColSize != 2)) {
        goto ERR;
    }
    int bRet = InitCourses(numCourses, &pCourses, &pRet);
    if(bRet == false) {
        goto ERR;
    }
    for(int i = 0; i < prerequisitesSize; i++) {
        int depCourse = prerequisites[i][0];
        int curCourse = prerequisites[i][1];
        int conIndex = pCourses[curCourse].conNum;
        pCourses[curCourse].pCourses[conIndex] = depCourse;
        pCourses[curCourse].conNum++; // 当前子节点数量
        pCourses[depCourse].depNum++; // 当前节点被依赖数
        PRINTF("depCourse:%d %d\n",pCourses[depCourse].depNum , depCourse);
    }
    bRet = DfsFindOrder(pCourses, numCourses, returnSize, pRet);
    if(bRet == false){
        PRINTF("DFS failed!\n");
        goto ERR;
    }
    return pRet;
ERR:
    FreeCourses(numCourses, pCourses, pRet);
    *returnSize = 0;
    return NULL;
}
```