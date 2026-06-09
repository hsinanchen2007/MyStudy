```
class Solution {
    public int subarrayBitwiseORs(int[] A) {
        
        Set<Integer> set=new HashSet<>();
        int len=A.length;
        int[][] dp=new int[len][len];
        for(int i=0;i<len;i++){
            dp[0][i]=A[i];
            set.add(dp[0][i]);
        }
        for(int i=1;i<len;i++){
            for(int j=0;j<len-i;j++){
                dp[i][j]=dp[i-1][j]|dp[i-1][j+1];
                set.add(dp[i][j]);
            }
        }
        return set.size();
    }
}
```
