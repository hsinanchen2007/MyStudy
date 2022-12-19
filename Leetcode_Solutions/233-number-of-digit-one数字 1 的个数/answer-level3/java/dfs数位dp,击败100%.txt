```
private int[] tempCountDigitOneTemp;
    private int[] tempCountDigitOneTempDp;

    public int countDigitOne(int n) {
        tempCountDigitOneTemp = new int[15];
        tempCountDigitOneTempDp = new int[15];
        int pos = 0;
        while (n != 0) {
            tempCountDigitOneTemp[pos++] = n % 10;
            n /= 10;
        }
        Arrays.fill(tempCountDigitOneTempDp, -1);
        return dfs3(pos - 1, true);
    }

    private int dfs3(int pos, boolean limit) {
        if (pos == -1) return 0;
        if (!limit && tempCountDigitOneTempDp[pos] != -1) return tempCountDigitOneTempDp[pos];
        int up = limit ? tempCountDigitOneTemp[pos] : 9;
        int tmp = 0;
        for (int i = 0; i <= up; i++) {
            if (i == 1) {
                if (limit && tempCountDigitOneTemp[pos] == i) {
                    int temp = 0;
                    for (int j = pos - 1; j >= 0; j--) {
                         temp = temp * 10 + tempCountDigitOneTemp[j];
                    }
                    tmp += temp + 1;
                } else {
                    tmp += Math.pow(10, pos);
                }
            }
            tmp += dfs3(pos - 1, limit && tempCountDigitOneTemp[pos] == i);
        }
        if (!limit) tempCountDigitOneTempDp[pos] = tmp;
        return tmp;
    }
```
