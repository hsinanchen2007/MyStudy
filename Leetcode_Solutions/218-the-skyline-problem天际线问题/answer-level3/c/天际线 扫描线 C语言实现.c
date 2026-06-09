
先说用例： 

    1，用例有空输入，此时应返回 *returnSize 为 0
    2，用例有大量一个building被另外一个覆盖情况，本解法会超时，要先去重复

再说解法，其实就是扫描线法。但是C实现比较麻烦，毕竟没有很多好用的库。

    1，去除一栋建筑明显被其他一栋覆盖情况 （后续还可以合并高度相同相连情况）
    2，以所有建筑的左右边创建有序链表scan，其内容为另外一个链表edges
    3，edges存放有1到n个建筑的信息，并标记左边还是右边。
    4，循环扫描各建筑，如果建筑b的左右之间有坐标x在scan中，则x对应的edges链表应添加b的左边信息。
    5，至此，scan信息的扫描线信息应该已经完整了。
    6，依次遍历scan数组的各x坐标，每个坐标下的最高高度就是即将开始的新高度。


在C中时间结果很差，击败5%，内存结果150MB击败100%. 
其实不论时间还是空间，代码应该还有很大优化空间。暂时不折腾了。


以下代码中的 list queue 和 array实现参考本人其他题解。

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "common.h"
#include "my_list.h"
#include "my_array.h"

#define BID_LEFT    0
#define BID_RIGHT   1
#define BID_HEIGHT  2

typedef struct _SCAN_ITEM {
    int *building;  // building[3]
    char pos;
} SCAN_ITEM;

static void ScanBuildingsFree(void *element)

    LIST *edges = *(LIST **) element;
    if (edges == NULL) {
        return;
    }
    List_Destroy(edges);
}

static inline SCAN_ITEM *GetFirstEdge(LIST *edges)
{
    SCAN_ITEM *item;
    if (edges == NULL) {
        return NULL;
    }
    if (edges->count == 0) {
        return NULL;
    }
    item = (SCAN_ITEM *) List_GetElement(edges, edges->head);
    return item;
}

static int Scan_FindNode(void *element, void *param)
{
    int axisX = *((int *) param);
    SCAN_ITEM *e = GetFirstEdge(*(LIST **) element);
    if (e == NULL) {
        return -1;
    }
    if (e->building[e->pos] == axisX) {
        return 0;
    }
    return -1;
}

static int Scan_FindPrevNode(void *element, void *param)
{
    int axisX = *((int *) param);
    SCAN_ITEM *e = GetFirstEdge(*(LIST **) element);
    if (e == NULL) {
        return -1;
    }
    if (e->building[e->pos] < axisX) {
        // LOG("Scan_FindPrevNode: found %d\n", e->building[e->pos]);
        return 0;
    }
    return -1;
}

static inline LIST *Scan_GetEdges(LIST *scan, NODE *scan_node)
{
    return *(LIST **) List_GetElement(scan, scan_node);
}

static inline int ScanNode_GetAxisX(LIST *scan, NODE *scan_node)
{
    SCAN_ITEM *item = GetFirstEdge(Scan_GetEdges(scan, scan_node));
    return item->building[item->pos];
}

static int InsertEdgeToScan(LIST *edges, int axisX, LIST *scan)
{
    NODE *prev;

    if (scan->count == 0) {
        return List_Append(scan, &edges);
    }
    prev = List_RFind(scan, NULL, Scan_FindPrevNode, &axisX);
    if (prev == NULL) {
        return List_InsertAfter(scan, NULL, &edges);
    } else {
        return List_InsertAfter(scan, prev, &edges);
    }
}

