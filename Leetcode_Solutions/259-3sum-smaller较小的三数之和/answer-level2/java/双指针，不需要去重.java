### 解题思路
同15. 三数之和 16. 最接近的三数之和

### 代码

```java
class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        if (nums == null || nums.length < 3) {
            return 0;
        }
        Arrays.sort(nums);
        int n = nums.length;
        int cnt = 0;
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    cnt = cnt + (right - left);
                    left++;
                } else {
                    right--;
                }
            }
        }
        return cnt;
    }
}
```