### 解题思路
此处撰写解题思路
基本思路:
1.将所有向量边加入到有向图中，有向图的结构需要包含父节点和当前二维数组索引，单个节点可能有两个父亲，全部扫描完后处理，不要再扫描的过程中处理，后面没有加入的节点会对前面的判断有影响
2.确认是否有一个节点有两个父节点，没有的话找形成的环，去掉最大索引的节点即可
### 代码

```c
#define INVAL (-1)
#define RETURN_SIZE 2
#define MAX_PARRENT_NUM 2
#define MIN_ARR_NUM 3
#define MAX_ARR_NUM 1001

typedef struct {
    int parrent[MAX_PARRENT_NUM];
    int edgeIndex[MAX_PARRENT_NUM];
}NodeTag;

typedef struct {
    NodeTag **ptag;
    int size;
}UfsTag;

int Max(int a, int b到
{
    if (a > b) {
        return a;
    }
    return b;
}

UfsTag* UfsCreate(int k)
{
    int index;
    UfsTag* pufs = NULL;

    if (k <= 0) {
        return NULL;
    }

    pufs = (UfsTag *) malloc(sizeof(UfsTag));
    if (pufs == NULL) {
        return NULL;
    }
    pufs->size = k;
    pufs->ptag = (NodeTag **)malloc(sizeof(NodeTag*) * k);

    for (index = 0; index < k; index++) {
        pufs->ptag[index] = (NodeTag *)malloc(sizeof(NodeTag));
        pufs->ptag[index]->parrent[0] = INVAL;
        pufs->ptag[index]->parrent[1] = INVAL;
        pufs->ptag[index]->edgeIndex[0] = INVAL;
        pufs->ptag[index]->edgeIndex[1] = INVAL;
    }

    return pufs;
}

int UfsFindCircle(UfsTag* pufs, int index)
{
    int cnt = 0;
    int maxRow = 0;
    int tmp = index;
    
    //printf("find circle:index = %d\n", index);

    while (pufs->ptag[tmp]->parrent[0] > 0) {
        maxRow = Max(pufs->ptag[tmp]->edgeIndex[0], maxRow);
        //printf("find circle:parrent[0] = %d\n", 
        //pufs->ptag[tmp]->parrent[0]);
        tmp = pufs->ptag[tmp]->parrent[0];
        cnt++;

        if (tmp == index) {
            //printf("index= %d, maxrow=%d\n", index, maxRow);
            return maxRow;
        }
        if (cnt >= pufs->size) {
            break;
        }

    }

    return 0;
}

int HaveTwoParrent(UfsTag* pufs)
{
    int index;

    for (index = 0; index < pufs->size; index++) {
        if (pufs->ptag[index]->parrent[0] > 0 &&
            pufs->ptag[index]->parrent[1] > 0) {
            return index;
        }
    }

    return -1;
}


int UfsJoint(UfsTag* pufs, int x, int y, int row)
{
    if (pufs->ptag[y]->parrent[0] > 0 && 
        pufs->ptag[y]->parrent[1] > 0) {
        return -1;
    }

    if (pufs->ptag[y]->parrent[0] <= 0) {
        pufs->ptag[y]->parrent[0] = x;
        pufs->ptag[y]->edgeIndex[0] = row;        
    } else {
        pufs->ptag[y]->parrent[1] = x;
        pufs->ptag[y]->edgeIndex[1] = row;        
    }
    
    return 0;
}


void UfsDestroy(UfsTag* pufs)
{
    int index;

    if (pufs != NULL) {
        if (pufs->ptag != NULL) {
            for (index = 0; index < pufs->size; index++) {
                if (pufs->ptag[index] != NULL) {
                    free(pufs->ptag[index]);
                    pufs->ptag[index] = NULL;
                }            
            }
            free(pufs->ptag);
            pufs->ptag = NULL;            
        }
        free(pufs);
        pufs = NULL;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int row;
    int result;
    int last = 0;
    int* parr = NULL;
    UfsTag* pedge = NULL;

    *returnSize = 0;

    if (edges == NULL || edgesColSize == NULL || edgesSize < MIN_ARR_NUM) {
        printf("edge NULL\n");
        return NULL;
    }

    pedge = UfsCreate(MAX_ARR_NUM);
    if (pedge == NULL) {
        printf("ufs create\n");
        return NULL;
    }

    for (row = 0; row < edgesSize; row++) {
        if (UfsJoint(pedge, edges[row][0], edges[row][1], row) < 0) {
            printf("joint fail\n");
            goto EXIT;
        }
    }

    result = HaveTwoParrent(pedge);
    //printf("result = %d\n", result);

    if (result > 0) {
        if (UfsFindCircle(pedge, pedge->ptag[result]->parrent[0]) > 0 ) {
            last = pedge->ptag[result]->edgeIndex[0];
        } else if (UfsFindCircle(pedge, pedge->ptag[result]->parrent[1]) > 0){
            last = pedge->ptag[result]->edgeIndex[1];
        } else {
            last = Max(pedge->ptag[result]->edgeIndex[0],pedge->ptag[result]->edgeIndex[1]);
        }
    } else {
        for (row = 1; row < pedge->size; row++) {
            result = UfsFindCircle(pedge, row);
            if (result > 0) {
                last = result;
                //printf("####last= %d\n",last);
            }
        }

    }
    
    parr = (int* )malloc(sizeof(int) * RETURN_SIZE);
    if (parr == NULL) {
        printf("malloc err\n");
        goto EXIT;
    }
    
    parr[0] = edges[last][0];
    parr[1] = edges[last][1];
    *returnSize = RETURN_SIZE;

EXIT:
    UfsDestroy(pedge);
    return parr;
}
```