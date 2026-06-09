### 解题思路
用时击败90.24%，内存击败100%（这个内存比较诧异，因为这个方法有空间换时间的做法）

1、开辟一个数组arrAngle，标识下arr2中有哪些元素。遍历arr2,元素值作为arrAngle数组脚标。
2、遍历arr1，元素的值作为脚标在arrAngle中寻找，如果arr2中有就++，否则先存起来，以后排序备用。
3、遍历arr2,不难看出，此时arrAngle此时保存了arr1中元素出现的次数。
4、arr3保存了arr1中出现，但是arr2没有的数字。
5、拼接起来。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXLENGTH 1001

int cmp(const void* a, const void* b)
{
    return (*((int *)a) - *((int *)b));
}

 //题目要求arr1的元素的相对顺序和arr2中相对顺序相同，也就是需要自己按照新的规则实现排序。
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    //申请一个数组的空间，数组角标表征arr2的元素的数值，对应数组元素的大小，是arr1中的元素等于对应角标数值的个数
    int arrAngle[MAXLENGTH] = {0};
    for(int i = 0; i < MAXLENGTH; i++) {
        arrAngle[i] = -1;
    }

    int* arrReturn = (int *)malloc(sizeof(int) * arr1Size);
    memset(arrReturn, 0, sizeof(int) * arr1Size);

    for (int i = 0; i < arr2Size; i++) {
        arrAngle[*(arr2 + i)] = 0;
    }

    //申请一个数组保存arr1中不在arr2中的元素。
    int* arr3 = (int *)malloc(sizeof(int) * MAXLENGTH);
    memset(arr3, 0, sizeof(int) * MAXLENGTH);

    int otherNum = 0;
    int* arr3Tmp = arr3;
    for (int i = 0; i < arr1Size; i++) {
        if (arrAngle[*(arr1 + i)] != -1) {
            arrAngle[*(arr1 + i)]++;
        } else {
            *(arr3Tmp + otherNum) = *(arr1 + i);
            otherNum++;
        }
    }

    qsort(arr3, otherNum, sizeof(int), cmp);

    int* arrReturnTmp = arrReturn;
    for (int i = 0; i < arr2Size; i++) {
        for (int j = 0; j < arrAngle[*(arr2 + i)]; j++) {
            *arrReturnTmp = *(arr2 + i);
            arrReturnTmp++;
        }
    }

    *returnSize = arr1Size;
    memmove(arrReturnTmp, arr3, otherNum * sizeof(int));
    free(arr3);
    return arrReturn;
    
}
```