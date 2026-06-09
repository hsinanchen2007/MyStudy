### 解题思路
用一个临时数组的下标记录出现过的数字。

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
 int amount = nums.length;
        int[] temp = new int[amount];
        for (int i = 0; i < amount; i++) {
            if (temp[nums[i]] == 1) return nums[i];
            else temp[nums[i]] = 1;
        }
        return 0;
    }
}
```