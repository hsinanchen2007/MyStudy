### 解题思路
采用递归方式求解。首先找到数组的中间元素A[mid]=n,如果n==mid,则尝试从左边查找是否存在更小的魔术索引，如果存在，则使用该魔术索引；如果不存在，则使用mid作为魔术索引；如果n!=mid，则尝试从左右两边分别查找是否存在魔术索引，最后使用最小的魔术索引，如果未找到则返回-1。
主要解题思想为递归，只是采用了二分思想使用中间元素作为分割点。

### 代码

```java
class Solution {
    public int findMagicIndex(int[] nums) {
        return helper(nums, 0, nums.length -1);
    }

    public int helper(int[] nums, int start, int end) {
        if (start > end) {
            return -1;
        }
        int mid = start + (end - start) / 2;
        int n = nums[mid];
        if (n == mid) {
            //去左边查找是否还存在更小的魔术索引
            int lo = helper(nums, start , mid - 1);
            if (lo != -1) {
                return lo;
            }
            return mid;
        } else {
            //从左右两边查找是否存在魔术索引
            int lo = helper(nums, start, mid - 1);
            int hi = helper(nums, mid + 1, end);
            if (lo != -1) {
                return lo;
            }
            if (hi != -1) {
                return hi;
            }
            return -1;
        }
    }
}
```