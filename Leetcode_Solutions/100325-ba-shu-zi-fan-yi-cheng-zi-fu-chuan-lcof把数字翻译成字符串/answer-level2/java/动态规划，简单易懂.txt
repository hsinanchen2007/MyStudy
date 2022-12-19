### 解题思路


### 代码

```java
class Solution {
    public int translateNum(int num) {
        String str = String.valueOf(num);
        int len = str.length();
        int[] dp = new int[len + 1];
        dp[0] = 1;  
        dp[1] = 1;
        for (int i = 1; i < len; ++i) {
            if (str.charAt(i - 1) == '0'||str.substring(i - 1, i + 1).compareTo("25") >0){
                //beginIndex -- 起始索引（包括）, 索引从 0 开始。 endIndex -- 结束索引（不包括）
                dp[i+1] = dp[i];
            }else {
                dp[i+1] = dp[i] + dp[i-1];
            }
                
            
        }
        return dp[len];
    }
}



```