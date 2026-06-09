### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int i=0;
        while(i<nums.length&&nums[i]<target)i++;
        return i;
    }
}
```