```
int ComputeSums(const int* nums, int numsSize, int divideNum, int threshold)
{
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        count += (nums[i] + divideNum - 1) / divideNum;
        if (count > threshold) {
            break;
        }
    }

    return count;
}

int BinarySearch(const int* nums, int numsSize, int left, int right, int threshold)
{
    int mid;

    while (left < right) {
        mid = left + (right - left) / 2;
        if (ComputeSums(nums, numsSize, mid, threshold) <= threshold) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int smallestDivisor(int* nums, int numsSize, int threshold){
    int left = 1;
    int right = 1000000;

    return BinarySearch(nums, numsSize, left, right, threshold);
}
```
执行结果：
通过
显示详情
执行用时 :36 ms, 在所有 c 提交中击败了100.00% 的用户
内存消耗 :9.5 MB, 在所有 c 提交中击败了100.00%的用户