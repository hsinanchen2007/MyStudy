执行用时 :116 ms, 在所有 java 提交中击败了91.69% 的用户
内存消耗 :248.4 MB, 在所有 java 提交中击败了100.00%的用户
```
class Solution {
    public int longestArithSeqLength(int[] A) {
        if(A == null || A.length < 3)
            return 0;
        int[][] dp = new int[A.length][20001];
        int max = 0;
        for(int i = 1; i < A.length; i++){
            for(int j = 0; j < i; j++){
                int distance = A[i] - A[j] + 10000;
                if(dp[j][distance] > 0){
                    dp[i][distance] = (dp[i][distance] > dp[j][distance]+1) ? dp[i][distance] : dp[j][distance]+1;
                }
                else{
                    dp[i][distance] = 2;
                }
                max = max > dp[i][distance] ? max : dp[i][distance];
            }
        }
        return max;
    }
}
```
