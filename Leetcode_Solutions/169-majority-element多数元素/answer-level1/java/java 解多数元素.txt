### 解题思路
先排序，出现次数大于 ⌊ n/2 ⌋ 的元素必定是nums.length/2

### 代码

```java
class Solution {
     public static  int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
}
}
```