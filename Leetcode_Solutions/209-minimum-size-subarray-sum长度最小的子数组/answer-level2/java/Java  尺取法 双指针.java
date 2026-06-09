```
public int minSubArrayLen(int s, int[] nums) {
    int sum = 0;
    int left = 0;
    int res = Integer.MAX_VALUE;
    for (int i = 0; i < nums.length; i++) {
        sum += nums[i];
        while (sum >= s) {
            res = Math.min(res, i + 1 - left);
            sum -= nums[left++];
        }
    }
    return res == Integer.MAX_VALUE ? 0 : res;
}
```
