class Solution {
    public int maxSubArray(int[] nums) {
        int max=nums[0];
        int sum=0;
        int x;
        if(nums.length==1){
            return nums[0]; //如果数组只有一个数，则该数为最大和
        }
        for(int i=0;i<nums.length;i++){       //对数组进行遍历，算出最大序列和
            sum=sum+nums[i];
            if(sum>max){
                max=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        for(int i=0;i<nums.length;i++){  //再对数组进行遍历，判断数组性质
            if(nums[i]>=0){ //如果数组中有正数，则前面一个循环计算的结果是正确的
                break;
            }else{
                if(nums[i]>max) max=nums[i];//如果全部为负数的话，则最大子序列的和为几个负数中最大的一个
            }
        }
        return max;
    }
}
**初次接触算法，希望能记录下自己的成长之路**