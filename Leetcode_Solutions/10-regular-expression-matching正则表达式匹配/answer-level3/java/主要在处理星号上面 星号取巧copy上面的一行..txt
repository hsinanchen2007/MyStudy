 public boolean isMatch(String s, String p) {
        if (s == null || p == null) {
            return s == p;
        }

        boolean[][] dp = new boolean[p.length() + 1][s.length() + 1];
        //""==""
        //dp[i][j]=true 代表长度0-i的p和长度0-j的s匹配
        dp[0][0] = true;

        for (int i = 0; i <p.length(); i++) {
            if (p.charAt(i) == '*') {
                for (int j = 0; j < dp[i].length; j++) {
                    dp[i+1][j]=dp[i][j];
                }
              continue;
            }
            //*
            else if (i + 1 < p.length() && p.charAt(i + 1) == '*') {
                for (int j = 0; j < dp[i].length; j++) {
                    dp[i+1][j]=dp[i][j];
                }
                for (int j = 0; j < dp[i].length - 1; j++) {
                    if (dp[i][j]) {
                        while (j < dp[i].length - 1) {
                            if (p.charAt(i) == '.' || p.charAt(i) == s.charAt(j)) {
                                dp[i + 1][j + 1] = true;
                            } else {
                                break;
                            }
                            j++;
                        }
                    }
                }

            } else {
                for (int j = 0; j < dp[i].length - 1; j++) {
                    if (dp[i][j]) {

                        if (j < dp[i].length - 1) {
                            if (p.charAt(i) == '.' || p.charAt(i) == s.charAt(j)) {
                                dp[i + 1][j + 1] = true;
                            }
                        }
                    }

                }
            }
        }
        return dp[p.length()][s.length()];
    }