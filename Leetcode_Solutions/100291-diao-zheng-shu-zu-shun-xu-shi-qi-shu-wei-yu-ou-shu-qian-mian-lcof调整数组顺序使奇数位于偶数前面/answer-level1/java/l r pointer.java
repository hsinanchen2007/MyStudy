### 解题思路
使用两个指针来解决问题

### 代码

```java
class Solution {
 public int[] exchange(int[] nums) {
        if (nums == null || nums.length == 0 || nums.length == 1) {
            return nums;
        }
        // 双指针
        int l = 0, r = nums.length - 1;
        while (l < r) {

            // 如果是奇数，则l++，直到遇到偶数
            while (l < r) {
                if ((nums[l] & 1) == 1) {
                    l ++;
                } else {
                    break;
                }
            }

            // 如果是偶数，则r--，直到遇到奇数
            while (l < r) {
                if ((nums[r] & 1) == 0) {
                    r --;
                } else {
                    break;
                }
            }

            // 调整 nums[l] 和 nums[r]
            if (l < r) {
                int t = nums[l];
                nums[l] = nums[r];
                nums[r] = t;
            }
        }
        return nums;
    }
}
```