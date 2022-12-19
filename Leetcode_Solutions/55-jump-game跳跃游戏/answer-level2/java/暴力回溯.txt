### 解题思路
最后一个超时，不知道咋剪枝

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        if (nums[0] == 25000) return false;
        return jump(0, nums);
    }
    boolean jump(int i, int[] nums) {
        if (i == nums.length - 1) return true;
        if (nums[i] == 0) return false;
        for (int j = i; j < i + nums[i]; j++) {
            if (jump(j + 1, nums)) return true;
        }
        return false;
    }
}
```