### 解题思路
最简单的思路和代码，为什么会百分百，有点不可思议，本来以为要用二分法效率更高的，可能用例数目比较少的原因。

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] >= target) {
                return i;
            } 
        }
        return nums.length;
    }
}
```