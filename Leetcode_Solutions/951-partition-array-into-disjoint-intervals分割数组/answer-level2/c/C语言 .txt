左边最大值小于右边最小值时，就找到了分割点
```
int partitionDisjoint(int* A, int ASize){
    int *left = (int*)malloc(ASize * sizeof(int));
    if (left == NULL) {
        return 0;
    }
    left[0] = A[0];
    for (int i = 1; i < ASize; i++) {
        left[i] = fmax(left[i - 1], A[i]);
    }
    int *right = (int*)malloc(ASize * sizeof(int));
    if (right == NULL) {
        return 0;
    }
    right[ASize - 1] = A[ASize - 1];
    for (int i = ASize - 2; i >= 0; i--) {
        right[i] = fmin(right[i + 1], A[i]);
    }
    for (int i = 0; i < ASize - 1; i++) {
        if (left[i] <= right[i + 1]) {
            return i + 1;
        }
    }
    return 0;
}
```
