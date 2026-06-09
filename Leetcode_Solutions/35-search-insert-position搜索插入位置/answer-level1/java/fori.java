### 解题思路
看到都是用的二分 , 菜鸡写法竟然过了

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < target) {
                j++;
            }
            if (nums[i] >= target) {
                return j;
            }
        }
        return j;
    }
}
```