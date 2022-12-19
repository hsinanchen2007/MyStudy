直接快排，然后找到第1个非0数，肯定是最小值，然后从这个点开始向右循环查找到+1+2+3+K个数，每找到1个将对应位置的nums清0, 下次循环直接从当前最小值位置往下找下一个大于0的数，如果查找期间发现某个Min的值找不到连续+K个数，直接返回false，所有循环结束，返回true。

```
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
bool isPossibleDivide(int* nums, int numsSize, int k){
    int min, cnt, j;
    if (numsSize % k != 0) {
        return false;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            min = nums[i];
            cnt = 0;
            for (j = i; (j < numsSize) && (cnt < k); j++) {
                if (nums[j] == min){
                    cnt++;
                    min++;
                    nums[j] = 0;
                }
            }
            if (cnt < k) {
                return false;
            }
        }
    }
    return true;
}
```
