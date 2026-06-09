二维数组的DP,
代表对于当前i, 如果其等差数列前值是j这个下标这时候最大等差数列长度
最先一个n ^ 3的方法遍历
通过Map可以存每个值对应的下标list，就优化了很多runtime

```
class Solution {
    public int longestArithSeqLength(int[] A) {
        int n = A.length;
        // corner case
        if (n == 2) {
            return 2;
        }

        int m = Arrays.stream(A).max().getAsInt() - Arrays.stream(A).min().getAsInt();

        if (m == 0) return n;
        int[][] dp = new int[n][n];

        dp[0][0] = 1;

        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            List<Integer> list = map.getOrDefault(A[i], new ArrayList<>());
            list.add(i);
            map.put(A[i], list);
        }

        for (int i = 1; i < n; i++) {
            dp[i][i] = 1;
            for (int j = 0; j < i; j++) {
                dp[i][j] = Math.max(dp[i][j], 2);
                int val = 2 * A[j] - A[i];
                for (int k : map.getOrDefault(val, Collections.emptyList()))
                {
                    
                    dp[i][j] = Math.max(dp[i][j], dp[j][k] + 1);
                    
                }

                
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = Math.max(res, Arrays.stream(dp[i]).max().getAsInt());
        }
        return res;
    }
}
```
