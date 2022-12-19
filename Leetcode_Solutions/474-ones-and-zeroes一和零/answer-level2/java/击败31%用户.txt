### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        // 如果strs里面没有字符串则直接返回0
        if(strs.length == 0){
            return 0;
        }
        // 如果没有0和1，则拼不成任何字符串
        if(m == 0 && n == 0){
            return 0;
        }
        // dp[x][y]里保存的是x个0和y个0的条件下最多拼成几个字符串
        int[][] dp = new int[m+1][n+1];
        for(String s : strs){
            char[] sArray = s.toCharArray();
            //  zeros，ones变量分别保存sArray里面‘0’和‘1’的个数
            int zeros = 0;
            int ones = 0;
            for(char c : sArray){
                if(c == '0'){
                    zeros++;
                }
                else{
                    ones++;
                }
            }

            for(int i = m; i >= zeros; i--){
                for(int j = n; j >= ones; j--){
                    // 可以选择装不装这个字符串
                    dp[i][j] = Math.max(dp[i][j], dp[i-zeros][j-ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
}
```