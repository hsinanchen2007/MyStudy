```
    private int[][] stoneGameIIDp;
    public int stoneGameII(int[] piles) {
        int[] sum = new int[piles.length];
        stoneGameIIDp = new int[piles.length][101];
        for (int i = 0; i < stoneGameIIDp.length; i++) {
            Arrays.fill(stoneGameIIDp[i], -1);
        }
        sum[sum.length - 1] = piles[piles.length - 1];
        for (int i = sum.length - 2; i >= 0; i--) {
            sum[i] = sum[i + 1] + piles[i];
        }
        return getStoneGameIIResult(sum, piles, 0, 1);
    }
    private int getStoneGameIIResult(int[] sum, int[] piles, int x, int M) {
        if (x > piles.length - 1) return 0;
        if (x == piles.length - 1) return piles[piles.length - 1];
        if (stoneGameIIDp[x][M] != -1) return stoneGameIIDp[x][M];
        int res = 0;
        for (int i = 1; i <= 2 * M && i + x <= piles.length; i++) {
            res = Math.max(res, sum[x] - getStoneGameIIResult(sum, piles, i + x, Math.max(i, M)));
        }
        stoneGameIIDp[x][M] = res;
        return res;
    }
```
