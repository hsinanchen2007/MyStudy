### 解题思路
注意 ：l 和 r  维护 [l...r]的闭区间

### 代码

```java
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int l = 0;
        int r = -1; // s = [i ...j]
        int res = nums.length + 1; // the length of the sub array.
        int sum = 0; // the sum of the sub array.
        while (l < nums.length) {
            if (r + 1 < nums.length && sum < s) {
                sum += nums[++r];
            } else {
                sum -= nums[l++];
            }
            if (sum >= s) {
                res = Math.min(res, r - l + 1);
            }
        }
        if (res == nums.length + 1)
            return 0;
        return res;
    }
}
```