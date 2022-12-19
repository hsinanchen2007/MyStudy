### 解题思路
把元素大小改为 1-n
参考 LeetCode442 https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/
将数组中的每个值所对应的下标的值，修改为对应的负值，如果该下标的值已经为负值，则意味着该下标的数出现过2次

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        // 把元素大小改为 1-n
        // 参考 LeetCode442 https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/
        for (int i = 0; i < nums.length; i++) {
            nums[i]++;
        }
        for (int num : nums) {
            if (nums[Math.abs(num)-1] < 0) {
                return Math.abs(num) - 1;
            } else {
                nums[Math.abs(num) - 1] *= -1;
            }
        }
        throw new RuntimeException("has no answer.");
    }
}
```