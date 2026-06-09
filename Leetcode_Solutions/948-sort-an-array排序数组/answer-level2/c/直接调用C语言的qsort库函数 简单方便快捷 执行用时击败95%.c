### 解题思路
调用C语言的库函数解题

### 代码

```c
int compare(int *a,int *b) {
    return *a-*b;
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    qsort(nums, numsSize, sizeof(nums[0]), compare);//qsort库函数（不会的可以上网查，本处不做赘述）
    *returnSize = numsSize;//让返回的数组大小等于nums数组的大小，否则会报内存溢出的错误
    return nums;
}

```