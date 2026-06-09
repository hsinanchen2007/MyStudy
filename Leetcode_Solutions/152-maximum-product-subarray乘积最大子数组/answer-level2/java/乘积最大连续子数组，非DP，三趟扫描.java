### 解题思路
    考虑一个没有0的数组，先求nums[i]= nums[0]*...*nums[i]，其代表以原nums[i]结尾的连续子数组乘积的最大值。若nums[i]为正就是最后结果，为负的话则必然存在奇数个负因子，必须去掉离其最远的负因子（这样不但会使nums[i]由负变正，还会留下最长的连乘序列，序列中每个因子的绝对值都不小于1以确保连乘结果最大），这样再求出数组中的最大值就可以了。
    那么如果数组中有0该怎么办呢，只需将数组以0分段分别处理就可以了。
    第一趟扫描，nums[i]为原数组中nums[index+1]*...*nums[i], index为i左侧离i最近的0元素的索引
    第二趟扫描，确定以0为间隔的每段第一个负值negative，并将每段中其他负值除以该段对应的negative
    第三趟扫描，求最大
    eg：nums：-2 -3 -4 2 0 -6 -1 4 -2
        for_1:-2 6 -24 -48 0 -6 6 24 -48
        for_2:-2 6  12  24 0 -6 6 24 8
        for_3: max = 24

### 代码

```java
class Solution {
    public int maxProduct(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        for(int i = 1; i < nums.length; i++){
            if(nums[i-1] != 0)
                nums[i] *= nums[i-1]; 
        }
        int negative = 1;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] < 0){
                if(negative > 0)
                    negative = nums[i];
                else
                    nums[i] /= negative;
            }
            if(nums[i] == 0)
                negative = 1;
        }
        int maxProduct = nums[0];
        for(int i = 0; i < nums.length; i++)
            if(nums[i] > maxProduct)
                maxProduct = nums[i];
        return maxProduct;
    }
}
```