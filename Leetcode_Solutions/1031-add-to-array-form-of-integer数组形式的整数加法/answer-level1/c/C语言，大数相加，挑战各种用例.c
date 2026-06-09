C语言
大数相加
小人不才，最笨方法解决
```
#define MAX(a, b)   a > b ? a : b
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
    int i = 0;
    int tmpK = K;
    while (tmpK / 10) {
        tmpK /= 10;
        i++;
    }
    int lengthK = i + 1;
    int arrayK[lengthK];
    memset(arrayK, 0, lengthK * sizeof(int));
    i = 0;
    tmpK = K;
    while (tmpK / 10) {
        arrayK[i] = tmpK % 10;
        tmpK /= 10;
        i++;
    }
    arrayK[i] = tmpK  % 10;
    for (i = 0; i < ASize / 2; i++) {
        int tmp = A[i];
        A[i] = A[ASize - 1 - i];
        A[ASize - 1 - i] = tmp;
    }
    int size = ((MAX(lengthK, ASize)) + 1) * sizeof(int);
    int *ret = (int *)malloc(size);
    memset(ret, 0, size);
    if (ASize >= lengthK) {
        for (i = 0; i < lengthK; i++) {
            if (arrayK[i] + A[i] + ret[i] < 10) {
                ret[i] = arrayK[i] + A[i] + ret[i];
            } else {
                ret[i] = arrayK[i] + A[i] + ret[i] - 10;
                ret[i + 1]++;
            }
        }
        for (;i < ASize; i++) {
            if (ret[i] + A[i] < 10){
                ret[i] += A[i];
            } else {
                ret[i] = A[i] + ret[i] - 10;
                ret[i + 1]++;
            }
        }
        if (ret[ASize] == 0) {
            (*returnSize) = ASize;
        } else {
            (*returnSize) = ASize + 1;
        }
        for (i = 0; i < (*returnSize) / 2; i++) {
            int tmp = ret[i];
            ret[i] = ret[(*returnSize) - 1 - i];
            ret[(*returnSize) - 1 - i] = tmp;
        }
        return ret;
    } else if ( ASize < lengthK) {
        for (i = 0; i < ASize; i++) {
            if (arrayK[i] + A[i] + ret[i] < 10) {
                ret[i] = arrayK[i] + A[i] + ret[i];
            } else {
                ret[i] = arrayK[i] + A[i] + ret[i] - 10;
                ret[i + 1]++;
            }
        }
        for (;i < lengthK; i++) {
            if (ret[i] + arrayK[i] < 10){
                ret[i] += arrayK[i];
            } else {
                ret[i] = arrayK[i] + ret[i] - 10;
                ret[i + 1]++;
            }
        }
        if (ret[lengthK] == 0) {
            (*returnSize) = lengthK;
        } else {
            (*returnSize) = lengthK + 1;
        }
        for (i = 0; i < (*returnSize) / 2; i++) {
            int tmp = ret[i];
            ret[i] = ret[(*returnSize) - 1 - i];
            ret[(*returnSize) - 1 - i] = tmp;
        }
        return ret;
    } else {
        return NULL;
    }
}
```
