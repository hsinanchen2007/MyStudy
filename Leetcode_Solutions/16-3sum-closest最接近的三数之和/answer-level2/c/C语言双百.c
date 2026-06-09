### 解题思路
直接看代码，而且考虑了整形溢出问题

### 代码

```c
int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}


int threeSumClosest(int* nums, int numsSize, int target){
    int three, left, right;
    long sum;
    long diff;
    long abs = INT_MAX;
    long min;

    if ((nums == NULL) || (numsSize == 0)) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    }

    if (numsSize == 2) {
        return nums[0] + nums[1];
    }

    if (numsSize == 3) {
        return nums[0] + nums[1] + nums[2];
    }

    qsort(nums, numsSize, sizeof(int), cmp);

    for (three = 0; three < numsSize - 2; three++) {
        left = three + 1;
        right = numsSize - 1;
        
        while (left < right) {
            sum = (long)nums[three] + (long)nums[left] + (long)nums[right];
            
            if (sum == (long)target) {
                min = sum;
                break;
            } else if (sum > (long)target){
                right--;
            } else {
                left++;
            }

            diff = sum - (long)target;
            diff = diff < 0 ? 0 - diff : diff;
            if (abs > diff) {
                abs = diff;
                min = sum;
            }
        }

        if (left != right) {
            break;
        }
    }

    return min;
}
```