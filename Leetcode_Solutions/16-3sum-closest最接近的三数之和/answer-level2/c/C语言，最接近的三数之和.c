所有`N数之和`的问题，都应该想到`排序`+`双指针`。
当`N > 2`时，外层用循环嵌套处理。例如：`N = 3`则一层循环 + 双指针；`N = 4`则两层循环 + 双指针。

本题思路：
1. 先快速排序，再用双指针找三数之和
2. 用一个变量`gap`记录 `sum`和`target`的距离（即差的绝对值）, `ret`记录此时的返回值
3. 若有`sum = target`，直接返回`sum`。否则所有循环结束后返回`ret`

代码（4ms, 100%)：
```C
int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int threeSumClosest(int* nums, int numsSize, int target) {
    int ret, gap = 0x7fffffff;   // gap 记录距离并初始化为最大值，ret 记录此时返回值
    qsort(nums, numsSize, sizeof(int), comp);
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(sum - target) < gap) {    //如果距离更短，则更新 gap 和 ret
                gap = abs(sum - target);
                ret = sum;
            }
            if (sum > target) right--;        //移动左右指针
            else if (sum < target) left++;
            else return sum;
        }
    }
    return ret;
}
```
