```
 private int[] tempCountDigitOne;
    private int[] tempCountDigitOneDp;

    public int countDigitOne(int n) {
        tempCountDigitOne = new int[String.valueOf(Integer.MAX_VALUE).length()];
        tempCountDigitOneDp = new int[String.valueOf(Integer.MAX_VALUE).length()];
        Arrays.fill(tempCountDigitOneDp, -1);
        return solve(n);
    }

    private int solve(int n) {
        int pos = 0;
        while (n != 0) {
            tempCountDigitOne[pos++] = n % 10;
            n /= 10;
        }
        return dfs2(pos - 1, true);
    }

    private int dfs2(int pos, boolean limit) {
        if (pos == -1) return 0;
        if (!limit && tempCountDigitOneDp[pos] != -1) return tempCountDigitOneDp[pos];
        int up = limit ? tempCountDigitOne[pos] : 9;
        int tmp = 0;
        for (int i = 0; i <= up; i++) {
            if (i == 1) {
                int temp = 0;
                if (limit && tempCountDigitOne[pos] == i) {
                    for (int j = pos - 1; j >= 0; j--) {
                        temp = temp * 10 + tempCountDigitOne[j];
                    }
                    tmp += temp + 1;
                } else {
                    tmp += Math.pow(10, pos);
                }
            }
            tmp += dfs2(pos - 1, limit && tempCountDigitOne[pos] == i);
        }
        if (!limit) tempCountDigitOneDp[pos] = tmp;
        return tmp;
    }
```
