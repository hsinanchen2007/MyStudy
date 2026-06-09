```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void exec(int* arr, int size, int* tmp1, int* tmp2)
{
    int i;
    int j = 0;
    int k = 0;

    // 如果数组长度小于等于2 则无需处理
    if (size <= 2) {
        return;
    }

    // 处理数组，把数字1 3 5 7 放在前面，把2 4 6 8...放在后面
    for (i = 0; i < size; i++) {
        if (i % 2 == 0) {
            tmp1[j++] = arr[i];
        } else {
            tmp2[k++] = arr[i];
        }
    }

    memcpy(arr, tmp1, j * sizeof(int));
    memcpy(arr + j, tmp2, k * sizeof(int));

    // 对前面的1 3 5 7...重复该处理过程
    exec(arr, j, tmp1, tmp2);

    // 对后面的2 4 6 8...重复该处理过程
    exec(arr + j, k, tmp1, tmp2);
}

int* beautifulArray(int N, int* returnSize){
    int* arr;
    int* tmp1;
    int* tmp2;
    int i;


    *returnSize = N;

    // 返回的数组
    arr = (int*)malloc(sizeof(int) * N);

    // 两个临时数组用于存放临时数据
    tmp1 = (int*)malloc(sizeof(int) * N);
    tmp2 = (int*)malloc(sizeof(int) * N);

    for (i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    exec(arr, N, tmp1, tmp2);

    free(tmp1);
    free(tmp2);

    return arr;
}
```
