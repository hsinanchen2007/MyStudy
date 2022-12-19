### 解题思路
把数字翻译成字符串，采用动态规划进行求解；
dp[0] = 1,第一个数字肯定满足对应的字符串的；
当第i-1字符在0~9之间时，那么对应的dp[i]+=dp[i-1];
当第i-2个字符和第i-1个字符组成的数字在10~25之间时，dp[i]+=dp[i-2];

### 代码

```java
class Solution {
    //采用动态规划，dp[i]中，如果前一个数字在0~9之间 dp[i]+=dp[i-1];
    //如果i-2和i-1组成的数字在 0~25之间，dp[i]+=dp[i-2];
    public int translateNum(int num) {
        char[] ch = String.valueOf(num).toCharArray();
        int n = ch.length;
        int[] dp = new int[n+1];
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            int number = ch[i-1]-'0';
            if(number<=9&&number>=0){
                dp[i]+=dp[i-1];
            }
            if(i>1){
                int number2 = (ch[i-2]-'0')*10+(ch[i-1]-'0');
                if(number2>=10&&number2<=25){
                    dp[i]+=dp[i-2];
                }
            }
        }
        return dp[n];
    }
}
```