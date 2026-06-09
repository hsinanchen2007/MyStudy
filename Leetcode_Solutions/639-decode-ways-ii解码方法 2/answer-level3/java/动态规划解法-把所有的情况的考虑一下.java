动态规划，每种情况，不要漏了就可以了，体力劳动。

```
public int numDecodings(String s) {
        int m = 1000000007;
        
        char[] array = s.toCharArray();
        int len = array.length;
        
        long[] dp = new long[len + 1];
        dp[0] = 1;
        
        for(int i = 1; i <= len; i++) {
            if (i == 1) {
                if (array[i-1] == '0') {
                    dp[i] = 0;
                } else if (array[i-1] == '*') {
                    dp[i] = 9;
                } else {
                    dp[i] = 1;
                }
            } else {
                if (array[i-1] == '*') {
                    dp[i] = (9 * dp[i-1]);
                    if (array[i-2] == '*') {
                        dp[i] += (15 * dp[i-2]);
                    } else if (array[i-2] == '1') {
                        dp[i] += (9 * dp[i-2]);
                    } else if (array[i-2] == '2') {
                        dp[i] += (6 * dp[i-2]);
                    }
                } else if (array[i-1] == '0') {
                    if (array[i-2] == '*') {
                        dp[i] += (2 * dp[i-2]);
                    } else if (array[i-2] == '1' || array[i-2] == '2') {
                        dp[i] += dp[i-2];
                    }
                } else if (array[i-1] <= '6') {
                    dp[i] = dp[i-1];
                    if (array[i-2] == '*') {
                        dp[i] += (2 * dp[i-2]);
                    } else if (array[i-2] == '1' || array[i-2] == '2') {
                        dp[i] += dp[i-2];
                    }
                } else if (array[i-1] > '6') {
                    dp[i] = dp[i-1];
                    if (array[i-2] == '*' || array[i-2] == '1') {
                        dp[i] += dp[i-2];
                    }
                }
            }
            
            dp[i] %= m;
        }
        return (int)dp[len];
    }
```
