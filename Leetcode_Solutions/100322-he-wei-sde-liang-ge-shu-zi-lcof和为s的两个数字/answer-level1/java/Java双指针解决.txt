### 解题思路
双指针
less初始为头
more初始为尾
### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        if (target <= 0) return new int[0];
        int len = nums.length;
        int less = 0; 
        int more = len - 1;

        while (less < more) {
            if (nums[less] + nums[more] < target) {
                less++;
            } else if (nums[less] + nums[more] > target) {
                more--;
            } else {
                return new int[] {nums[less], nums[more]};
            }
        }

        return new int[0];
    }
}
```