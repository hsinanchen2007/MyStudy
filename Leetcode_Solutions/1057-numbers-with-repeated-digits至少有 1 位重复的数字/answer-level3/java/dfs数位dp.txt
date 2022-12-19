```
 private int[] tempNumDupDigitsAtMostN;
    private int[][] tempNumDupDigitsAtMostNDp;

    public int numDupDigitsAtMostN(int N) {
        tempNumDupDigitsAtMostN = new int[10];
        int temp = N + 1;
        int pos = 0;
        while (N != 0) {
            tempNumDupDigitsAtMostN[pos++] = N % 10;
            N /= 10;
        }
        tempNumDupDigitsAtMostNDp = new int[1 << 10][pos];
        for (int i = 0; i < tempNumDupDigitsAtMostNDp.length; i++) {
            Arrays.fill(tempNumDupDigitsAtMostNDp[i], -1);
        }
        return temp - dfs(pos - 1, 0, true);
    }

    private int dfs(int pos, int mask, boolean limit) {
        if (pos == -1) return 1;
        if (!limit && tempNumDupDigitsAtMostNDp[mask][pos] != -1) return tempNumDupDigitsAtMostNDp[mask][pos];
        int up = limit ? tempNumDupDigitsAtMostN[pos] : 9;
        int tmp = 0;
        for (int i = 0; i <= up; i++) {
            if (((1 << i) & mask) == 0) {
                if (i == 0 && mask == 0) {
                    tmp += dfs(pos - 1, mask, false);
                } else {
                    tmp += dfs(pos - 1, mask | (1 << i), limit && tempNumDupDigitsAtMostN[pos] == i);
                }
            }
        }
        if (!limit) tempNumDupDigitsAtMostNDp[mask][pos] = tmp;
        return tmp;
    }
```
