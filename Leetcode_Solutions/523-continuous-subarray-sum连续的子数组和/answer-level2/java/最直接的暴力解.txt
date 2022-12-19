### 解题思路
最直接的暴力解了吧。

### 代码

```java
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        if (k == 0) {
            int count = 0;
            for (int num : nums) {
                if (num == 0) {
                    count++;
                    if (count > 1) return true;
                } else {
                    count = 0;
                }
            }
        } else {
            for (int start = 0; start < nums.length; start++) {
                int sum = 0;
                for (int end = start; end < nums.length; end++) {
                    sum += nums[end];
                    if ((sum % k) == 0 && (end - start) > 0) return true;
                }
            }
        }
        return false;
    }
}
```