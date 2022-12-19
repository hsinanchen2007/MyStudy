### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int slow = 0;
        int fast = 0;
        while (fast < nums.length ){
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            } 
            fast ++;
        }
        return slow;
    }
}
```