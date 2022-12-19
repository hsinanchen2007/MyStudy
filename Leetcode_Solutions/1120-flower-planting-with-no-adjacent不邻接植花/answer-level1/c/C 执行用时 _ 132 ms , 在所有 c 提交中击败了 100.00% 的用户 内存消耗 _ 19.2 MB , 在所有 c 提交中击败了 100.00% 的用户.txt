```
struct Node {
    int num;
    int index[3];
    int color;
};
int* gardenNoAdj(int N, int** paths, int pathsSize, int* pathsColSize, int* returnSize){
    struct Node* arr = malloc(sizeof(struct Node) * (N + 1));
    memset(arr, 0, sizeof(struct Node) * (N + 1));
    for (int i = 0; i < pathsSize; i++) {
        arr[paths[i][0]].index[arr[paths[i][0]].num] = paths[i][1];
        (arr[paths[i][0]].num)++;
        arr[paths[i][1]].index[arr[paths[i][1]].num] = paths[i][0];
        (arr[paths[i][1]].num)++;
    }
    int* flag = malloc(sizeof(int) * 5);
    for (int i = 1; i <= N; i++) {
        memset(flag, 0, sizeof(int) * 5);
        for (int j = 0; j < arr[i].num; j++) {
            flag[arr[arr[i].index[j]].color]++;
        }
        for (int j = 1; j <= 4; j++) {
            if (flag[j] == 0) {
                arr[i].color = j;
                break;
            }
        }
    }
    int* res = malloc(sizeof(int) * N);
    *returnSize = N;
    for (int i = 1; i <= N; i++) {
        res[i - 1] = arr[i].color;
    }
    return res;
}
```
