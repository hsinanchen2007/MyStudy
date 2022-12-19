### 解题思路
因为出现次数大于 n/2,因此 排序后 n/2 的肯定是结果 无论该数值是大还是小

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];

    }
}
```