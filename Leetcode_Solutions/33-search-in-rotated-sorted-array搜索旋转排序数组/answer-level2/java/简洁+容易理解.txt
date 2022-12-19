### 思路
由于题目要求时间复杂度为 O(log n)，故实现为**二分法查找**，关于二分法，一般存在 low,high,mid位，来辅助判断。
- 如果 target 在`[mid+1,high]` 序列中，则`low = mid+1`,否则` high = mid`,关键是如何判断 target在`[mid+1,high]`序列中,具体判断如下：
- 当`[0, mid]` 序列是升序: `nums[0] <= nums[mid]`, 当`target > nums[mid] || target < nums[0]` ,则向后规约
- 当`[0, mid]` 序列存在旋转位: `nums[0] > nums[mid]`,当`target < nums[0] && target > nums[mid]`,则向后规约
- 当然其他其他情况就是向前规约了

循环判断，直到排除到只剩最后一个元素时，退出循环，如果该元素和 target 相同，直接返回下标，否则返回 -1。
### 实现
```
class Solution {
    public int search(int[] nums, int target) {
        int lo = 0;
        int hi = nums.length - 1;

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            // 当[0,mid]有序时,向后规约条件
            if (nums[0] <= nums[mid] && (target > nums[mid] || target < nums[0])) {
                lo = mid + 1;
                // 当[0,mid]发生旋转时，向后规约条件
            } else if (target > nums[mid] && target < nums[0]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo == hi && nums[lo] == target ? lo : -1;
    }
}
```
算法不仅需要简洁，也需要容易理解。