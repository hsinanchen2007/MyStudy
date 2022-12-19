```java
class Solution {
    int[][] dp = new int[100][142];
    public int superEggDrop(int K, int N) {
        if(K == 1) return N;
        ojbk();
        int pivot = 0;
        int res = 0;
        for (int i = 0; i < 142; i++) {
            pivot += dp[K-1][i];
            if (pivot >= N) {
                res = i+1;
                break;
            } 
        }
        return res;
    }
    
    private void ojbk() {
        for(int i = 0; i < 100; i++) {
            dp[i][0] = 1;
        }
        for(int i = 1; i < 142; i ++) {
            dp[0][i] = 1;
        }
        for(int i = 1; i < 100; i ++) {
            for (int j = 1; j < 142; j ++) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
            }
        }
    }
}