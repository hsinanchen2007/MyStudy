```java
class Solution {
    public int longestStrChain(String[] words) {
        int n = words.length;
        Arrays.sort(words, Comparator.comparingInt(String::length));
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        int max = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isBefore(words[j], words[i])) {
                    dp[i] = Math.max(dp[i], 1 + dp[j]); 
                }
            }
            max = Math.max(max, dp[i]);
        }
        return max;
    }

    private boolean isBefore(String pre, String pos) {
        if (pre.length() + 1 != pos.length()) {
            return false;
        }
        int i = 0;
        int j = 0;
        int n = 0;
        while (i < pre.length()) {
            if (pre.charAt(i) == pos.charAt(j)) {
                i++;
                j++;
            } else {
                if (n > 0 || pre.charAt(i) != pos.charAt(j + 1)) {
                    return false;
                } else {
                    n++;
                    i++;
                    j += 2;
                }
            }
        }
        return true;
    }
}
```
