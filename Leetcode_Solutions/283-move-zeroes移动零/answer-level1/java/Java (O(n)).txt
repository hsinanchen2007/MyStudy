### 解题思路
额外添加一个下标，标记应该放入的数值的位置。（从0起）

### 代码

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int validIndex = 0;
        for (int i = 0; i < nums.length; i++){
            if (nums[i] != 0){
                nums[validIndex++] = nums[i];
            }
        }
        for (int i = validIndex; i < nums.length; i++){
            nums[i] = 0;
        }
    }
}
```