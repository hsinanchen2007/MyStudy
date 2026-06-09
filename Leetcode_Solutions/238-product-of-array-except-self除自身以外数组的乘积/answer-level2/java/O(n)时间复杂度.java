第一次遍历使用output数组存储，output[i]表示nums中i左侧位置乘积；
第二次遍历使用rightMulti存储i位置右侧的乘积
```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int len = nums.length;
        int[] outputs = new int[len];
        for (int i = 0; i < len; i++) {
          if (i == 0) {
            outputs[i] = 1;
          } else {
            outputs[i] = outputs[i - 1] * nums[i - 1];
          }
        }
        int rightMulti = 1;
        for (int i = len - 1; i >= 0; i--) {
          outputs[i] *= rightMulti;
          rightMulti *= nums[i];
        }
        return outputs;
    }
}
```