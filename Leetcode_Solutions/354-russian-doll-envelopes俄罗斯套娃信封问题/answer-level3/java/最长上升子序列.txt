```
class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        int len = envelopes.length;
        if (len == 0) {
            return 0;
        }
        // 按宽排序
        Arrays.sort(envelopes, new Comparator<int[]>() {
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });

        // dp[i] 表示第i个信封作为最外层信封时，套娃的个数
        int[] dp = new int[len];
        // 初始条件，每个信封的套娃是1
        Arrays.fill(dp, 1);

        int res = 1;
        // 遍历每个信封，把比自己小的信封且套娃个数最多的信封装进去
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i][1] > envelopes[j][1] && envelopes[i][0] > envelopes[j][0]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            res = Math.max(res, dp[i]);
        }
        return res;
    }
}
```
