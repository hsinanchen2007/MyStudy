### 解题思路
1.判断当前能够跳跃到最远的距离和当前坐标的关系
2.如果当前最远的距离大于坐标，说明可以调到，继续遍历
3.如果当前的最远距离小于当前的坐标，那就不能跳跃到这里

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        // 
        int ans = 0;// 当前能够跳跃到的最远的距离
        for (int i = 0; i < nums.length ; i++) {
            if(ans < i) return false;
            ans = Math.max(ans, i+nums[i]) ;
        }
        return true;
    }
}
```