
```
#define MAXSIZE 1002
int movesToMakeZigzag(int* nums, int numsSize){
    int ret1 = 0;
    int ret2 = 0;
    int min = 0;

    /* 第一种情况，减两边 */
    for (int i = 1; i < numsSize; i = i + 2) {
        if (nums[i-1] >= nums[i]) {
            if (i == 1) {
                min = nums[0];
            } else {
                min = nums[i -2] -1 < nums[i-1] ? nums[i -2] -1 : nums[i-1];
            }
            ret1 += nums[i] <= min ? min - nums[i] + 1 : 0;
        }
        if (i + 1 < numsSize && nums[i+1] >= nums[i]) {
            ret1 += nums[i+1] - nums[i] + 1;
        }
    }

    /* 第二种情况，减中间,这种情况比较好处理，完全不需要考虑两边的值是否被减过，
     * 因为两边就没动过，相邻的中间的值又不互相影响,因此取两边的最小值直接计算即可。
     */
    for (int i = 1; i < numsSize; i = i + 2) {
        if (i + 1 >= numsSize) {
            min = nums[i - 1];
        } else {
            min = nums[i - 1] < nums[i + 1] ? nums[i - 1] : nums[i + 1];
        }
        ret2 += nums[i] >= min ? nums[i] - min + 1 : 0;
    }
 
    return ret1 < ret2 ? ret1 : ret2;
}

```
