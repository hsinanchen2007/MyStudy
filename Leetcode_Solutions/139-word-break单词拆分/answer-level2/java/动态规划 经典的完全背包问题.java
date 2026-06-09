经典的完全背包问题，关于01背包与完全背包可以参考此处。
[背包问题详解](https://blog.csdn.net/reed1991/article/details/53352426)
```
public boolean wordBreak(String s, List<String> wordDict) {
        if (s == null) {
            return true;
        }
        if (wordDict == null || wordDict.size() == 0) {
            return false;
        }

        Set<String> set = new HashSet<>(wordDict);
        boolean[] dp = new boolean[s.length() + 1];

        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && set.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length()];

    }
```
