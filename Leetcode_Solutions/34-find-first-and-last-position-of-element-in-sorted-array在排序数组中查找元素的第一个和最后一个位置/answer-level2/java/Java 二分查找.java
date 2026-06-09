### 一种比较节省脑细胞的二分模板

```java
/**
 * l + 1 < r 形式的二分
 * l = mid / r = mid  (无需+1或-1)
 * 只需要分析清楚判断条件, 什么时候 l = mid, 什么时候 r = mid
 * 不过最后需要再额外判断 l 和 r 哪个是答案
 */
class Solution {
    public int[] searchRange(int[] nums, int target) {
        if (nums == null || nums.length < 1) {
            return new int[]{-1, -1}; 
        }

        // 找第一个
        int l = 0, r = nums.length - 1; 
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid;
            } else {
                r = mid;
            }
        }
        int first = nums[l] == target ? l : (nums[r] == target ? r : -1);

        // 找最后一个
        l = 0; 
        r = nums.length - 1; 
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid;
            }
        }
        int last = nums[r] == target ? r : (nums[l] == target ? l : -1);
        return new int[]{first, last};
    }
}
```