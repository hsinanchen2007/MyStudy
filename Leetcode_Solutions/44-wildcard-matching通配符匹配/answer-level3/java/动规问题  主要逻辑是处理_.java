```
public boolean isMatch(String s, String p) {
        if (s.length() == 0 || p.length() == 0) {
            return p.replace("*", "").equals(s);
        }
        //表示 dp[i][j] 表示p第i个 和s第j个之前的子串匹配结果2
        boolean dp[][] = new boolean[p.length() + 1][s.length() + 1];
        //表示两个为空的情况
        dp[0][0] = true;

        for (int i = 1; i < p.length() + 1; i++) {
            //处理* 找到第一个true 然后往下全设为true
            if (p.charAt(i - 1) == '*') {
                for (int k = 0; k < s.length() + 1; k++) {
                    dp[i][k] = dp[i - 1][k];
                    if (dp[i][k] == true) {
                        while (k < s.length() + 1) {
                            dp[i][k] = true;
                            k++;
                        }
                    }
                }

            }
            //不是*时候单个匹配
            for (int j = 1; j < s.length() + 1; j++) {
                //前一个记录不匹配 跳过
                boolean pre = dp[i - 1][j - 1];
                if (!pre) continue;
                if (p.charAt(i - 1) == '?' || s.charAt(j - 1) == p.charAt(i - 1)) {
                    dp[i][j] = true;
                }

            }

        }

        return dp[p.length()][s.length()];
    }
```
