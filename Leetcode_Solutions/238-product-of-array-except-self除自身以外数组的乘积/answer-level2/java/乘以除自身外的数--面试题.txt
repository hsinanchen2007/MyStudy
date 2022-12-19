### 解题思路
1. 面试题，不让用除法，时间复杂度为On
2. 利用输出数组，首先计算当前位左侧的数的乘积，用数组来保存，res[i] = res[i-1] * nums[i-1], res[0]=1.
3. 然后在得到的数组的基础上，再依次乘以当前位右侧的数的乘积，用一个变量存储。res[i] \*= k,k=\*nums[i];

### 代码

```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] res = new int[nums.length];
        res[0] = 1;
        for(int i = 1; i < res.length; i++)
            res[i] = res[i-1] * nums[i-1];
        
        int k = 1;
        for(int i = res.length-1; i >= 0; i--){
            res[i] *= k;
            k *= nums[i];
        }
        return res;
    }
}
```