### 解题思路
1、带入一堆参数
2、DFS进入和退出后的对应状态变量要维护好

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void DFS(int** edges, int edgesSize, int k, int p, bool* Map, int* MaxIndex, int* index, bool* isfound, int* res)
{
    int tmp = *MaxIndex;
    
    if (index[k] < 2) {
        return ;
    }

    if (k == p && *MaxIndex != -1) {
        *res = *MaxIndex;
        *isfound = true;
        return ;
    }

    for (int n = 0; n < edgesSize; n++) {
        if (*isfound) {
            return;
        }

        if (edges[n][0] == k && Map[n] == false) {
            Map[n] = true;
            *MaxIndex = (*MaxIndex > n) ? *MaxIndex : n;
            DFS(edges, edgesSize, edges[n][1], p, Map, MaxIndex, index, isfound, res);
            *MaxIndex = tmp;
            Map[n] = false;

        }

        if (edges[n][1] == k && Map[n] == false) {
            Map[n] = true;
            *MaxIndex = (*MaxIndex > n) ? *MaxIndex : n;
            DFS(edges, edgesSize, edges[n][0], p, Map, MaxIndex, index, isfound, res);
            *MaxIndex = tmp;
            Map[n] = false;
        }
    } 

    return ;   
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int index[edgesSize + 1];
    for (int i = 0; i <= edgesSize; i++) {
        index[i] = 0;
    }

    for (int j = 0; j < edgesSize; j++) {
        index[edges[j][0]]++;
        index[edges[j][1]]++;
    }
    
    int MaxIndex = -1;
    int res = -1;
    bool Map[1000] = {false};
    bool isfound = false;

    for (int k = 0; k <= edgesSize; k++) {
        if (index[k] > 1) {
            DFS(edges, edgesSize, k, k, Map, &MaxIndex, index, &isfound, &res);        
            if (isfound)
                break;
            
        }
    }
    
    int *ret = (int *)malloc(sizeof(int) * edgesColSize[0]);
    ret[0] = edges[res][0];
    ret[1] = edges[res][1];

    *returnSize = 2;
    return ret;
}
```