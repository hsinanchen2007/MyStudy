
int maxSubArray(int* nums, int numsSize){

    int i = 0;
    int sum=nums[0];
    int summax = nums[0];
    for(i = 1; i < numsSize;i++)
    {
       if((nums[i]>sum)&&(sum<0)) {
           sum = nums[i];
       }
        else{
            sum+=nums[i];
        }
       // printf("sum=%d,nums[i]=%d\n",sum,nums[i]);
        if(summax < sum){
            summax=sum;
        }
    }
    
    return summax;
}


如上代码
执行用时 :4 ms, 在所有 C 提交中击败了99.20%的用户
内存消耗 :7.6 MB, 在所有 C 提交中击败了81.98%
的用户

