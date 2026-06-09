直接贴代码
```
class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = 0;
        for (int i = 0; i < nums.length; i++) {
            int sum = 0;
            for (int j = i; j < nums.length; j++) {
                sum+=nums[j];
                if (sum == k) {
                    n++;
                }
            }
        }
        return n;
    }
}
```
时间复杂度 O(n^2)
空间复杂度 O(1)

