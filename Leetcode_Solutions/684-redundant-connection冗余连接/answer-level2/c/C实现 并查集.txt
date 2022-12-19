![image.png](https://pic.leetcode-cn.com/fef046d94622803a0003cc3f58aa6f33311bfb35af194ce3f0675686e86f4943-image.png)

### 解题思路
并查集

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX 2000

int g_preNode[MAX];

int FindRoot(int node)
{
    int son = node;
    int temp;

    if (g_preNode[node] == -1) {
        return node;
    }

    while (g_preNode[node] != -1) {
        node = g_preNode[node];
    }

    while (son != node) {
        temp = g_preNode[son];
        g_preNode[son] = node;
        son = temp;
    }

    return node;
}

void UnionRoot(int node1, int node2)
{
    int a = FindRoot(node1);
    int b = FindRoot(node2);

    if (a != b) {
        g_preNode[b] = a;
    }
    
    return;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int *result = NULL;
    int temp = edgesSize - 1;
    int i;

    *returnSize = 0;
    if (edgesSize < 3 || edgesColSize[0] < 2) {
        return result;
    }

    result = (int *)malloc(edgesColSize[0] * sizeof(int));

    while (temp) {
        memset(g_preNode, -1, MAX * sizeof(int));        
        for (i = 0; i  < edgesSize; i++) {
            if (i != temp) {
                UnionRoot(edges[i][0], edges[i][1]);
            }
        }
        if (FindRoot(edges[temp][0]) == FindRoot(edges[temp][1])) { /*这里不能统计preNode为-1的次数来看，需要从冗余边的角度来考虑*/
            result[0] = edges[temp][0];
            result[1] = edges[temp][1];
            *returnSize = 2;
            return result;
        }
        temp--;      
    }

    return result;
}
```