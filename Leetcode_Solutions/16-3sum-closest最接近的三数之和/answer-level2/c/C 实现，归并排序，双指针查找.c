![2019-09-30_18-55.png](https://pic.leetcode-cn.com/ec3185e4b90580e83ebdc862abe960e8f274f7a273b8438398cd4718f2e96ac7-2019-09-30_18-55.png)

```c
// 归并
void merge(int * nums, int * tmp, int leftStart, int rightStart, int rightEnd) {
    int cur = leftStart;
    int leftEnd = rightStart - 1;
    int numsSize = rightEnd - leftStart + 1;
    while (leftStart <= leftEnd && rightStart <= rightEnd) {
        if (nums[leftStart] < nums[rightStart])
            tmp[cur++] = nums[leftStart++];
        else
            tmp[cur++] = nums[rightStart++];
    }
    while (leftStart <= leftEnd)
        tmp[cur++] = nums[leftStart++];
    while (rightStart <= rightEnd)
        tmp[cur++] = nums[rightStart++];
    for (int i = 0; i < numsSize; i++, rightEnd--) {
        nums[rightEnd] = tmp[rightEnd];
    }
}

// 归并排序
void mergeSort(int * nums, int * tmp, int left, int right) {
    if (left < right) {
        int mid = (left + right) >> 1;
        mergeSort(nums, tmp, left, mid);
        mergeSort(nums, tmp, mid + 1, right);
        merge(nums, tmp, left, mid + 1, right);
    }
}

int threeSumClosest(int* nums, int numsSize, int target) {
    // 先对 nums 进行排序
    int * tmp = (int *) malloc(sizeof(int) * numsSize);
    mergeSort(nums, tmp, 0, numsSize - 1);
    free(tmp);

    // 声明并初始化变量
    int sum = nums[0] + nums[1] + nums[2]; // 三数之和
    int ret = sum;                         // 三数之和返回值
    int diff = sum - target;               // 和与目标的差值
    int min = diff > 0? diff: -diff;       // 差值绝对值的最小值
    int L, R;                              // 左右指针
    for (int i = 0; i < numsSize - 2; i++) {
        // 当前值与前一个值相等时，跳过本次循环
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        // 初始化左右指针
        L = i + 1;
        R = numsSize - 1;
        while (L < R) {
            sum = nums[i] + nums[L] + nums[R];
            diff = sum - target;
            // 差值为 0 时直接返回
            if (diff == 0) {
                return sum;
            }
            // 差值小于 0
            else if (diff < 0) {
                // 差值绝对值比记录值小时，更新记录值和返回值
                if (-diff < (min > 0? min: -min)) {
                    min = -diff;
                    ret = sum;
                }
                // 利移动左指针使 sum 增大
                L++;
                // 跳过重复值
                while (L < R && nums[L] == nums[L - 1]) L++;
            }
            else if (diff > 0) {
                if (diff < (min > 0? min: -min)) {
                    min = diff;
                    ret = sum;
                } R--;
                while (L < R && nums[R] == nums[R + 1]) R--;
            }
        }
    }

    return ret;
}
```
