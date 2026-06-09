```
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] dp = new int[n+1];
        for(int i=0;i<triangle.get(n-1).size();i++){
            dp[i] = triangle.get(n-1).get(i);
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle.get(i).size();j++){
                dp[j] = Math.min(triangle.get(i).get(j)+dp[j],triangle.get(i).get(j)+dp[j+1]);
            }
        }
        return dp[0];
    }
}
```
