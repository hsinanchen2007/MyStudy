### 解题思路
此处撰写解题思路
1.找到最大值的位置K。
2.翻转最大值在内的前K个数字，此时最大值已经处于第一个位置。
3.翻转整个数组。此时最大值处于最后一个位置。
4.以此次类推，计算第二大数字的位置，进行操作。
5.注意：1）已经排好序的，直接返回。2）记录翻转的位置不是数组的下标
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdbool.h>

int max_value_postion(int *arr, int num) {
    int max_flag = 0;
    int i;
    for (i = 1; i < num; i++) {
        if (arr[i] > arr[max_flag]) {
            max_flag = i;
        }
    }

    return max_flag + 1;
}
void return_over_arr(int *arr, int num) {
    int i, j;
    int tmp;

    for (i = 0; i < num / 2; i++) {
         tmp = arr[i];
         arr[i] = arr[num - 1 - i];
         arr[num - 1 - i] = tmp;
    }

    return ;
}

bool isAscendSort(int *arr, int arrLenth) {
    int temp = 0;
    for (int i = 0; i < arrLenth; i++) {
        temp = arr[i];
        if (i < arrLenth - 1) {//防止数组下标越界
            if (temp > arr[i+1]) {//后一个元素比前一个大，非升序
                return false;
            }
        }
    }
    return true;
}
int* pancakeSort(int* A, int ASize, int* returnSize) {
    int i, k, j;
    int *returnarray;
    int index;

    if (ASize <= 1) {
        *returnSize = 0;
        return NULL;
    }

    bool flag = false;
    flag = isAscendSort(A, ASize);

    if (true == flag) {
        *returnSize = 0;
        return NULL;
    }

    returnarray = (int *)malloc(sizeof(int) * ASize * 10);

    for (i = 0, k = 0; i < ASize - 1; i++) {
        index = max_value_postion(A, ASize - i);
        return_over_arr(A, index);
        returnarray[k++] = index;
        return_over_arr(A, ASize - i);
        returnarray[k++] = ASize - i;
    }

    * returnSize = k;

    if (k > (ASize * 10)) {
        * returnSize = 0;
        return NULL;
    } else {
        return returnarray;
    }
}
```