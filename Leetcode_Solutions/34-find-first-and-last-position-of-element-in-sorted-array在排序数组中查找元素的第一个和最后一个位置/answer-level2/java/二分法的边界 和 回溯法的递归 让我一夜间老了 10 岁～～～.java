```java
class Solution {
    // 一种直接的解法，线性扫描，但是其时间复杂度是 n，不满足条件呀！
    public int[] searchRange(int[] nums, int target) {
        int[] ans = {-1, -1};
        if (nums.length == 1) {
            return nums[0] == target ? new int[] {0, 0} : ans;
        }
        ans[0] = searchRange(nums, target, true);
        ans[1] = searchRange(nums, target, false);
        return ans;
    }

    // 二分法查询左边界
    private int searchRange(int[] nums, int target, boolean left) {
        int start = 0;
        // 注意这个地方在 [2, 2] 的时候会，如果 - 1 的话，right 计算出来的是 0；
        // 主要是 start 和 end 是相邻的，所以这里没有 - 1，让 start 和 end 中间间隔一个；
        int end = nums.length;
        int res = -1;
        while (start < end) {
            int mid = (start + end) >>> 1; // 左中位数
            // 当大于 mid 的时候，说明 target 在最右边
            // 此时我们更新 start；
            if (nums[mid] < target) {
                start = mid + 1;
               // 当小于 mid 的时候，说明 target 在最左边
               // 此时我们更新 end；
            } else if (nums[mid] > target) { 
                end = mid;
            } else {
                // 此时我们知道了 target，我们用 res target 的下标；
                res = mid;
                if (left) { //
                    end = mid;
                } else {
                    start = mid + 1;
                }
            }
        }
        return res;
    } 
}
```
