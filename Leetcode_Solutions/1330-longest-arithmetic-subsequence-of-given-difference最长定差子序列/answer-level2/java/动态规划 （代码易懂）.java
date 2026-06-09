思路：
我们设dp[i]表示当前序列最后一个数是i的最大子序列长度
递推方程很简单：dp[i]=max(dp[i],dp[i-difference]+1);
因为i可能是负数，因此我们将每个数加10000，保证所有数非负即可！
```
class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        int[] dp=new int[20005];
        for(int i=0;i<arr.length;i++)
        	arr[i]+=10000;
        int ans=0;
        for(int i=0;i<arr.length;i++)
        {
        	int sum=arr[i]-difference;
        	if(sum<0 || sum>20000) 
        		dp[arr[i]]=1;
        	else 
        		dp[arr[i]]=Math.max(dp[arr[i]],dp[sum]+1);
        	ans=Math.max(ans, dp[arr[i]]);
        }
        return ans;
    }
}
```

