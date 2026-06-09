### 解题思路
将数组排序，这样可以最大化的求出 最后的最大值，找出 函数的规律，无论数组中元素的个数有多少，最后都会被分成numsSize的一半，这样排完序的数组，数组中每子组的第一项为最小值，加在一起即可

### 代码

```c
int cmp(int *a, int *b) {
    return *(int *)a > *(int *)b;
}
int arrayPairSum(int* nums, int numsSize){
    int i, j;
    int sum = 0;
    if (numsSize < 2) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(int), cmp);  //stdlib.h库中 快排函数
    for (sum = nums[0], i = 2; i < numsSize; i += 2) 
    {
        sum += nums[i];
    }
    return sum;
}

```