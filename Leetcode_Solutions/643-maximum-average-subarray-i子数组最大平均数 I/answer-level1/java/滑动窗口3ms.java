```java
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int len = nums.length;
        int sum = 0;
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < len; i++) {
            if (i <= k - 1) {
                sum += nums[i];
            } else {
                sum += nums[i] - nums[i - k];
            }
            if (i >= k - 1) {
                max = Math.max(max, sum);
            }
        }
        return (double) max / k;
    }
}
```