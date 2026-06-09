### 解题思路
1.思路比较简单：先对原始数据完成快排，然后从头开始找第3大的数。
2.corner condition：
（1）.数据不够三个；
（2）.没有第三大的数；
3.知识点总结：
通过这个题可以得到一个经验，快排的比较函数最好使用大于号或者小于号，如果是使用减号，本题中刚好有个用例，数据是-2147483648，刚好是int类型的左极值，如果这时候再减一，就会溢出。这个比较重要。
4.耗时：54mins，花的时间太长了，哎~~。主要耗时点：
（1）快排的cmpf函数溢出-----经验；
（2）取第三大的数，数中有可能有相同的数而出现反复重复解题------读题不准；
（3）有可能不够三个数------典型corner condition没有列全；
（4）for循环中逐项比较的起始条件设置逻辑考虑不清晰------对边界条件判断和使用的经验不足；
......


### 代码

```c
int cmpf(const void *a, const void *b) {
    return (*(int *)b) > (*(int *)a);
}

int thirdMax(int* nums, int numsSize){
    int i;
    int ii = 0;
    int count = 0;
    int temp;
    if (numsSize == 1) {
        return nums[0];
    }
    if (numsSize == 2) {
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }

    // printf("qsort before:\n");
    qsort(nums, numsSize, sizeof(int), cmpf);
    // printf("qsort after:\n");
    for (i = 1, temp = nums[0]; i < numsSize; i++) {
        if (temp > nums[i]) {
            count++;
            if (count == 2) {
                ii = i;
                // printf("ii = %d\n",ii);
                break;
            }
        }
        temp = nums[i];
    }

    if (count < 2) {
        ii = 0;
    }
    return nums[ii];
}
```