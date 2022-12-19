### 解题思路
此处撰写解题思路
1，先排序
2，根据下标关系获取最终结果

```java
class Solution {
      public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        int result = nums[nums.length-k];
        return result;
    }
}
```