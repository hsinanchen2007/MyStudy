之前做过3数之和这道题，所以刚开始以为这道题只要在三数之和的基础上稍微改改即可，实际调试后发现完全不是一回事
1，先排序，通用做法
2，双指针，固定一个子帧i从0到numsSize-2循环，然后调整另外两个j，k指针查找目标结果
3，这道题不用去重，另外在for循环内部不能加入第一个数大于目标值就break的操作，这个地方和三数之和等于0有差异，要仔细想想才能转过弯来
4，关键是判断出来三数之和小于target之后的操作，首先这个是k指针往左的所有数据都满足要求，所以有k-j个组合，然后要注意还要j++继续找

int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int threeSumSmaller(int* nums, int numsSize, int target){
    int i, j, k;
    int tmp;
    int cnt = 0;

    if (nums == NULL || numsSize < 3) {
        return 0;
    }

    qsort(nums, numsSize, sizeof(int), comp);

    for (i = 0; i < numsSize - 2; i++) {
        j = i + 1;
        k = numsSize - 1;

        while (j < k) {
            tmp = nums[i] + nums[j] + nums[k];
            if (tmp < target) {
                cnt += (k - j);
                j++;
            } else {
                k--;
            }
        }
    }
    
    return cnt;
}