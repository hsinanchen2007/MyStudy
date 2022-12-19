### 解题思路
我们从数组的最后往前判断。例如，最后的index为i1，我们就要在之前发现是否有i2连接i1，然后是否有i3连接i2，一直到index 0连接ix。
如果index 0无法连接之前已经连接好的通道，那么该数组便无法完成跳跃。

### 代码

```java
class Solution {
    public boolean canJump(int[] nums) {
        // can achieve to last index?
        // [2,3,1,1,4]
        // we found index1 and index 3 can achieve to last index
        if (nums.length == 1){
            return true;
        }
        boolean can_jump = false;
        int current_index = nums.length - 2;
        int target_index = nums.length - 1;

        // we do judgement from back to beginning, starts from the last index, we want to find any index i1 which connects to last index
        // then we want to find any index that connects to i1
        // recursively do this until first index has connections to last index
        // if not, return false
        while(current_index >= 0){
            if(nums[current_index] + current_index < target_index){
                current_index--;
                if (current_index < 0){
                    return false;
                }
            } else {
                target_index = current_index;
                current_index--;
            }
        }
        return true;
    }
}
```