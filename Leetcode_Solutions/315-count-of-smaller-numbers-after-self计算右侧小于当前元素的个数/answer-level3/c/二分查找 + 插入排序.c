### 解题思路
二分查找 + 插入排序
1. 二分查找找到第一个小于val值的元素，对应的index就是前面有多少个数比它小；
2. 类似插入排序的方式确保每次进来元素有序。

代码中在二分查找时就存入了index,后面不用再翻转了。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* 插入 + 二分查找 */
int binarysearch(int nums[], int start, int end, int val)
{
    int l = start;
    int r = end - 1;
    int mid ;
    /* 返回小于该数的位置 */
    while (l <= r) {
        mid = (l + r) / 2;
        if (nums[mid] < val) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

void insert(int *nums, int start, int end, int index, int val) {
    int i = end;
    for (; i >= start; i--) {
        //printf("%d->", i);
        if (i == index) {
            nums[i] = val;
            break;
        } else if(i != 0){
            nums[i] = nums[i - 1];
        }
    }
}

int* countSmaller(int* nums, int numsSize, int* returnSize){
    int *ReturnNums = malloc(sizeof(int) * (numsSize));
    int *Count = malloc(sizeof(int) * numsSize);
    memset(Count, 0, sizeof(int) * numsSize);
    memset(ReturnNums, 0, sizeof(int) *(numsSize));
    for (int i = 0; i < numsSize; i++) {
        ReturnNums[i] = INT_MIN;
    }
    int end = numsSize - 1;
    int num = 0;
    for (; end >=0 ; end--) {
        int sindex = binarysearch(ReturnNums, 0, num, nums[end]);
        Count[end] = sindex;
        insert(ReturnNums, 0, num, sindex, nums[end]);
        num++;
    }
    *returnSize = numsSize;
    free(ReturnNums);
    return Count;
}
```