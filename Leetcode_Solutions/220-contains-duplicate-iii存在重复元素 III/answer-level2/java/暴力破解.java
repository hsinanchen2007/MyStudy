### 解题思路
暴力破解

### 代码

```java
class Solution {
 public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        /**
         * 遍历一遍,存在则返回,时间复杂度为O(n*k),空间复杂度为O(1)
         */
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j <= i + k; j++) {
                if (j < nums.length) {
                    if (Math.abs((long)nums[j] - (long)nums[i]) <= t) return true;
                }
            }
        }
        return false;
    }
}
```