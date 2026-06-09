解题思路：
1.对数组进行升序排序。
2.对数组下标{0、1、2、3、4、5、6......2n-1,2n}为0,2....2n的数组值进行求和。

    int cmp(int *a, int *b) {
        return *(int *)a > *(int *)b;
    }
    int arrayPairSum(int* nums, int numsSize){
        int i, j;
        int sum = 0;
        if (numsSize < 2) {
            return 0;
        }
        qsort(nums, numsSize, sizeof(int), cmp);
        for (sum = nums[0], i = 2; i < numsSize; i = i + 2) {
            sum += nums[i];
        }
        return sum;
    }