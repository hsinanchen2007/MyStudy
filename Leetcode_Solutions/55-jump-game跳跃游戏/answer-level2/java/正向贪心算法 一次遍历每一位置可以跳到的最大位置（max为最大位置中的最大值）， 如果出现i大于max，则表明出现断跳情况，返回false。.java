### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        int max = 0;
        for(int i = 0;i<nums.length;i++){
            if(i>max) return false;
            if(i+nums[i]>max) max=i+nums[i];
        }
        return true;
    }
}
```