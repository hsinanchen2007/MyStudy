执行用时 :5 ms, 在所有 Java 提交中击败了94.43%的用户
内存消耗 :35 MB, 在所有 Java 提交中击败了88.48%的用户

记String s长度为n，List<String> wordDict长度为m
时间复杂度：O(nm)


```java
public boolean wordBreak(String s, List<String> wordDict) {
    int n = s.length();
    boolean[] dp = new boolean[n+1];
    // Arrays.fill(dp,false);
    dp[0] = true;

    for (int i = 1;i<=s.length();i++){
        for(int j = 0;j<wordDict.size();j++){
            String word = wordDict.get(j);
            if (i>=word.length()) {
                if (dp[i-word.length()] && word.equals(s.substring(i-word.length(), i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[n];
}
```
