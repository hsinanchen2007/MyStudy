### 解题思路
动态规划
特殊情况需要处理：
1. 10,20: dp[i] = dp[i-2]
2. 30.40.50.60...: 0
3. 00: 0
4. 0: 0

### 代码

```java
class Solution {
    public int numDecodings(String s) {
        int length = s.length();
        if(length==0||s.charAt(0)=='0')
            return 0;
        if(length==1)
                return 1;

        int[] dp = new int[length];
        dp[0] = 1;

        int tmp = Integer.parseInt(s.charAt(0)+""+s.charAt(1));
        if(tmp>26&&s.charAt(1)=='0')
            return 0;
        if(tmp>26||tmp==10||tmp==20)
            dp[1] = 1;
        else
            dp[1] = 2;

        for(int i=2; i<length; i++){
            int num = Integer.parseInt(s.charAt(i-1)+""+s.charAt(i));
            if(s.charAt(i)=='0'&&s.charAt(i-1)=='0')
                return 0;
            if(num>26&&s.charAt(i)=='0')
                return 0;
            if(num>26||num<10)
                dp[i] = dp[i-1];
            else if(s.charAt(i)=='0')
                dp[i] = dp[i-2];
            else
                dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[length-1];
    }
}
```