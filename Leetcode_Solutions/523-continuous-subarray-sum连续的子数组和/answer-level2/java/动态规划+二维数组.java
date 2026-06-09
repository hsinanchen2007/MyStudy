使用动态规划，必须要有状态转移方程
构造一个二维整数数组dp[nums.length-1][nums.length-1]
nums={23,2,6,4,7}
dp[0][0]=23+2;
dp[1][0]=23+2+6,dp[1][1]=2+6;
dp[2][0]=23+2+6+4,dp[2][1]=2+6+4,dp[2][2]=6+4;
dp[3][0]=23+2+6+4+7,dp[3][1]=2+6+4+7,dp[3][2]=6+4+7,dp[3][3]=4+7;
首先将dp[0][0]=nums[0]+nums[1]加入数组。
对于dp[i][j]:
     1.i>j,dp[i][j]=dp[i-1][j]+nums[i+1];
     2.i=j,dp[i][j]=nums[i]+nums[i+1];
只要存在dp[i][j]%k==0,即返回true;
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        if(nums.length<=1){
            return false;
        }else{
            if(k==0){
                int len=nums.length-1;
                int[][] dp=new int[len][len];
                dp[0][0]=nums[0]+nums[1];
                if(dp[0][0]==0){
                    return true;
                }
                for(int i=0;i<len;i++){
                    for(int j=0;j<=i;j++){
                        if(i!=j){
                            dp[i][j]=dp[i-1][j]+nums[i+1];                   
                        }else{
                            dp[i][j]=nums[i]+nums[i+1]; 
                        }
                        if(dp[i][j]==0){
                            return true;
                        }
                    }            
                }
                return false;
            }else{
                int len=nums.length-1;
                int[][] dp=new int[len][len];
                dp[0][0]=nums[0]+nums[1];
                if(dp[0][0]%k==0){
                    return true;
                }
                for(int i=0;i<len;i++){
                    for(int j=0;j<=i;j++){
                        if(i!=j){
                            dp[i][j]=dp[i-1][j]+nums[i+1];                   
                        }else{
                            dp[i][j]=nums[i]+nums[i+1]; 
                        }
                        if(dp[i][j]%k==0){
                            return true;
                        }
                    }            
                }
                return false;
            }
        }  
    }
}