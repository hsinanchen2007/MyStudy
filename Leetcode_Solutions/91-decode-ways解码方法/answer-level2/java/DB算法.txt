  if (s.startsWith("0")) {
            return 0;
        }
        int[] dp = new int[s.length()];
        dp[0] = 1;
        for (int index = 1; index < s.length(); index++) {
            if ('0' != s.charAt(index)) {
                dp[index] += dp[index - 1];
            }
            if (!s.substring(index - 1, index + 1).startsWith("0") && (Integer.valueOf(s.substring(index - 1, index + 1)) <= 26)) {
                dp[index] += index >= 2 ? dp[index - 2] : 1;
            }
        }
        return dp[s.length() - 1];