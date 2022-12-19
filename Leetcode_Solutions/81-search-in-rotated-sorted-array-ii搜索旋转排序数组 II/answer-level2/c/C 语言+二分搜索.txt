### 解题思路
此处撰写解题思路

/* 允许重复元素，则上一题中如果A[m]>=A[l], 那么[l,m] 为递增序列的假设就不能成立了，比如[1,3,1,1,1] */

/*
    如果A[m]>=A[l] 不能确定递增，那就把它拆分成两个条件：
    • 若A[m]>A[l]，则区间[l,m] 一定递增
    • 若A[m]==A[l] 确定不了，那就l++，往下看一步即可。
*/

### 代码

```c
/* 允许重复元素，则上一题中如果A[m]>=A[l], 那么[l,m] 为递增序列的假设就不能成立了，比如[1,3,1,1,1] */

/*
    如果A[m]>=A[l] 不能确定递增，那就把它拆分成两个条件：
    • 若A[m]>A[l]，则区间[l,m] 一定递增
    • 若A[m]==A[l] 确定不了，那就l++，往下看一步即可。
*/
bool search(int* nums, int numsSize, int target){
    int left, right, mid;

    if (nums == NULL || numsSize <= 0) {
        return false;
    }

    left = 0;
    right = numsSize - 1;
    while(left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            return true;
        } else if (nums[left] < nums[mid]) { // 左边有序
            if (target >= nums[left] && target <= nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else  if (nums[left] > nums[mid]) {
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else {
            left++;
        }
    }

    return false;
}
```