### 解题思路
一维dp，dp[i]标识字符下标从0到i，是否可以被拆分。如果dp[i]=true，可以将i+1作为一个拆分点，拆分点表示0~i是可以被拆分的，0为第一个拆分点。
比如当前dp[] = {t,f,t,t},拆分点应该是{0,1,3},判断dp[5]的时候只需要判断s.subString(3,i+2),s.subString(1,i+2),s.subString(0,i+2)有任一个在dict中，dp[5]就位true。
提示：官方给出的测试用例从后向前判会更快

### 代码

```java
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> dict = new HashSet<>(wordDict);
        int maxlen = 0;
        int minlen = Integer.MAX_VALUE;
        for (String s1 : wordDict) {
            maxlen = Math.max(maxlen, s1.length());
            minlen = Math.min(minlen, s1.length());
        }

        boolean[] dp = new boolean[s.length()];
        List<Integer> startIndices = new ArrayList<>();

        dp[0] = wordDict.contains(s.substring(0, 1));
        startIndices.add(0);
        if (dp[0]) {
            startIndices.add(1);
        }

        for (int i = 1; i < s.toCharArray().length; i++) {
            for (int j = startIndices.size() - 1; j >= 0; j--) {
                int len = i + 1 - startIndices.get(j);
                if (len <= maxlen && len >= minlen && dict.contains(s.substring(startIndices.get(j), i + 1))) {
                    dp[i] = true;
                    break;
                }
            }

            if (dp[i]) {
                startIndices.add(i + 1);
            }
        }
        return dp[dp.length - 1];
    }
}
```