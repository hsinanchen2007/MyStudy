### 解题思路
关键算法
    for (int j = 3; j <= n; j++) {  
        for (m = 0; m < (j + 1) / 2; m++) {
            arr[j][m] = arr[(j + 1) / 2][m] * 2 - 1;
        }
        
        for (int n = 0; n < j / 2; n++) {
            arr[j][m + n] = arr[j / 2][n] * 2;
        }
    }
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* calArr(int n) {
    if (n <= 0) {
        return NULL;
    }
    
    int *res = (int *)malloc(n * sizeof(int));
    int arr[n + 1][n];
    arr[1][0] = 1;

    if (n == 1) {
        memcpy(res, arr[n], n * sizeof(int));
        return res;    
    } else {
        arr[2][0] = 1;
        arr[2][1] = 2;
    }

    int m;
    for (int j = 3; j <= n; j++) {  
        for (m = 0; m < (j + 1) / 2; m++) {
            arr[j][m] = arr[(j + 1) / 2][m] * 2 - 1;
        }
        
        for (int n = 0; n < j / 2; n++) {
            arr[j][m + n] = arr[j / 2][n] * 2;
        }
    }
    
    memcpy(res, arr[n], n * sizeof(int));
    return res;
}

int* beautifulArray(int N, int* returnSize){
    *returnSize = N;
    return calArr(N);
}
```