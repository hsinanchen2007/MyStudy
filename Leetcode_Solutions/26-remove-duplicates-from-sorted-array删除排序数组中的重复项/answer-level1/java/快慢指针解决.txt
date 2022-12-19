### 解题思路
快慢指针解决

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int slow = 1;
        int fast = 1;
        int last = nums[0];
        while ( fast < nums.length ) {
            if (nums[fast] != last ) {
                nums[slow] = nums[fast];
                last = nums[fast];
                slow ++;
            }
            fast++;
        }
        return slow;
    }
}
```