
将每个点想象成加油站，车子先一直往前开，没油了，就直接获得开的范围中最多油的加油站。

```
int jump(int* nums, int numsSize)
{
    if (numsSize <= 1) return 0;
    for (int i = 0; i < numsSize; i++) {
        nums[i] += i;
    }
    int ret = 1;
    int leftStep = nums[0];
    int maxStep = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (leftStep < i) {
            ret++;
            leftStep = maxStep;
        }
        if (nums[i] > maxStep) {
            maxStep = nums[i];
        }
    }
    return ret;
}
```
