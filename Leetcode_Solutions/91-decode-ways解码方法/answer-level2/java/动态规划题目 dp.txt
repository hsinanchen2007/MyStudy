### 解题思路
这题需要考虑的情况比较多
重点是以下几点
1，首个数字为0时，返回0
2，前两个字符为00 或者 30 40 ......90时，返回0

其他按照dp动态方程即可

### 代码

```java
class Solution {
    public int numDecodings(String s) {
        
        //首个数字为0 返回不匹配
        if (s.charAt(0) == '0') {
            return 0;
        }

        //一维动态规划问题 dp i代表字符串s有几种解码方法
        int[] dp = new int[s.length()+1];
        
        //初始化dp
        dp[0] = 1;
        
        dp[1] = 1;
        
        //状态转移方程
        for (int i = 2; i < s.length() + 1; i++) {
            //当前数的两个数是否可被解码
            String tempStr = s.substring(i-2, i);
            int    temp = Integer.parseInt(s.substring(i-2, i));
            
            //debug
            //System.out.println(tempStr);
            
            if (tempStr.equals("00") || 
                  ( Integer.parseInt(s.substring(i-2, i-1)) > 2 
                     && Integer.parseInt(s.substring(i-1, i)) == 0)) {//前两个字符为 00 30 ....90 时不能匹配 
                return 0;
            }

            //正常动态规划过程
            if ((temp > 10 && temp < 20) || (temp > 20 && temp < 27)) {
                dp[i] = dp[i-1] + dp[i-2];
            }  else if (temp == 10 || temp == 20) {//连续多个0的情况
                dp[i] = dp[i-2];
            } else {
                dp[i] = dp[i-1];
            }
        }

        return dp[s.length()];
    }
}
```