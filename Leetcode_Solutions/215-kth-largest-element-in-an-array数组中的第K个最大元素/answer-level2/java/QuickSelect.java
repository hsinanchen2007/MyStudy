### 解题思路
我先偷懒占个位置，接下来会更新QuickSelect。

### 代码

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length - k];
    }
}
```