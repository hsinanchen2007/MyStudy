int Comp (const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int triangleNumber(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), Comp);

    int result = 0;

    for (int i = 0; i < numsSize; i++) {
        int j = i + 1;
        int k = numsSize - 1;

        while (j < k) {
            if (nums[j] + nums[k] > nums[i]) {
                result += k - j;
                j++;
            } else {
                k--;
            }
        }
    }

    return result;
}

![image.png](https://pic.leetcode-cn.com/8665a94e4c806fae389dd2013b0a95266914d89c458917ddd0f207e95d3fc0e4-image.png)
