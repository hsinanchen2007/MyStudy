    
    class Solution {
        public boolean isMatch(String s, String p) {
            if(p.isEmpty()) {
                return s.isEmpty();
            }
            boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
            dp[0][0] = true;                           //p的前0个肯定能表示s串的前0个，这是平凡的
            for(int i = 1;i < p.length();i++) {        //初始化二维表格的第一行
                if(p.charAt(i) == '*') {               //二维表格的第一列不用初始化，全是false
                    dp[0][i + 1] = dp[0][i - 1];
                }
            }
            for(int i = 0;i < s.length();i++) {        //填写剩余的二维表格
                for(int j = 0;j < p.length();j++) {
                    if(j > 0 && p.charAt(j) == '*') {
                        if(p.charAt(j - 1) == s.charAt(i) || p.charAt(j - 1) == '.') {
                            dp[i + 1][j + 1] = dp[i + 1][j - 1] || dp[i][j + 1];
                        }else {
                            dp[i + 1][j + 1] = dp[i + 1][j - 1];
                        }
                    }else if(s.charAt(i) == p.charAt(j) || p.charAt(j) == '.') {
                        dp[i + 1][j + 1] = dp[i][j];
                    }
                }
            }
            return dp[s.length()][p.length()];
        }

    }