一、深度优先搜索，普通回溯算法
```
#define MAX_ALPHA 26
int max = 0;
int DFS(char** arr, int size, int len, int index, int* bk) {
    max = fmax(max, len);
    for (int i = index; i < size; i++) {
        int tmp[MAX_ALPHA] = {0};
        int len1 = strlen(arr[i]);
        if (bk != NULL) {
            memcpy(tmp, bk, MAX_ALPHA * sizeof(int));
        }
        int j;
        for (j = 0; j < len1; j++) {
            if (tmp[arr[i][j] - 'a'] > 0) {
                break;
            }
            tmp[arr[i][j] - 'a']++;
        }
        if (j != len1) {
            continue;
        }
        max = fmax(max, DFS(arr, size, len + strlen(arr[i]), i + 1, tmp));
    }
    return max;
}
int maxLength(char ** arr, int arrSize){
    max = 0;
    return DFS(arr, arrSize, 0, 0, NULL);
}
```
二、字符串数组不长，可以用位运算穷举，不过效率貌似不高
```
#define MAX_SIZE 1 << 16
int GetBit(char *a) {
    int ret = 0;
    for (int i = 0; i < strlen(a); i++) {
        if (ret & (1 << (a[i] - 'a'))) {
            return 0;
        }
        ret += 1 << (a[i] - 'a');
    }
    return ret;
}
int maxLength(char ** arr, int arrSize){
    int max = 0;
    int *bitArr = (int*)malloc(arrSize * sizeof(int));
    memset(bitArr, 0, arrSize * sizeof(int));
    int lenArr[MAX_SIZE] = {0};
    for (int i = 0; i < arrSize; i++) {
        bitArr[i] = GetBit(arr[i]);
        lenArr[i] = strlen(arr[i]);
    }
    for (int i = 1; i < (1 << arrSize); i++) {
        int num = 0;
        int len = 0;
        for (int j = 0; j < arrSize; j++) {
            if (i & (1 << j)) {
                if (num & bitArr[j] || bitArr[j] == 0) {
                    break;
                }
                num |= bitArr[j];
                len += lenArr[j];
            }
        }
        max = fmax(max, len);
    }
    return max;
```


