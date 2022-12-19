### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//计数排序思想
#define LEN 1001
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int count[LEN] = {0};
    for (int i = 0; i < arr1Size; i++) {
        count[arr1[i]]++;
    }

    int index = 0;
    for (int i = 0; i < arr2Size; i++) {
        while (count[arr2[i]] > 0) {
            arr1[index++] = arr2[i];
            count[arr2[i]]--;
        }
    }
    for (int i = 0; i < LEN; i++) {
        while (count[i] > 0) {
            arr1[index++] = i;
            count[i]--;
        }
    }

    *returnSize = arr1Size;
    return arr1;
}
```