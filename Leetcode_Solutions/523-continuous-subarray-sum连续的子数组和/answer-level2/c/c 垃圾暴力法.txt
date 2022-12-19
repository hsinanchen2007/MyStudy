### 解题思路
此处撰写解题思路
垃圾暴力法，先用的二维数组sum来保存中间结果，时间不超，但是内存超了，后来改一维数组，速度慢，占内存多。不过好歹ac了。
中间有无数坑，k为负数啦，k为0啦这些都没考虑到，提交一次改一次。
### 代码

```c
bool checkSubarraySum(int* nums, int numsSize, int k){
    if (nums == NULL || numsSize == 0 || numsSize == 1) {
        return false;
    }
    // k=0特殊处理,看数组元素里面有没有连续的0
    int flag = 0;
    if (k == 0) {
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] == 0) {
                if (flag == 1) {
                    return true;
                } else {
                    flag = 1;
                }
            } else {
                flag = 0;
            }
        }
        return false;
    }
    int *sum = (int *)malloc(sizeof(int) * numsSize);
    sum[0] = nums[0];
    // 从i到i的和
    for (int i = 1; i < numsSize; i++) {
        sum[i] = sum[i - 1] + nums[i];
    }
    if (sum[numsSize - 1] == 0) {
        return true;
    }

    int len = 2;  // 子串长度，从2开始
    int tmp;
    while (len <= numsSize) {
        for (int i = 0; i <= numsSize - len; i++) {
            if (i - 1 < 0) {
                tmp = sum[i + len -1];
            } else {
                tmp = sum[i + len -1] - sum[i - 1];
            }
            if (tmp % k == 0) {
                return true;
            }
        }
        len++;
    }

    return false;
}
```