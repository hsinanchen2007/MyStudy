思路：由于题目中说了不存在某个字符串是另一个字符串的子串，那么当前的选择会增加的长度就仅和上一个选择的字符串相关，即增加的长度为当前选择字符串的长度减去和上一个选择的字符串的重叠的长度。因此我们每次的选择需要两个状态记录：
1. 历史选择，就是本次选择之前都选择了哪些字符串，用状态压缩，一个int的末n位(A的长度)表示即可
2. 上一次选择

因此我们需要二维DP，第一维表示状态，第二维表示上一次选择。每一次做选择我们都要判断重叠的长度，这部分工作可以提前做好，避免重复计算
因此总的时间复杂度为计算重叠的长度`O(n ^ 2 * W)`和记忆化递归的开销`O((2 ^ n) * n * n)`, 总的时间复杂度为`O((2^n + W) * n ^ 2)`.
```
// time complexity O(n ^ 2 * (2 ^ n + W))
class Solution {
    public String shortestSuperstring(String[] A) {
        int n = A.length;
        int[][] overlaps = new int[n][n];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j  < n ; j++){
                if(i == j){
                    continue;
                }
                int m = Math.min(A[i].length(), A[j].length());
                for(int k = m ; k >= 0 ; k--){
                    if(A[i].endsWith(A[j].substring(0, k))){
                        overlaps[i][j] = k;
                        break;
                    }
                }
            }
        }
        String[][] dp = new String[1 << n][n];
        String res = null;
        for(int i = 0 ; i < n ; i++){
            int status = 1 << i;
            String s = A[i] + dfs(A, dp, overlaps, status, i);
            if(res == null || res.length() > s.length()){
                res = s;
            }
        }
        return res;
    }

    private String dfs(String[] A, String[][] dp, int[][] overlaps, int status, int pre){
        int n = A.length;
        if(status == (1 << n) - 1){
            return "";
        }
        if(dp[status][pre] != null){
            return dp[status][pre];
        }
        String res = null;
        for(int i = 0 ; i < n ; i++){
            if((status & (1 << i)) == 0){
                int newStatus = status | (1 << i);
                String s = A[i].substring(overlaps[pre][i]) + dfs(A, dp, overlaps, newStatus, i);
                if(res == null || res.length() > s.length()){
                    res = s;
                }
            }
        }
        dp[status][pre] = res;
        return res;
    }
}
```