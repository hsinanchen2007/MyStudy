```java
class Solution {
    public int jump(int[] nums) {
        if (nums == null || nums.length < 2) return 0;
        int res = 1;
        for(int i = 0; i < nums.length;) {
            int end = i + nums[i];
            if (end >= nums.length -1) {
                return res;
            }
            int max = end;
            for(int j = end - 1; j > i; j--) {
                max = j + nums[j] > max + nums[max]? j: max;
            }
            i = max;
            res ++;
        }
        return -1;
    }
}