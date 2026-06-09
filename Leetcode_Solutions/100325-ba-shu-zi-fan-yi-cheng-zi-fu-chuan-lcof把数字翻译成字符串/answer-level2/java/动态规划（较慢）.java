思路在代码中

### 代码

```java
class Solution {
    public int translateNum(int num) {
        String str = num + "";
        int len = str.length();
        //数字长度为0和为1
        if(len == 0) return 0;
        if(len == 1) return 1;
        //动规数组
        int[] dp = new int[len+1];
        dp[0] = dp[1] = 1;
        for(int i = 2;i < len + 1;i++){
            //如果能够和前面的字符组成小于等于25的数字
            //则有dp[i-1] + dp[i-2]种组合方法
            //如1225  取到5时 有25 前面2种  有单独5  前面3种
            if(str.charAt(i-2) != '0' &&
                str.substring(i-2,i).compareTo("25") <= 0){
                    dp[i] = dp[i-1] + dp[i-2];  
            }else{
            //如果不能组成,就单独为1个数字,和前面方法数相等
                dp[i] = dp[i-1];
            }
        }
        return dp[len];
    }
}
```