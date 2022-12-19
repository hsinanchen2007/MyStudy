
class Solution {
    public int pivotIndex(int[] nums) {
        if (nums == null || nums.length == 0) {
            return -1;
        }
        
        for (int i = 0; i < nums.length; i++) {
            int m = 0;
            int n = i + 1;
            int left = 0;
            int right = 0;
            while (m < i) {
                left += nums[m];
                m++;
            }
            while (n < nums.length) {
                right += nums[n];
                n++;
            }
            if (left == right) {
                return i;
            }
        }
        return -1;
    }
}
```
