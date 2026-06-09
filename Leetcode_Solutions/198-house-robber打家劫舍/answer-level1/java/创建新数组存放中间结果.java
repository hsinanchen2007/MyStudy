### 解题思路
思路同官方解法，但是新建了一个同样长度的数组存放中间结果，便于理解。

其实使用nums数组本身来存放中间结果也行

### 代码

```java
class Solution {
    public int rob(int[] nums) {
         if(nums == null || nums.length == 0){return 0;}
         // 采用数组的方式存放每一步的执行结果
        int[] result = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            if(i == 0){
                result[i] = nums[i];
            } else if(i == 1){
                result[i] = Math.max(nums[0],nums[1]);
            } else {
                result[i] = Math.max(result[i-2] + nums[i],result[i-1]);
            }
        }
        return result[result.length - 1];
    }
}
```