其实，每次我们在计算当前行的时候，只会用到下一行而已，再往下的就用不到了。所以每次用新的覆盖旧的就好了。
```
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int length = triangle.size();
        int[] dp = new int[length+1];
        for(int i=length-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[j] = Math.min(dp[j],dp[j+1])+triangle.get(i).get(j);
            }
        }
        return dp[0];
    }
}
```
