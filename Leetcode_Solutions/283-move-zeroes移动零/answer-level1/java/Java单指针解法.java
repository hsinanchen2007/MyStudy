```java
class Solution {
    public void moveZeroes(int[] nums) {
        // 使用 j 记录下一个非0元素存放的位置
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                if (i != j) {
                    nums[i] = 0;
                }
                j++;
            }
        }
    }
}

```
