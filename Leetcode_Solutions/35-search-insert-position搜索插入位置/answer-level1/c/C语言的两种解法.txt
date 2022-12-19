## 暴力破解
```
int searchInsert(int* nums, int numsSize, int target){
    int cur = 0;
    while (cur < numsSize && nums[cur] < target) cur++;
    return cur;
}
```
- 时间复杂度：O(n)，最坏情况为查找的数是数组中最大的元素。
- 空间复杂度：O(1)
## 二分查找法
```
int searchInsert(int* nums, int numsSize, int target){
    int mid, left = 0, right = numsSize - 1;

    while (left <= right)
    {
        mid = (left + right) >> 1; //右移一位相当于除以2
        if (target < nums[mid])
            right = mid - 1;
        else if (target > nums[mid])
            left = mid + 1;
        else
            return mid;
    }
    return left;
}
```
- 时间复杂度为：O(n)
- 空间复杂度为：O(1)