### 解题思路
通过增加一个临时下标记录数组中当前非零值，从而通过一次循环不断更新非零值下标，从而达到改变数组中0的位置

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                if (j != i) {
                    nums[i] = 0;
                }
                j++;
            }
        }
    }
}
```