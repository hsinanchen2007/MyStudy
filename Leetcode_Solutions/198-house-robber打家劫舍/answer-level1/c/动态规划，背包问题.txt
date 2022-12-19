```
#define max(x,y) x>y?x:y
int rob(int* nums, int numsSize){
    if(numsSize==0)return 0;
    int dp[1000]={0};
    dp[0]=nums[0];
    
    for(int i=1;i<numsSize;i++){
        if(i==1)dp[1]=max(nums[0],nums[1]);           
        else dp[i]=max((dp[i-2]+nums[i]),(dp[i-1]));
    }
    return dp[numsSize-1];
}
```
