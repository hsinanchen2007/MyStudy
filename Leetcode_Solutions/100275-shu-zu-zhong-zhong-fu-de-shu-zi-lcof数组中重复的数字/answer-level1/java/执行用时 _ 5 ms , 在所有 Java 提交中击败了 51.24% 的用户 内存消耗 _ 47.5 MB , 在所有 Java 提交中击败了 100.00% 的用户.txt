### 解题思路
排序，依次遍历，从前往后，找到重复即停止循环并返回该值，否则返回-1.

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        Arrays.sort(nums);
        for(int i = 0;i<nums.length-1;i++) {
            if(nums[i]==nums[i+1]) {
                return nums[i];
            }
        }
        return -1;
    }
}
```