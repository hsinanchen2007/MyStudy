### 解题思路
排序，然后中间那个一定是！不知道面试的时候这样写行不行...

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
    }
}
```