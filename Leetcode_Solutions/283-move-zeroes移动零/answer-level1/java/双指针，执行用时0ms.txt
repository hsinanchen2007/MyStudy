### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public void moveZeroes(int[] nums) {
        int i = 0;
        for (int j = 0; j < nums.length; ++j) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                i++;
            }
        }

        for (; i < nums.length; ++i) {
            nums[i] = 0;
        }
    }
}
```