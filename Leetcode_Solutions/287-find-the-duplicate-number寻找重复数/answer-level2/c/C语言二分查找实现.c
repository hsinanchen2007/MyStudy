解题思路：应用二分查找的关键是如何判断下一步查找是左半部分还是右半部分。
1、先对数据进行排序：这是二分查找应用的前提。由于本题不能修改nums数组，所以要新建一个数组。
2、排序后的数组在重复数出现之前存在特征：arry[i] == i + 1, 出现重复数之后：arry[i] == i 。以这个条件来判断重复数出现在mid左侧还是右侧。
void SortArry(int *arry, int size)
{
    int tmp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arry[j] > arry[j + 1]) {
                tmp = arry[j];
                arry[j] = arry[j + 1];
                arry[j + 1] = tmp;
            }
        }
    }
}
int findDuplicate(int* nums, int numsSize){
    if (nums == NULL) {
        return 0;
    }
    if (numsSize < 3) {
        return nums[0];
    }
    // 先对数据进行排序：这是二分查找应用的前提。由于本题不能修改nums数组，所以要新建一个数组。
    int *a = (int *)malloc(numsSize * sizeof(int));
    memcpy(a, nums, numsSize * sizeof(int));
    SortArry(a, numsSize);
    /**
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    */
    int left = 0;
    int right = numsSize - 1;
    int mid;
    while (left < right) {
        mid = left + (right - left)/2;
        if (a[mid] < mid + 1) {  // 不满足特征：arry[i] == i + 1，说明已出现重复数
            right = mid;
        } else {
            left = mid + 1;
        }
        printf("mid %d left %d right %d \n", mid, left, right);
    }
    int ret = a[left];
    free(a);    
    return ret;
}
