### 解题思路
太晚了，明天再写思路。

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        String[] dp = new String[n] ;
        dp[0] = "1" ;
        StringBuilder sb = new StringBuilder() ;
        for(int i = 1 ; i < n ; i++){
            int count = 1 ;
            sb = new StringBuilder() ;
            char[] ss = dp[i-1].toCharArray() ;
            int len = ss.length ;
            for(int j = 0 ; j < len - 1 ; j++){
                if(ss[j] == ss[j+1]){
                    count++ ;
                    continue ;
                }
                sb.append(String.valueOf(count)).append(ss[j]) ;
                count = 1 ;   
            }
            sb.append(String.valueOf(count)).append(ss[len-1]) ;
            dp[i] = sb.toString() ;
        }
        return dp[n-1] ;
    }
}
```