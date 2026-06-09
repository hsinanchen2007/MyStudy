```
public int numDecodings(String s) {
        //dp[n]:前n个字符组成的字符串的编码方法总数
        int[] dp = new int[s.length() + 1];
        //初始化
        dp[0] = 1;
        dp[1] = s.charAt(0) != '0' ? 1 : 0;
        //迭代
        for (int i = 2; i < s.length() + 1; i++) {
            dp[i] = (isDoubleDigitValid(s, i - 2) ? dp[i - 2] : 0)
                    + (isSingleDigitValid(s, i - 1) ? dp[i - 1] : 0);
        }
        return dp[s.length()];
    }

    //可以取两位数
    boolean isDoubleDigitValid(String str, int start) {
        if (start == str.length() - 1) {
            return false;
        }
        if (str.charAt(start) == '0') {
            return false;
        }
        int value = Integer.valueOf(str.substring(start, start + 2));
        return value >= 1 && value <= 26;
    }

    //可以取一位数
    boolean isSingleDigitValid(String s, int index) {
        return s.charAt(index) != '0';
    }
```
