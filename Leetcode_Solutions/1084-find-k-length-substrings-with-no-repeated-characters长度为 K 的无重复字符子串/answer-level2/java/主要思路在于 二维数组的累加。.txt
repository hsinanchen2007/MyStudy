### 解题思路
此处撰写解题思路
从i开始，到i+k结束的子字符串，含26个字符的个数。设置dp[i][0...25]为0到i的所有字符的累加，dp[i+k][0...25]为0到i+k的所有字符的累加，相减得出子串所有字符，都小于2，就满足条件。计数加1；
### 代码

```java
class Solution {
    public int numKLenSubstrNoRepeats(String S, int K) {
        int len= S.length();
        int [][] dp = new int [len][26];
        int i = 0 ;
        int k=K ;
        dp[i][S.charAt(i)-'a']=1;
        for(i=1;i<len;i++){
            for(int j = 0 ;j<26;j++){
                dp[i][j]=dp[i-1][j];
            }
            dp[i][S.charAt(i)-'a']=dp[i-1][S.charAt(i)-'a']+1;
        }
        int count = 0 ;
        for(i=0;i<=len - k ;i++){
            int j ;
            if(i==0){
                int flag = 0;
                for(j=0;j<26;j++)
                if(dp[k-1][j]>1){
                   flag=1; 
                }
                if(flag==0){
                    count++;
                }
                continue ;
            }
       
                int flag = 0;
                for(j=0;j<26;j++)
                if(dp[k+i-1][j]-dp[i-1][j]>1){
                   flag=1; 
                }
                if(flag==0){
                    count++;
                }
        }
        return count ;
        }
    }

```