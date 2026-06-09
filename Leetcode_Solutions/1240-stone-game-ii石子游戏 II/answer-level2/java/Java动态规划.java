重点在于“两者都发挥最佳水平”，可以定义一个递归方法findMaxStones：对于一定堆数的石子和某一M值，找出最多可以拿到的石子数。
对于某一次轮到Alex拿石子，他先取 1 <= X <= 2M 堆石子。假设Alex取X堆石子，那么对于剩下的石子，Lee也想拿到数量最多的石子，所以对剩下的石子同样用findMaxStone求出最多可以拿到的石子数。那么，每个X均对应一个"Lee最多可以拿到的石子数"，只要找到某一X，使得Lee的石子数最少，这时Alex的石子数最大。
- 为了不重复对piles求和，设置后缀和数组suffixSum；
- 递归过程中存在很多重复计算（相同的i，M），设置二维数组记录结果，即带备忘录、自顶向下的动态规划。
```
    public int stoneGameII(int[] piles) {
        if(piles == null || piles.length == 0)
            return 0;
        int n = piles.length;
        suffixSum = new int[n];
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        dp = new int[n][n];
        return findMaxStones(piles, 0, 1);
    }
    private int[] suffixSum;
    private int[][] dp;
    private int findMaxStones(int[] piles, int i, int M){
        if(i == piles.length)
            return 0;
        if(i + 2 * M >= piles.length){
            return suffixSum[i];
        }
        if(dp[i][M] != 0)
            return dp[i][M];
        int minStones = Integer.MAX_VALUE;
        for (int X = 1; X <= 2 * M; X++){
            minStones = Math.min(minStones, findMaxStones(piles, i + X, Math.max(X, M)));   //找出对手可以获得的最小石子数
        }
        dp[i][M] = suffixSum[i] - minStones;
        return dp[i][M];
    }
```
