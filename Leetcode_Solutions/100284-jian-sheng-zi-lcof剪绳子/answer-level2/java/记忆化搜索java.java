```
class Solution {
    public int[] memo;
    public int cuttingRope(int n) {
		memo = new int[n+1];
        return dfs(n);
	}
      public int dfs(int n) {
		 if(n == 1)
			 return 1;
		 if(memo[n] != 0) {
			 return memo[n];
		 }
		 int res = Integer.MIN_VALUE;
		 for(int i = 1; i <= n-1 ; i++) {
			 res = Math.max(res, Math.max(dfs(n-i)*i,(n-i)*i));
		 }
		 memo[n] =res;
		 return res;
	}

}
```
