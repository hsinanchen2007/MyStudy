### 解题思路
参考注释
### 代码

习惯性思维使用快慢指针写法（操作较多）：
```java
class Solution {
    public void moveZeroes(int[] nums) {
        int i = 0; // 快指针
        int k = 0; // 慢指针
        int count = 0; // 0 的数量
        int length = nums.length;
        while (i < length) {
            if (nums[i] == 0) {
                count++;
            } else {
                nums[k++] = nums[i];
            }
            i++;
        }

        // 最后补齐 0 的位置
        for (int i1 = 0; i1 < count; i1++) {
            nums[length - 1 - i1] = 0;
        }
    }
}
```
**优化一波为：**
```java
public void moveZeroes(int[] nums) {
        int k = 0; // 慢指针
        for (int num : nums) {
            if (num != 0) {
                nums[k++] = num;
            }
        }
        while (k < nums.length) {
            nums[k++] = 0;
        }
}
```