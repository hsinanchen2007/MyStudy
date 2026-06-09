```最直接的动态规划，不掺杂任何优化
public  int minimumTotal(List<List<Integer>> triangle) {
		 int n = triangle.size();
		 int[][] dp = new int[n][n];
		 int rows = 0;
		 int min=Integer.MAX_VALUE;
		 for(List<Integer> l:triangle){
			 for(int i=0;i<l.size();i++){
				 if(l.size()==1){
					 dp[rows][0] = l.get(i);
				 }else{
					 if(i==0){
						 dp[rows][i] = l.get(i)+dp[rows-1][i];
					 }else if(i==l.size()-1){
						 dp[rows][i] = l.get(i)+dp[rows-1][i-1];
					 }else{
						 dp[rows][i] = Math.min(l.get(i)+dp[rows-1][i-1], l.get(i)+dp[rows-1][i]);
					 }
				 }
			 }
			 rows++;
		 }
		 for(int i=0;i<dp[0].length;i++){
			 min = Math.min(dp[n-1][i], min);
		 }
		 return min;
	 }
```
