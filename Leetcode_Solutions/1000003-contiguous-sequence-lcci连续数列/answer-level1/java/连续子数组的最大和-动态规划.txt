```
class Solution {
    public int maxSubArray(int[] nums) {
       /*
       这道题是剑指offer的 面试题31，参考书本上的解法
       方法一:  利用数组的特点
       如果总和是负数的话，与任何数相加都是减小的

       方法二： 使用动态规划
       使用函数 f(i)表示第i个数字结尾的子数组的最大和
       求 max(f(i))

        如果 f(i-1)>0   f(i)=f(i-1)+nums[i]
        如果 f(i-1)<0   f(i)=nums(i)

        编码与以下代码一致   f(i)对应的变量是 sum,而 max(f(i))对应的是max

       */

       final int ERROR=-999;
       if(nums.length<0|| nums==null){
           return -ERROR;
       }
       int sum=nums[0];
       int max=sum;
       int len=nums.length;

       for(int i=1;i<len;i++){
           if(sum>0){
               sum+=nums[i];
           }else{
               sum=nums[i];
           }
           max=max>sum?max:sum;
       }
        return max;

    }
}
```
