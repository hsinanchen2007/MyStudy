### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        int pre = nums[0];
        int curr = Math.max(nums[0], nums[1]);
        for (int i = 2; i < nums.length; i++) {
            int temp = Math.max(curr, pre + nums[i]);
            pre = curr;
            curr = temp;
        }
        return curr;
    }
}
```