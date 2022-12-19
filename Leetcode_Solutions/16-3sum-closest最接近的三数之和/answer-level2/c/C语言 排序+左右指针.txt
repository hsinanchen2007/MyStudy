### 解题思路
先排序，然后左右指针逼近target，记录最小diff的sum值

![image.png](https://pic.leetcode-cn.com/4d4123f8b998b3d186c752e30aae06a8178f1630c76618e32c95c01ee6409f8d-image.png)

### 代码

```c
int cmp(const void *a, const void *b)
{
    return *(int*)a > *(int*)b;
}

void prepare(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);
}

int proc(int* nums, int numsSize, int target)
{
    int i, sum, rlt, diff;
    int minDiff = INT_MAX;
    int l, r;
    for (i = 0; (i + 2) < numsSize; i++) {
        l = i + 1;
        r = numsSize - 1;
        while(l < r) {
            sum = nums[i] + nums[l] + nums[r];
            diff = abs(target - sum);
            if (diff < minDiff) {
                rlt = sum;
                minDiff = diff;
                //printf("%d, %d, %d\n", nums[i], nums[l], nums[r]);
            }
            if (target > sum) {
                l++;
            } else if (target < sum) {
                r--;
            } else {
                break;
            }
        }
        if (minDiff == 0) {
            break;
        }
    }
    return rlt;
}

int threeSumClosest(int* nums, int numsSize, int target){
    prepare(nums, numsSize);
    return proc(nums, numsSize, target);
}
```