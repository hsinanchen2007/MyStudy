### 解题思路
此处撰写解题思路

### 代码

```c
int Comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

bool isPossibleDivide(int* nums, int numsSize, int k)
{
    if (numsSize % k) {
        return false;
    }

    qsort(nums, numsSize, sizeof(int), Comp);

    int len = numsSize / k;
    int i = 0;
    int last;

    while (i < len) {
        int conut = 0;
        int t;
        for (t = 0; t < numsSize; t++) {
            if (nums[t] != 0) {
                last = nums[t];
                nums[t] = 0;
                conut++;
                break;
            }
        }

        for (int j = t + 1; j < numsSize; j++) {
            if (last + 1 == nums[j]) {
                last = nums[j];
                nums[j] = 0;
                if (++conut == k) {
                    break;
                }
            }
        }

        if (conut != k) {
            return false;
        }
        i++;
    }

    return true;
}
```