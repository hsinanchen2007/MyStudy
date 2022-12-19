1.首先第一部分算出s的每一段substring 变成回文需要修改多少字符串
1.1这部分的状态转移方程是
**pali[i][j] = pali[i+1][j-1]+1(如果i和j位置的字符串不等) 
pali[i][j] = pali[i+1][j-1] (如果i和j位置的字符串相等)
注意 如果j-i<=1，即i到j之间有小于等于2个字符串的时候
pali[i][j] = 1(如果i和j位置的字符串不等) 
pali[i][j] = 0(如果i和j位置的字符串相等)**

2.计算分割成k个字符串后让每个字符串变成回文字符串的最少修改次数
**用dp[i][j]表示，i表示切割成i个 j表示当前字符串的长度
状态转移方程是
dp[i][j] = min(dp[i-1][x] + pali[x+1][j])
其中x的取值范围是[i-1, j-1] (i-1表示前i-1个字符串，每一个字母一段，j-1表示最后一个字母一段)**

```
class Solution {
    public int palindromePartition(String s, int k) {
        int[][] pali= new int[s.length() + 1][s.length() + 1];
        for(int i = s.length(); i >= 1; i--)
        {
            for(int j = i; j <= s.length(); j++)
            {
                if(j - i >= 2)
                    pali[i][j] = pali[i + 1][j - 1];
                if(s.charAt(i - 1) != s.charAt(j - 1))
                    pali[i][j]++;
            }
        }
        
        int[][] dp = new int[k + 1][s.length() + 1];
        for(int i = 1; i <= k; i++)
        {
            for(int j = i; j <= s.length(); j++)
            {
                if(i == 1)
                    dp[i][j] = pali[i][j];
                else
                {
                    dp[i][j] = dp[i - 1][i - 1] + pali[i][j];
                    for(int x = i; x < j; x++)
                        dp[i][j] = Math.min(dp[i][j], dp[i - 1][x] + pali[x + 1][j]);
                }
            }
        }
        return dp[k][s.length()];
    }
}
```