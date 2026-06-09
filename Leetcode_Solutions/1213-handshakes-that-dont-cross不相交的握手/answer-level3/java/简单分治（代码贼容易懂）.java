分治搞一搞啦，一个优化的地方是标记已经统计过的情况，避免重复遍历。
```
class Solution {
	
	private int[] dp;
	private int mod=1000000007;
	
    public int numberOfWays(int num_people) {
    	dp=new int[num_people+1];
    	for(int i=0;i<=num_people;i++)
    		dp[i]=-1;
    	dp[0]=dp[1]=0; dp[2]=1;
        return work(1,num_people);
    }
    
    private int work(int start,int end) {
    	if(start>=end) return 1;
    	if(dp[end-start+1]!=-1)
    		return dp[end-start+1];
    	
    	int ans=0;
    	
    	for(int i=start+1;i<=end;i++) {
    		if((i-start-1)%2==1 || (end-i)%2==1)
    			continue;
    		ans=(ans+(int)((long)work(start+1,i-1)*work(i+1,end)%mod))%mod;
    	}
    	return dp[end-start+1]=ans;
    }
}
```
