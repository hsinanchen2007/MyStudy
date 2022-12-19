dp[i]表示前i个字符所需最小翻转次数，则dp[i+1]有如下四种情况，取其最小值即可
1、第i+1个字符为0，且不翻转，d[i+1]=前i个字符中1的个数
2、第i+1个字符为0，且翻转，d[i+1]=d[i]+1
3、第i+1个字符为1，且不翻转，d[i+1]=d[i]
4、第i+1个字符为1，且翻转，d[i+1]=前i个字符中1的个数+1
其中1的个数可以在遍历S的时候记录下来。代码如下
```
    public static int minFlipsMonoIncr(String S) {
        int numOfOne = 0;
        int len = S.length();
        int[] dp = new int[len];
        for (int i = 0; i < len; i++) {
            if (S.charAt(i) == '1') {
                dp[i] = (i == 0 ? 0 : Math.min(dp[i - 1], numOfOne + 1));
                numOfOne++;                
            } else {
                dp[i] = (i == 0 ? 0 : Math.min(dp[i - 1] + 1, numOfOne));
            }

        }
        return dp[len -1];
    }
```
