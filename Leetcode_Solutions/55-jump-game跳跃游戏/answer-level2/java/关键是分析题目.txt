### 解题思路
这个题目有两个关键点：
1.  【每个元素代表你在该位置可以跳跃的最大长度】代表可以跳跃的最大长度，不是刚好跳跃那个长度，比如：某个值为8，数组长度为4，则我可以跳跃4次达到最后一个值
2. 当所有元素的最大步长小于对应元素索引，则代表某个元素肯定为到达不了当前元素

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length < 2){
            return true;
        }
        if(nums[0] == 0){
            return false;
        }
        int maxStep = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i > maxStep) {
                return false;
            }
            if(nums[i] + i > maxStep){
                maxStep = nums[i] + i;
            }
            if (maxStep > nums.length - 1) {
                break;
            }
        }

        return true;
    }
}
```