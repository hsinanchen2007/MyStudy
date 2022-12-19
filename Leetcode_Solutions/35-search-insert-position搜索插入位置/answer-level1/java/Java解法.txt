### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int result = nums.length;//若是target大于nums最后一位
        for (int i = 0; i < nums.length; i++) {
            if (target <= nums[i]) {//若是target小于等于于nums[i]数据，则target索引必是i
                result = i;
                break;
            }
        }
        return result;
    }
}
```