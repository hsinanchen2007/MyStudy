### 解题思路
此处撰写解题思路

### 代码

```c
//如果中间的数字小于最右边的数，则右半段有序；若中间的数大于最右边的数，则左半段有序
//这里注意判断的条件
int search(int* nums, int numsSize, int target){
    int l = 0;
    int r = numsSize-1;
    if (numsSize == 0) {
        return -1;
    }
    if (nums[l] == target) {
        return l;
    }
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        if (nums[l] < nums[mid]) {
            if (nums[l] <= target && target <= nums[mid]) {
                r = mid;
            } else {
                l = mid;
            }
        } else if (nums[l] > nums[mid]) {
            if (nums[mid] <= target && target <= nums[r]) {
                l = mid;
            } else {
                r = mid;
            }
        } else {
            l++; //这里为啥要l++呢
        }
    }
    if (nums[l] == target) {
        return l;
    }
    if (nums[r] == target) {
        return r;
    }
    return -1;
}
```