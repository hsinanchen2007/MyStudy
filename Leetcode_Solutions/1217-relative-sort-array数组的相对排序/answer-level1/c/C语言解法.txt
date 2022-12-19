思路很比较简单，由于题目给的数据量不大，可以采用空间换时间的思路。
其实不用关心排序过程，统计数组1中所有数字出现的次数，最终的结果就是数组2中出现的数字按序*数组1中统计的个数，
最后在没有在数组2中出现的数字按照计数数组输出即可。
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int i, j;
    int idx = 0;
    int array1_cnt[1001] = {0}; /* 最大数字1001 */
    int *result = (int*)malloc(sizeof(int) * arr1Size);
    *returnSize = arr1Size;
    /* 1. 统计arr1出个数字的次数 */
    for(i = 0; i < arr1Size; i++) {
        array1_cnt[arr1[i]]++;
    }

    /* 2. arr2必然出现的数字按照arr1统计出来的个数按序按数存放 */
    for(i = 0; i < arr2Size; i++) {
        for(int j = 0; j < array1_cnt[arr2[i]]; j++) {
            result[idx] = arr2[i];
            idx++;
        }
        array1_cnt[arr2[i]] = 0; /* 抹去已经存放的 */
    }

    /* 3.未出现在arra1中数字按数字打印 */
    for(i = 0; i < arr1Size; i++) {
        for(j = 0; j < array1_cnt[arr1[i]]; j++) {
            result[idx] = arr1[i];
            idx++;
        }
    }

    return result;
}
