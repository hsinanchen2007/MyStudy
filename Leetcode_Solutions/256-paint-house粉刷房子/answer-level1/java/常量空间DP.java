```
    public int minCost(int[][] costs) {
        if (costs == null || costs.length == 0) {
            return 0;
        }
        int dp0 = costs[0][0];
        int dp1 = costs[0][1];
        int dp2 = costs[0][2];

        for (int i = 1; i < costs.length; i++) {

            int t1 = Math.min(dp1, dp2) + costs[i][0];
            int t2 = Math.min(dp0, dp2) + costs[i][1];
            int t3 = Math.min(dp0, dp1) + costs[i][2];
            dp0 = t1;
            dp1 = t2;
            dp2 = t3;

        }

        return Math.min(Math.min(dp0, dp1), dp2);

    }
```
