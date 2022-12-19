
如果这个边的两个顶点属于同一集合，则认为这个边最后导致了环，取最后一个造成环的边即可

方法1： 使用rank
```
#define MAX_POINTNUM  1000


int findRoot(int point, int *pParent) 
{
    int pt = point;
    while (pt != pParent[pt]) {
        pt = pParent[pt];
    }

    return pt;
}

bool unionPoint(int point1, int point2, int *pParent, int *pRank) 
{
    int root1 = findRoot(point1, pParent);
    int root2 = findRoot(point2, pParent);

    if (root1 == root2) {
        return true;
    } 

    if (pRank[root1] > pRank[root2]) {
        pParent[root2] = root1;
    } else if (pRank[root1] < pRank[root2]) {
        pParent[root1] = root2;
    } else {
        pParent[root1] = root2;
        pRank[root2] += 1;
    }

    return false;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int parent[MAX_POINTNUM + 1];
    int rank[MAX_POINTNUM +1] = { 0 };
    int i, j;
    int point1 = 0, point2 = 0;
    int *rslt = NULL;

    *returnSize = 0;
    if (edges == NULL || edgesSize == 0) {
        return NULL;
    }

    for (i = 1; i <= MAX_POINTNUM; i++) {
        parent[i] = i;
    }

    for (i = 0; i < edgesSize; i++) {
            if (unionPoint(edges[i][0], edges[i][1], parent, rank) ) {
                point1 = edges[i][0];
                point2 = edges[i][1];
            }
    }

    if (point2 != 0) {
        rslt = (int *)malloc(2 * sizeof(int));
        rslt[0] = point1;
        rslt[1] = point2;
        *returnSize = 2;
    }

    return rslt;
}
```
方法2：不使用rank ，查询时候压缩路径
```

#define MAX_POINTNUM  1000


int findRoot(int point, int *pParent) 
{
    int pt = point;
    while (pt != pParent[pt]) {
        pParent[pt] = pParent[pParent[pt]];
        pt = pParent[pt];
    }

    return pt;
}

bool unionPoint(int point1, int point2, int *pParent) 
{
    int root1 = findRoot(point1, pParent);
    int root2 = findRoot(point2, pParent);

    if (root1 == root2) {
        return true;
    } 

    pParent[root1] = root2;
    return false;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int parent[MAX_POINTNUM + 1];
    int i, j;
    int point1 = 0, point2 = 0;
    int *rslt = NULL;

    *returnSize = 0;
    if (edges == NULL || edgesSize == 0) {
        return NULL;
    }

    for (i = 1; i <= MAX_POINTNUM; i++) {
        parent[i] = i;
    }

    for (i = 0; i < edgesSize; i++) {
            if (unionPoint(edges[i][0], edges[i][1], parent) ) {
                point1 = edges[i][0];
                point2 = edges[i][1];
            }
    }

    if (point2 != 0) {
        rslt = (int *)malloc(2 * sizeof(int));
        rslt[0] = point1;
        rslt[1] = point2;
        *returnSize = 2;
    }

    return rslt;
}
```

