### 解题思路
一次遍历，快慢指针实现

### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int start = 0;
        int end = 0;
        while(end < nums.length) {
            if(nums[end] != val) {
                nums[start] = nums[end];
                start ++;
            }
            end ++;
        }
        return start;
    }
}
```