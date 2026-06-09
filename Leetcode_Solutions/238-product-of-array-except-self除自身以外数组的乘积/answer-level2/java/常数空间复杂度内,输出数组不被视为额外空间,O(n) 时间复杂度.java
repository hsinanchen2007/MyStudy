class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] sum=new int[nums.length];
        int t=1;
        for(int i=0;i<nums.length;i++){
            sum[i]=t;
            t*=nums[i];
        }
        t=1;
        for(int j=(sum.length-1);j>=0;j--){
            sum[j]*=t;
            t*=nums[j];
        }
        return sum;
    }
}![1.JPG](https://pic.leetcode-cn.com/9a69a3138da40fe9dc651991d9279d6363cc04e1293038f59cbc2eaffe0c8889-1.JPG)
