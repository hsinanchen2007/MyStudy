### 解题思路
一次遍历，采用双指针方式，直接挪动元素。

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int start = 0;
        int end = 1;
        while(end < nums.length) {
            if(nums[end] == nums[start]) {
                end ++;
            } else {
                start ++;
                nums[start] = nums[end];
            }
        }
        return start + 1;
    }
}
```