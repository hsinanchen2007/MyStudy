C语言双100%
思路：
1、利用map1[1001]的下标记录arr1中各值出现的频数；
2、遍历arr2，根据map1[arr2[i]]记录的频数输出对应数量的arr2[i]，没输出一次频数减1；
3、遍历map1[1001]，把剩下有频数的i按指定数量输出。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_SIZE 1001

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
    int map1[MAX_SIZE] = {0};

    int i;
    for (i = 0; i < arr1Size; i++) {
        map1[arr1[i]]++;
    }

    int* result = (int*)malloc(sizeof(int) * arr1Size);
    memset(result, 0, sizeof(int) * arr1Size);
    int cnt = 0;
    for (i = 0; i < arr2Size; i++) {
        while (map1[arr2[i]] > 0) {
            map1[arr2[i]]--;
            result[cnt++] = arr2[i];
        }
    }

    for (i = 0; i < MAX_SIZE; i++) {
        if (map1[i] <= 0) {
            continue;
        }
        while (map1[i] > 0) {
            map1[i]--;
            result[cnt++] = i;
        }
    }

    *returnSize = cnt;
    return result;
}