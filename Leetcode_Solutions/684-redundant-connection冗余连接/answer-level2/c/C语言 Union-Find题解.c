```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 /* union_find alg */
#define MAXNUM 10001
int UF[MAXNUM];
int UFSize[MAXNUM];

void initialUF(int *UF, int num) 
{
    int i = 0;
    for (i = 0; i < MAXNUM; i++) {
        UF[i] = i;
        UFSize[i] = 1;
    }
}

int root(int num) {
    while(UF[num] != num) {
        num = UF[num];
    }
    return num;
}

int Find(int a, int b) {
    return root(a) == root (b);
}

void Union(int a, int b) {
    a = root(a);
    b = root(b);
    if (UFSize[a] < UFSize[b]) {
        UF[a] = b;
        UFSize[b] += UFSize[a];
    } else {
        UF[b] = a;
        UFSize[a] += UFSize[b];
    }
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int i = 0;
    * returnSize = 2;
    int *ret = malloc(sizeof(int) * 2);
    initialUF(UF, MAXNUM);
    int a = 0;
    int b = 0;

    for (i = 0; i < edgesSize; i++) {
        a = edges[i][0];
        b = edges[i][1];
        if (!Find(a, b)) {
            Union(a, b);
        } else {
            ret[0] = a;
            ret[1] = b;
            return ret;
        }
    }
    return ret;
}
```
