完全是一道阅读理解题，子序列和非递增让人误以为要高大上
结果写了一会dfs后发现，就是先非递增排序，然后子序列其实是子集的意思，从头开始求和就好了

int Cmp(const void *a, const void *b) 
{
    return *(int *)b - *(int *)a;
}

int* minSubsequence(int* nums, int numsSize, int* returnSize){
    qsort(nums, numsSize, sizeof(int), Cmp);
    int i;
    int allsum = 0;
    for (i = 0; i < numsSize; i++) {
        allsum += nums[i];
    }
    int sum = 0;
    int cnt = 0;
    int *res = (int *)malloc(numsSize * sizeof(int));
    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (sum <= allsum / 2) {
            res[cnt++] = nums[i];
        } else {
            res[cnt++] = nums[i];
            break;
        }
    }
    *returnSize = cnt;
    return res;
}

