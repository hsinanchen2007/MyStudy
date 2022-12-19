画图，nums[m] == target 直接返回
否则 一共六种情况，其中三种是让右边向中间规约，其余都是左边向中间规约。
```java
class Solution {
    public int search(int[] nums, int target) {
        int l = 0;
        int r = nums.length - 1;
        while(l <= r) {
            int m = l + (r - l)/2;
            if (nums[m] == target) return m;
            if ((nums[m] < nums[l] && nums[l] <= target) || (nums[l] <= target && target < nums[m]) || (target < nums[m]  && nums[m] < nums[l])) {
                r = m - 1;
            }else {
                l = m + 1;
            }
        }
        return -1;
    }
}