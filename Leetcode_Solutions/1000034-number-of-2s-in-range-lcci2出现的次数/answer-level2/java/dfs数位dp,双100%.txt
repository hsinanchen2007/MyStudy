```
private int[] tempA;
    private int[] temptempDp;

    public int numberOf2sInRange(int n) {
        tempA = new int[10];
        temptempDp = new int[10];
        Arrays.fill(temptempDp, -1);
        int pos = 0;
        while (n != 0) {
            tempA[pos++] = n % 10;
            n /= 10;
        }
        return dfs(pos - 1, true);
    }

    private int dfs(int pos, boolean limit) {
        if (pos == -1) return 0;
        if (!limit && temptempDp[pos] != -1) return temptempDp[pos];
        int up = limit ? tempA[pos] : 9;
        int tmp = 0;
        for (int i = 0; i <= up; i++) {
            if (i == 2) {
                int temptemp = 0;
                if (limit && i == tempA[pos]) {
                    for (int j = pos - 1; j >= 0; j--) {
                        temptemp = temptemp * 10 + tempA[j];
                    }
                    tmp += temptemp + 1;
                } else {
                    tmp += Math.pow(10, pos);
                }
            }
            tmp += dfs(pos - 1, limit && i == tempA[pos]);
        }
        if (!limit) temptempDp[pos] = tmp;
        return tmp;
    }
```
