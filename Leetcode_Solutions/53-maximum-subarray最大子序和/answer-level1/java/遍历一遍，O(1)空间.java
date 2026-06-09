### 解题思路
 
用sum记录当前和，用max记录最大和
当sum小于0时，相当于从下一个i开始并且加了一个负数，直接归0


### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int sum = 0, max = nums[0];
        for(int i = 0; i < nums.length; i++){
            if(sum < 0) sum = 0;
            sum += nums[i];
            max = Math.max(max,sum);
        }
        return max;
    }
}
```