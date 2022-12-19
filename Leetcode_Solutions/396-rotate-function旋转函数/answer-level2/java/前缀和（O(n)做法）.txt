首先开两倍数组，然后将原数组加进去两边以巧妙解决循环问题，然后直接前缀和瞎搞，每次减去一波前缀和然后加上(n-1)*(当前数)即可。
```
class Solution {
    public int maxRotateFunction(int[] A) {
    	int n=A.length;
    	if(n==0) return 0;
        int[] B=new int[n*2];
        int[] sum=new int[n*2];
        for(int i=0;i<n;i++) {
        	B[i]=A[i];
        	B[n+i]=A[i];
        }
        sum[0]=B[0];
        for(int i=1;i<n*2;i++)
        	sum[i]=sum[i-1]+B[i];
        int nowSum=0,ans=Integer.MIN_VALUE;
        for(int i=0;i<n;i++)
        	nowSum+=B[i]*i;
        ans=Math.max(ans, nowSum);
        for(int i=n;i<2*n;i++) {
        	nowSum-=sum[i-1]-sum[i-n];
        	nowSum+=(n-1)*B[i];
        	ans=Math.max(ans, nowSum);
        }
        return ans;
    }
}
```
