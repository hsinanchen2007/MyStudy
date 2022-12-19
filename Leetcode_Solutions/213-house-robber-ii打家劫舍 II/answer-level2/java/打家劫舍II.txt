这道题递推方程与打家劫舍那道相同，不同的地方有:
数组第一个数和最后一个数不可能同时取，则有三种情况：
取首不取尾，取尾不取首、都不取
这三种情况可归并为不取首或不取尾
所以，可以分别踢去首和尾，分别计算结果，最后取最大值
# 代码
```java []
class Solution {
    public int rob(int[] nums) {
        if(nums.length==0) return 0;
        if(nums.length==1) return nums[0];
        if(nums.length==2) return Math.max(nums[0],nums[1]);
        int result1=0,result2=0;
        int pre=0, cur=nums[0];
        for(int i=1;i<nums.length-1;i++){
            result1=Math.max(pre+nums[i],cur);
            pre=cur;cur=result1;
        }
        pre=0;cur=nums[1];
        for(int i=2;i<nums.length;i++){
            result2=Math.max(pre+nums[i],cur);
            pre=cur;cur=result2;
        }
        return Math.max(result1,result2);
    }
}
```