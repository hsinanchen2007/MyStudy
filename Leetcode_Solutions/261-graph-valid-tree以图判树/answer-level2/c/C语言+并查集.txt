### 解题思路
典型的并查集题目

### 代码

```c
static int* S;

int find(int x)
{
    if (S[x] == x) {
        return x;
    }
    else {
        return find(S[x]);
    }
}

void union_xy(int x, int y)
{
    int a = find(x);
    int b = find(y);
    if (a == b) {
        return ;
    }
    else {
        if (b == y) {
            S[y] = a;
        }
        else {
            S[x] = b;
        }
    }
    return ;
}

bool validTree(int n, int** edges, int edgesSize, int* edgesColSize){
    S = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        S[i] = i;
    }

    for (int i = 0; i < edgesSize; i++) {
        int a = find(edges[i][0]);
        int b = find(edges[i][1]);
        if (a == b) {
            //判断是否有环
            return false;
        }
        union_xy(edges[i][0], edges[i][1]);
    }
    //判断是否为一棵树还是多棵
    for (int i = 1; i < n; i++) {
        if (find(i) != find(0)) {
            return false;
        }
    }
    return true;
}
```