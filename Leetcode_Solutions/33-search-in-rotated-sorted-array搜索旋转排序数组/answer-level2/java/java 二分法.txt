### 解题思路

二分法判断目标数是在mid的前还是在后面的思路

if sums[mid]>sums[start] && sums[mid]<sums[end] :
    if T > sums[mid] : 后
    else 前
else if sums[mid]<sums[start] :
    if T > sums[end] : 前
    else :
        if T < sums[mid] : 前
        else 后
else :
    if T < sums[start] : 后
    else : 
        if T > sums[mid] : 后
        else 前

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0) return -1;
        int mid = nums.length / 2;
        int start = 0, end = nums.length-1;
        while (start <= end) {
            if (nums[mid] == target) return mid;
            if (nums[start] == target) return start;
            if (nums[end] == target) return end;
            if (nums[mid] > nums[start] && nums[mid] < nums[end]) {
                if (target > nums[mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else if (nums[mid] < nums[start]) {
                if (target > nums[end]) {
                    end = mid - 1;
                } else {
                    if (target < nums[mid]) {
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                    }
                }
            } else {
                if (target < nums[start]) {
                    start = mid + 1;
                } else {
                    if (target > nums[mid]) {
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
            }
            mid = (start + end) / 2;
        }
        return -1;
    }


}
```