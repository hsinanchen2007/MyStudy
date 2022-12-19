### 解题思路
利用列表的特性，使下标和数字一直
nums[i]!=i说明i位置上的数字与i不一致
这时判断它和它应当在的位置上的数字是否一致，
nums[i]==nums[nums[i]] 如果一致，则为重复，
不一致则对调两者位置

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
         int len = nums.length;
        for (int i = 0; i < len; i++) {
            if (nums[i] != i && nums[i] == nums[nums[i]])
                return nums[i];
            while (nums[i] != i) {
                int tmp = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = tmp;
            }
        }
        return -1;
    }
}
```