# 解法1：二分查找+贪心
## 算法描述
令结果为r，可知r一定满足  max(nums) < r < sum(nums)。
并且r存在单调性，即若r0 < r1，则若r0能分割，r1也必定能。
所以可以用二分法搜索最小的r。
在计算r能否分割数组时，因为要求连续的子数组，所以使用贪心算法即可。

## 复杂度分析
令数组长度为n：
时间复杂度：O（nlogn）
空间复杂度：O（1）

## 提交结果
通过

## 参考代码
```
bool try_split(int *nums, int n, int limit, int m) {
    long long sum = 0;
    int count = 1;
    for (int i = 0; i < n; i++) {
        if (sum + nums[i] > limit) {
            sum = 0;
            count++;
        }
        sum += nums[i];
    }

    return count <= m;
}

int splitArray(int* nums, int numsSize, int m){
    long long left = 0;
    long long right = 0;
    for (int i = 0; i < numsSize; i++) {
        right += nums[i];
        left = left >= nums[i] ? left : nums[i];
    }

    while(left < right) {
        int mid = left + (right - left) / 2;
        if(try_split(nums, numsSize, mid, m)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return (int)left;
}
```