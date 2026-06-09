假设一个数的某位是n（二进制数0或1），那么0^n=n，n^n=0，由此性质可得：设整数为x，0^x=x，x^x=0。题目为数组中只有一个数出现一次，其他的均出现两次，如果遍历数组做异或操作，当出现两次的数异或到自己时，相当于0异或剩余结果，最终的结果也就是出现一次的数。
```
class Solution {
    public int singleNumber(int[] nums) {
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            result = result^nums[i];
        }
        return result;
    }
}
```
