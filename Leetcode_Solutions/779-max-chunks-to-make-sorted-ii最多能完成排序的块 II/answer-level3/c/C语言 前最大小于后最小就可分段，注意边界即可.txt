```
#define MAX_SIZE 2000
#define MAX_VALUE 100000001
int maxChunksToSorted(int* arr, int arrSize){
    int count = 0;
    int bk[MAX_SIZE] = {0};
    bk[arrSize - 1] = MAX_VALUE;
    for (int i = arrSize - 2; i >= 0; i--) {
        bk[i] = fmin(arr[i + 1], bk[i + 1]);
    }
    int max = 0;
    for (int i = 0; i < arrSize; i++) {
        max = fmax(max, arr[i]);
        if (max <= bk[i]) {
            count++;
        }
    }
    return count;
}
```
