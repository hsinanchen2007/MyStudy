### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NUM 1001

int g_arr[MAX_NUM] = {0};
int g_size = 0;

int MyCompare(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    if (x == y) {
        return 0;
    }
    int posX = -1;
    int posY = -1;
    for (int i = 0; i < g_size; i++) {
        if (g_arr[i] == x) {
            posX = i;
        }
        if (g_arr[i] == y) {
            posY = i;
        }
    }

    if (posX >= 0 && posY >= 0) {
        return posX - posY;
    } else if (posX >= 0 && posY == -1) {
        return -1;
    } else if (posX == -1 && posY >= 0) {
        return 1;
    }

    return x - y;
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    if (!arr1 || arr1Size < 1 || arr2Size < 1) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < MAX_NUM; i++) {
        g_arr[i] = 0;
    }
    g_size = arr2Size;
    for (int i = 0; i < arr2Size; i++) {
        g_arr[i] = arr2[i];
    }

    qsort(arr1, arr1Size, sizeof(int), MyCompare);

    *returnSize = arr1Size;
    return arr1;
}
```