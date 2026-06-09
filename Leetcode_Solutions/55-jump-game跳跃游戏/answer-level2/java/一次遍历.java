### 解题思路
从头开始遍历，找到能走到的最长距离

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        if (nums.length == 0)
            return false;
        
        int len = nums[0];
        
        for (int i=0; i<=len; ++i){
            if (i + nums[i] >= nums.length-1)
                return true;
            if (i + nums[i] > len)
                len = i+nums[i];
            
        }
        return false;
    }
}
```