class Solution {
    
	 public int maxProfit(int k, int[] prices) {
	        //回溯
	        //DP解法
            //dp方程：dp[i][j]=Math.max(dp[k][j],dp[k][j-1]+prices[i-1]-prices[k-1]);k>=0且小于i
         if(k>=prices.length) k=prices.length;
		 int[][] dp=new int[prices.length+1][k+1];//存放prices数组的前i个长度做了j次交易的最大值
	     int max=0;
         int cutone=0;
	     for(int i=0;i<dp.length;i++)
	    	 for(int j=0;j<dp[0].length;j++)
	    		 dp[i][j]=0;
		 for(int i=1;i<=k;i++)
			 for(int j=0;j<prices.length;j++) {
                 if(i==1)   dp[j+1][i]=cutone;
				 for(int m=0;m<j;m++) {
					 if(i==1) {
						 if(prices[j]>prices[m]&&dp[j+1][i]<prices[j]-prices[m]){
                             cutone=prices[j]-prices[m];
                             dp[j+1][i]=cutone;
                         }
							 
					 }
					 else {
						 if(prices[j]>prices[m]) {
							 int t=Math.max(dp[m+1][i-1]+prices[j]-prices[m],dp[m+1][i]);
							 if(dp[j+1][i]<t)
								 dp[j+1][i]=t;
						 }
						 else if(dp[j+1][i]<dp[m+1][i]) dp[j+1][i]=dp[m+1][i];
					 }
					 
				 }
			 }
		  int res=0;
		  for(int i=0;i<=k;i++)
             for(int j=0;j<dp.length;j++)
			  if(res<dp[j][i]) res=dp[j][i];
	      return res;
	    }
}