### 解题思路
此题可以转变思路：求除了自身以外数组的乘积 = 当前数字左边数字乘积 * 当前数字右边数字乘积
那么可以初始化两个数组，注意初始化时候初始值的确定，然后进行计算。
最后只需要计算output当前数字之外的乘积就可以了。

### 代码

```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] leftplus = new int[nums.length];
        int[] rightplus = new int[nums.length];
        int[] output = new int[nums.length];

        if(nums.length == 0)
            return new int[nums.length];
        leftplus[0] = 1;
        rightplus[nums.length-1] = 1;
        
        for(int i = 1; i < nums.length; i++){
            leftplus[i] = leftplus[i-1] * nums[i-1];
        }

        for(int i = nums.length - 2; i >= 0; i--){
            rightplus[i] = rightplus[i+1] * nums[i+1];
        }

        for(int i = 0; i < nums.length; i++){
            output[i] = leftplus[i] * rightplus[i];
        }
        
        return output;
    }
}
```