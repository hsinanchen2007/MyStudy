### 解题思路
此处撰写解题思路

### 代码

```c
void dfs(int** flights, int flightsSize,int src, int dst, int K, int *max, int depth, int curvalue, int** info, int *count)
{
    if (depth > K){
        return;
    }
    if (curvalue > *max) {
        return;
    }
    for (int i = 0; i < count[src]; i++) {
        int index = info[src][i];
        if (flights[index][0] == src) {
            if (flights[index][1] == dst) {
                (*max) = (*max) > (curvalue + flights[index][2]) ? (curvalue + flights[index][2]) : (*max);
                continue;
            }
            dfs(flights, flightsSize, flights[index][1], dst,K, max, depth + 1, curvalue + flights[index][2], info,count);
        }
    }
}

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int K){
    int max = 100000000;
    int depth = 0;
    int **info;
    info = (int**)malloc(sizeof(int*) * 100);
    for (int i = 0; i < 100; i++) {
        info[i] = (int*)malloc(sizeof(int) * 100);
    }
    int count[100] = { 0 };
    for (int i = 0; i < flightsSize; i++) {
        info[flights[i][0]][count[flights[i][0]]++] = i;
    }
    dfs(flights, flightsSize, src,dst, K, &max, depth, 0, info, count);
    if (max == 100000000) {
        return -1;
    }
    else
    {
        return max;
    }
}
```