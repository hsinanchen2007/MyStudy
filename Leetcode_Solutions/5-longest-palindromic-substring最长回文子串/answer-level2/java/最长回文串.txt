### 解题思路
此处撰写解题思路
首先如果串长为1时，回文串的长度为1
 
然后依次设置回文串的长度为2到字符串的长度；回文串 charAt(e)    与charAt(e+(回文串长度) -1)相等
依次验证，验证 dp[e][index] = 1 并设置开始的位置和最大回文串的长度

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        int len = s.length();
        if(len<2) return s;

        int startIndex = 0;
        int max = 1;
        //J为回文串的长度
        int[][] dp = new int[len][len];
 f      or(int i = 0;i<len;i++){
            dp[i][i] = 1;
             if(i<len -1 && s.charAt(i) == s.charAt(i+1)) dp[i][i+1] = 1; 
        }       
        
         for(int j = 2; j <= len; j++){
             dp[i-1][j-1] = 1
            for(int e = 0 ; e+j-1 < len ;e++){
                int endIndex = j+e - 1;

                if(s.charAt(e) == s.charAt(endIndex) && dp[e+1][endIndex-1] == 1){
                    dp[e][endIndex] = 1;
                    startIndex = e;
                    max = j;
                }

            }
        }

        return s.substring(startIndex,startIndex+max);
    }
}
```