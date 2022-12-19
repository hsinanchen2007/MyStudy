先转成字符串，创建dp数组，前一位和当前位组成的字符串和25比较就行了，还有注意前一位为0是不能算的。

```
class Solution {
    public int translateNum(int num) {
        String s = String.valueOf(num);
        int l = s.length();
        if (l == 1) return 1;
        int[] dp = new int[l+1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < l; i++) {
            if (s.charAt(i-1) != '0' && s.substring(i-1, i+1).compareTo("25") <= 0) {
                dp[i+1] = dp[i] + dp[i-1];
            } else {
                dp[i+1] = dp[i];
            }
        }
        return dp[l];
    }
}
```
