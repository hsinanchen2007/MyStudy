### 解题思路
先排序，因为存在多数元素，然后取中间值即可。

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
    }
}
```