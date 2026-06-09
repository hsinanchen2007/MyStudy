```
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int begin = 0, end = -1;
        int sum = 0, result = nums.length + 1;
        while (begin < nums.length - 1) {
            if (end + 1 < nums.length && sum < s) {
                end++;
                sum += nums[end];
            } else {
                sum -= nums[begin];
                begin++;
            }

            if (sum >= s) {
                result = Math.min(result, end - begin + 1);
            }
        }
        return result == nums.length + 1 ? 0 : result;
    }
}
```
