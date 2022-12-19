- 首先理一下暴力递归的思路：

![交错字符串](https://pic.leetcode-cn.com/6d77fbac8b62ed70bd26d1620ccad6d2319b4de418604375d1598865607a7c55.png)

- 直接上暴力递归的代码
```
    // 交错字符串
    public boolean isInterleave(String s1, String s2, String s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        HashMap<String,Boolean> memo = new HashMap<>();
        return getRes(s1,0,s2,0,s3,0,memo);
    }

    private boolean getRes(String s1, int c1, String s2, int c2, String s3, int c3, HashMap<String, Boolean> memo) {
        if(c3 == s3.length()) return true;
        if(c1 == s1.length()) return s2.substring(c2,s2.length()).equals(s3.substring(c3,s3.length()));
        if(c2 == s2.length()) return s1.substring(c1,s1.length()).equals(s3.substring(c3,s3.length()));
        String key = c1 + "@" + c2;
        if(memo.containsKey(key)) return memo.get(key);
        if(s1.charAt(c1) ==  s3.charAt(c3)) {
            if(getRes(s1,c1+1,s2,c2,s3,c3+1,memo)){
                memo.put(key,true);
                return true;
            }
        }
        if(s2.charAt(c2) ==  s3.charAt(c3)) {
            if(getRes(s1,c1,s2,c2+1,s3,c3+1,memo)){
                memo.put(key,true);
                return true;
            }
        }
        memo.put(key,false);
        return false;
    }
```
- 同样的，动态规划优化如下;
```

    // 交错字符串
    public boolean isInterleave(String s1, String s2, String s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if(len1 + len2 != len3) return false;
        boolean[][] dp = new boolean[len1 + 1][len2 + 1];
        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                }else if(i == 0){
                    dp[i][j] = dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(j - 1);
                }else if(j == 0) {
                    dp[i][j] = dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i - 1);
                }else{
                    dp[i][j] = (dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1)) ||
                                (dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1));
                }
                // 默认情况下不进行任何操作，直接默认赋值false
            }
        }
        return dp[len1][len2];
    }
```