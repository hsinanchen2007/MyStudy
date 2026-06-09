### 代码

```java
class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        Arrays.sort(nums);
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        int mid = sum / 2;
        List<Integer> res = new ArrayList<>();
        int tempmax = 0;
        for (int i = nums.length - 1; i >= 0; i--) {
            tempmax += nums[i];
            res.add(nums[i]);
            if (tempmax > mid) {
                return res;
            }
        }
        return res;
    }
}
```