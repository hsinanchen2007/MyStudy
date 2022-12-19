### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        return jump(nums, nums.length - 1);
    }

    public boolean jump(int[] nums, int index) {
        boolean result = false;
        if (index <= 0) {
            return true;
        }
        for (int i = 1;i <= index;i++) {
            if (nums[index - i] >= i) {
                result = jump(nums, index - i);
                break;
            }
        }
        return result;
    }
}
```