由题意容易看出是动态规划
关键是如何规划？转移方程是怎样的？
我们知道3+1=4（余1）3+5=8（余2），4+3=7（余1），观察知道
余数为0的数字+余数为0的数字余数为0
余数为0的数字+余数为1的数字余数为1
余数为0的数字+余数为2的数字余数为2

余数为1的数字+余数为0的数字余数为1
余数为1的数字+余数为1的数字余数为2
余数为1的数字+余数为2的数字余数为0

余数为2的数字+余数为0的数字余数为2
余数为2的数字+余数为1的数字余数为0
余数为2的数字+余数为2的数字余数为1

用max_0,1,2存着最大的这三种和。
并不断更新即可。

class Solution {
    public int maxSumDivThree(int[] nums) {
        //思路是从前到后动态规划
    
       if(nums.length==0){
           return 0;
       }
       int temp=0;
       int max_0=0;
       int max_1=0;
       int max_2=0;
       if(nums[0]%3==0){
         temp=nums[0];
        max_0=temp;
        }
        else if(nums[0]%3==1){
         temp=nums[0];
        max_1=temp;
        }
       else{
         temp=nums[0];
        max_2=temp;
        }
        for(int i=1;i<nums.length;i++){
           int temp_max0=max_0;
           int temp_max1=max_1;
           int temp_max2=max_2;
        if(nums[i]%3==0){
            temp=nums[i]+temp_max0;
            max_0=Math.max(temp,temp_max0);
            if(temp_max1!=0){
             temp=nums[i]+temp_max1;
            max_1=Math.max(temp,temp_max1);}
            if(temp_max2!=0){
             temp=nums[i]+temp_max2;
            max_2=Math.max(temp_max2,temp);
            }
        }
        else if(nums[i]%3==1){
             temp=nums[i]+temp_max0;
            max_1=Math.max(temp,temp_max1);
           
            if(temp_max2!=0){
                 
             temp=nums[i]+temp_max2;
            max_0=Math.max(temp,temp_max0);
            }
            if(temp_max1!=0){
            temp=nums[i]+temp_max1;
            
            max_2=Math.max(temp,temp_max2);
            }
        }
       else{
            temp=nums[i]+temp_max0;
            max_2=Math.max(temp,temp_max2);
            if(temp_max1!=0){
             temp=nums[i]+temp_max1;
            max_0=Math.max(temp,temp_max0);}
            if(temp_max2!=0){    
             temp=nums[i]+temp_max2;
            max_1=Math.max(temp,temp_max1);
            }
        }
        }
           return max_0;
    }
}