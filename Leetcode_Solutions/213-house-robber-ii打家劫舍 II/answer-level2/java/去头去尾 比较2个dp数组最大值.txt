由于头尾不能同时出现 那么问题可以化归为：
1.不包括第一个
2.包括第一个
假设长度为len的数组
第一种情况对应从0到len-2的dp数组
第二种情况对应从1到len-1的数组
两种一比较 即得到最后结果 相比其他具体判断方法 逻辑更为清晰
```
class Solution {
    public int rob(int[] nums) {
        int len = nums.length;
        if(len == 0)
            return 0;
        if(len == 1)
            return nums[0];
        int[] dp1 = new int[len];
        dp1[0] = 0;
        dp1[1] = nums[0];
        int[] dp2 = new int[len];
        dp2[0] = 0;
        dp2[1] = nums[1];
        for(int i = 2;i < len;i++){
            dp1[i] = Integer.max(dp1[i-1],nums[i-1]+dp1[i-2]);
            dp2[i] = Integer.max(dp2[i-1],nums[i]+dp2[i-2]);
        }
        return Integer.max(dp1[len-1],dp2[len-1]);
    }
}

```

