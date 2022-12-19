#  解法主要有2步： 1.找到自然数数组中的最大值，2.异或得到缺失的那个数；两个相同的数异或等于0，0与任何数异或都等于那个数

```
class Solution {
    public int missingNumber(int[] nums) {
       
        Arrays.sort(nums);
        int n = nums[nums.length-1];
        if(n < nums.length){//特殊情况，缺失的就是最后一个数
            return n+1;
        }
        int res = 0;
        for(int i = 1; i<=n; i++){
            res ^=i;
        }
        for(int i = 0; i< nums.length; i++){
            res ^=nums[i];
        }
        return res;
    }
}
```

