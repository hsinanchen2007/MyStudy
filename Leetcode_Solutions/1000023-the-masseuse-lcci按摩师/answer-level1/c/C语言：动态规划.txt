最基本的动态规划题目。和爬楼梯属于同一类

```
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int massage(int* nums, int numsSize){
    if ((nums == NULL) || (numsSize <= 0)) {
        return 0;
    }

    int fstatus[numsSize + 1];

    // init
    for (int i = 0; i <= numsSize; i++) {
        fstatus[i] = 0;
    }

    fstatus[1] = nums[0];

    for (int i = 1; i < numsSize; i++) {
        fstatus[i + 1] = MAX(fstatus[i], fstatus[i - 1] + nums[i]);
    }

    return fstatus[numsSize];
}
```
