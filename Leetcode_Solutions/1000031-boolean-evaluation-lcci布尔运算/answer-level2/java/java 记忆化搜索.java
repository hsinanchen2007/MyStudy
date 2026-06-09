### 思路
设`dp[s][e][r]`为从索引`s`到索引`e`值为`r`的方案数。那么，我们可以拿一个指针`k`(从`s`遍历到`e - 1`)，将区间`[s, e]`分成两个部分，`[s, k]` 和 `[k + 2, e]`。其中`k+1`的位置是运算符。同时，由于是布尔运算，因此左右两部分的结果页要么是`0`，要么是`1`。组合也就是四种情况，`{00, 01, 10, 11}`。然后判断这四种情况通过`k+1`位置的运算符算出来的值是不是能够等于`r`(`dp[s][e][r]`中的`r`)。能等的话，就将左右两部分的方案数相乘即可。

```java
private char[] arr;
    private int[][][] dp;

    private int getBoolAns(int val1, int val2, char operator) {
        switch (operator) {
            case '&':
                return val1 & val2;
            case '|':
                return val1 | val2;
            case '^':
                return val1 ^ val2;
        }
        return val1 & val2;
    }

    /**
     * 返回从索引start到end值为result的不同括号方案的个数
     */
    private int rec(int start, int end, int result) {
        if (start == end) {
            return arr[start] - '0' == result ? 1 : 0;
        }

        if (dp[start][end][result] != -1) {
            return dp[start][end][result];
        }

        int ansCount = 0;
        for (int k = start; k < end; k+=2) {
            char operator = arr[k + 1];
            for (int i = 0; i <= 1; i++) {
                for (int j = 0; j <= 1; j++) {
                    if (getBoolAns(i, j, operator) == result) {
                        ansCount += rec(start, k, i) * rec(k + 2, end, j);
                    }
                }
            }
        }

        dp[start][end][result] = ansCount;
        return ansCount;
    }

    public int countEval(String s, int result) {
        arr = s.toCharArray();
        int len = arr.length;
        dp = new int[len][len][2];
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }
        return rec(0, len - 1, result);
    }
```

