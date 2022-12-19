### 还是想跟大家分享一下我的思路。我觉得这种问题就三个步骤：
1.建dp数组
2.添加初始值
3.找dp[i]和dp[i-1],dp[i-2]之间的关系
多数比较难得dp一般都是dp间关系以及dp的定义不好找。找到后，这种题就会比较好做。

### 代码

```java
import java.util.*;
class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if(s3.length() != s1.length()+s2.length()) return false;
        int m = s1.length();
        int n = s2.length();
        boolean[][] dp = new boolean[m+1][n+1];
        dp[0][0] = true;
        for(int i =1;i<=m;i++){
            dp[i][0] = (s1.charAt(i-1)==s3.charAt(i-1) && dp[i-1][0] == true)?true:false;
        }
        for(int i =1;i<=n;i++){
            dp[0][i] = (s2.charAt(i-1)==s3.charAt(i-1) && dp[0][i-1] == true)?true:false;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(dp[i-1][j] == false && dp[i][j-1] == false){
                    dp[i][j] = false;
                }else if(dp[i-1][j] == true){
                    if(s1.charAt(i-1)==s3.charAt(i+j-1)){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }else if(dp[i][j-1] == true){
                    if(s2.charAt(j-1)==s3.charAt(i+j-1)){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[m][n];
    }
}
```