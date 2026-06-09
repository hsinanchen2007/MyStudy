相比较于打家劫舍1变化的是首尾之间的内部关系，所以只需分情况讨论，可以偷第一家,这时一定不能偷最后一家和不能偷第一家，可以偷最后一家的情况
```java
class Solution {

    public int rob(int[] nums) {
        if(nums.length==0)  return 0;
        if(nums.length==1)  return nums[0];
        if(nums.length==2)  return Math.max(nums[0],nums[1]);
        int[] dp1=new int[nums.length-1];
        int[] dp2=new int[nums.length];
           //偷第一家和不偷第一家
        //1.可以偷第一家
         for(int i=0;i<nums.length-1;i++)
         {
             if(i<2)
             {
             dp1[0]=nums[0];
             dp1[1]=Math.max(dp1[0],nums[1]);
             }
             else
             {
                 dp1[i]=Math.max(dp1[i-1],dp1[i-2]+nums[i]);
             }             
         }
        //2.不偷第一家，可以偷最后一家
        for(int i=1;i<nums.length;i++)
        {
            if(i<3)
            {
             dp2[1]=nums[1];
             dp2[2]=Math.max(dp2[1],nums[2]);
            }
             else
             {
                 dp2[i]=Math.max(dp2[i-1],dp2[i-2]+nums[i]);
             }             
        }
        return Math.max(dp1[dp1.length-1],dp2[dp2.length-1]);
    }
}