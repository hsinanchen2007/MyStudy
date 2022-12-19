基于icecrea的改了改
```java
    public int countSubstrings(String s) {
        int len = s.length();
        int res = 0;
        boolean[] dp = new boolean[len];

        for (int i = len - 1; i >= 0; i--) {
            for (int j = len - 1; j >= i; j--) {
                // 特判
                if (j == 0) {
                  res++;
                  continue;
                }
                if (s.charAt(i) == s.charAt(j) && ((j -i) < 2 || dp[j - 1])) {
                    res++;
                    dp[j] = true;
                } else {
                    dp[j] = false;
                }
            }
        }
        return res;
    }
```
