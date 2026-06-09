### 解题思路
贪心法 每次选取上一跳中可达范围 i+a[i]最大的，迭代可达范围，当可达范围到达终点时直接返回true

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        if (nums.length==0) return false;
        int right = nums[0];
        for (int i=0;i<=right;i++) {
            if (right >= nums.length-1) return true;
            if (i+nums[i]>right) right = i+nums[i];
        }
        return false;
    }
}
```