### 解题思路
数组排序，因为超过一半了，所以最中间的元素一定即为所求
### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
    }
}
```