### 解题思路
L -- > 使用输出列表保存
R -- > 使用变量保存
L*R 即为输出的列表

### 代码

```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        //使用左右两个数组
        int[] output = new int[nums.length];
        
        //两次乘积
        //左边小于当前数的乘积 L
        //右边大于当前数的乘积 R

        //初始化
        output[0] = 1;

        //左边小于当前数的乘积 L
        for (int i = 1; i < nums.length; i++) {
            output[i] = nums[i-1]*output[i-1];
            //debug
            //System.out.println(output[i]);
        }

        

        //有边大于当前数的乘积 R
        //有个变量记录R的乘积值
        int R = 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            output[i] = output[i]*R;
            //R增加当前值
            R = nums[i]*R;
        }

        return output;
    }
}
```