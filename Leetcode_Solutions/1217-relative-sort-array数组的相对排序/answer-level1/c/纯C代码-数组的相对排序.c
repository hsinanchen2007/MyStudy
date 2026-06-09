### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int i, j, k;
    int data[arr1Size];
    bool flag[arr1Size];

    memset(flag, false, sizeof(bool) * arr1Size);

    //arr1排序后，存入data
    qsort(arr1, arr1Size, sizeof(int), cmp);
    memcpy(data, arr1, sizeof(int) * arr1Size);

    for (i = 0, k = 0; i < arr2Size; i++) {
        for (j = 0; j < arr1Size; j++) {
            if (data[j] < arr2[i]) {
                continue;
            }
            //按arr2的相对顺序，取出data里面的数字，存入arr1.
            while (data[j] == arr2[i]) {
                arr1[k++] = data[j];
                flag[j] = true;
                j++;
                if (j == arr1Size) {
                    break;
                }
            }
            break;
        }
    }
    //data里未被取出的数字，存入arr1.
    for (j = 0; j < arr1Size; j++) {
        if (flag[j] == false) {
            arr1[k++] = data[j];
        }
    }
    *returnSize = arr1Size;

    return arr1;
}
```