static int AddEdgeToScan(SCAN_ITEM *item, LIST *scan)
{
    int axisX;
    NODE *scanNode;
    LIST *edges;
    axisX = item->building[item->pos];
    scanNode = List_RFind(scan, NULL, Scan_FindNode, &axisX);
    if (scanNode == NULL) {
        // LOG("AddEdgeToScan: create at axis %d for edge_mode=%d\n", axisX, item->pos);
        edges = List_Create(sizeof(SCAN_ITEM), NULL);
        List_Append(edges, item);
        InsertEdgeToScan(edges, axisX, scan);
    } else {
        // LOG("AddEdgeToScan: append at axis %d for edge_mode=%d\n", axisX, item->pos);
        edges = Scan_GetEdges(scan, scanNode);
        List_Append(edges, item);
    }
    return 0;
}

static int AddToScan(int *building, LIST *scan)
{
    char pos[] = {BID_LEFT, BID_RIGHT};
    SCAN_ITEM item;
    item.building = building;
    for (int i = 0; i < (int) ARRAY_COUNT(pos); i++) {
        item.pos = pos[i];
        AddEdgeToScan(&item, scan);
    }
    return 0;
}

static int EdgesGetMaxHeight(LIST *edges)
{
    NODE *edge_node;
    SCAN_ITEM *e;
    int height = 0;
    for (edge_node = edges->head; edge_node != NULL; edge_node = edge_node->next) {
        e = (SCAN_ITEM *) List_GetElement(edges, edge_node);
        LOG(" %c[%2d, %2d, %2d] ", e->pos ? 'R' : 'L', e->building[0], e->building[1], e->building[2]);
        if (e->pos == BID_RIGHT) {
            continue;
        }

        if (height < e->building[BID_HEIGHT]) {
            height = e->building[BID_HEIGHT];
        }
    }
    LOG("height: %3d\n", height);
    return height;
}

static int UpdateOneEdgeRange(LIST *scan, NODE *scanNode)
{
    NODE *edge_node, *scanStart;
    SCAN_ITEM *e;
    int left, right, x;
    LIST *edges = Scan_GetEdges(scan, scanNode);
    for (edge_node = edges->head; edge_node != NULL; edge_node = edge_node->next) {
        e = (SCAN_ITEM *) List_GetElement(edges, edge_node);
        if (e->pos != BID_LEFT) {
            continue;
        }
        left = e->building[BID_LEFT];
        right = e->building[BID_RIGHT];
        scanStart = scanNode->next;
        while (scanStart != NULL) {
            x = ScanNode_GetAxisX(scan, scanStart);
            if (left < x && x < right) {
                // TODO: 此处需要检查重复
                List_Append(Scan_GetEdges(scan, scanStart), e);
            }
            scanStart = scanStart->next;
        }
    }
    return 0;
}

static int FillBuildingLeftToScan(LIST *scan, NODE **scanStart, SCAN_ITEM *build)
{
    NODE *scanNode, *nextStart;
    int axisX = 0;
    axisX = build->building[BID_LEFT];
    nextStart = List_Find(scan, *scanStart, Scan_FindNode, &axisX);
    for (scanNode = nextStart; scanNode != NULL; scanNode = scanNode->next) {
        axisX = ScanNode_GetAxisX(scan, scanNode);
        if (axisX <= build->building[BID_LEFT]) {
            continue;
        }
        if (axisX >= build->building[BID_RIGHT]) {
            break;
        }
        List_Append(Scan_GetEdges(scan, scanNode), build);
    }

    *scanStart = nextStart;
    return 0;
}

static int FillBuildingsToScan(LIST *scan, INT_ARRAY2 *buildings)
{
    NODE *scanStart = NULL;
    SCAN_ITEM item;
    for (int r = 0; r < buildings->size.row; r++) {
        if (buildings->p[r][0] == -1) {
            continue;
        }
        item.building = buildings->p[r];
        item.pos = BID_LEFT;
        FillBuildingLeftToScan(scan, &scanStart, &item);
    }

    return 0;
}

static int ScanListToResult(LIST *scan, QUEUE *result)
{
    int last;
    LIST *edges;
    NODE *scanNode;
    LL res;
    last = 0;
    for (scanNode = scan->head; scanNode != NULL; scanNode = scanNode->next) {
        edges = Scan_GetEdges(scan, scanNode);
        // 依据当前坐标点下，所有边的信息，获取即将开始的新高度。
        res.x = ScanNode_GetAxisX(scan, scanNode);
        LOG("axisX: %3d, ", res.x);
        res.y = EdgesGetMaxHeight(edges);
        if (res.y != last) {
            Queue_Push(result, &res);
        }
        last = res.y;
    }
    return 0;
}

static int CalcSkyLine(INT_ARRAY2 *buildings, LIST *scan, QUEUE *result)
{
    // 将各建筑的左右两边分别输出到按x坐标排序list. 一个坐标下有1～n个信息。
    // TODO: 可以优化成一个数组，然后使用通用算法排序。
    for (int r = 0; r < buildings->size.row; r++) {
        if (buildings->p[r][0] == -1) {
            continue;
        }
        AddToScan(buildings->p[r], scan);
    }
    // 各个坐标下，增添所有存在的buildings信息。
    FillBuildingsToScan(scan, buildings);
    // 每个x扫描坐标下，根据高度信息，输出到结果队列。
    ScanListToResult(scan, result);
    return 0;
}

static int **ResultToArray(QUEUE *result, int *returnSize, int **returnColumnSizes)
{
    int **ret, i = 0;
    LL res;
    INT_ARRAY2 *lines = IntArray2_Create(result->count, 2, 0);
    *returnColumnSizes = IntArray_Create(result->count, 2);
    *returnSize = result->count;
    while (!Queue_IsEmpty(result)) {
        Queue_Pop(result, &res);
        lines->p[i][0] = res.x;
        lines->p[i][1] = res.y;
        i++;
    }
    ret = lines->p;
    IntArray2_Detach(lines);
    return ret;
}

static inline int IsOverlap(int *big, int *small)
{
    if (*big == -1 || *small == -1) {
        return 0;
    }
    if(small[0] >= big[0] && small[1] <= big[1] && small[2] <= big[2]){
        return 1;
    }
    return 0;
}

static int CleanOverlapBuildings(INT_ARRAY2 *buildings)
{
    for (int r = 1; r < buildings->size.row; r++) {
        if (buildings->p[r][0] == -1) {
            continue;
        }
        for (int j = 0; j < r; j++) {
            if (IsOverlap(buildings->p[j],buildings->p[r])) {
                buildings->p[r][0] = -1;
            } else if (IsOverlap(buildings->p[r],buildings->p[j])) {
                buildings->p[j][0] = -1;
            }
        }
    }
    return 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **getSkyline(int **buildings, int buildingsSize, int *buildingsColSize, int *returnSize, int **returnColumnSizes)
{
    int **ret;
    QUEUE *result;
    INT_ARRAY2 *buildingsArr;
    LIST *scan;
    // 因为不知道输出长度，结果存放到队列中去。
    result = Queue_Create(sizeof(LL), NULL);

    if (buildingsSize == 0) {
        LL res = {0, 0};
        Queue_Push(result, &res);
    } else {

        // 准备 一个list，以，扫面线坐标排序，依次存放各building的左右两边
        scan = List_Create(sizeof(LIST *), ScanBuildingsFree);
        buildingsArr = IntArray2_Attach(buildings, buildingsSize, *buildingsColSize);
        CleanOverlapBuildings(buildingsArr);
        // 计算结果的主体函数
        CalcSkyLine(buildingsArr, scan, result);
        // 销毁临时资源
        List_Destroy(scan);
        IntArray2_Detach(buildingsArr);
    }

    // 队列转 输出数组
    ret = ResultToArray(result, returnSize, returnColumnSizes);
    if (buildingsSize == 0) {
        *returnSize = 0;
    }
    Queue_Destroy(result);
    return ret;
}
```
