### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {

    public String longestPalindrome(String s) {
        if(s==null||s.length()<2) return s;
        boolean[][] dp=new boolean[s.length()][s.length()];
        for(int i=0;i<s.length();i++){
            dp[i][i]=true;
        }
        int max=0;
        int i=0;
        int j=0;
        for(int len=2;len<=s.length();len++){
            for(int l=0;l<=s.length()-len;l++){
                if(s.charAt(l)==s.charAt(l+len-1)&&(len==2||dp[l+1][l+len-2])){
                    dp[l][l+len-1]=true;
                    if(len>max) {
                        max=len;
                        i=l;
                        j=l+len-1;
                    }
                }
            }
        }
        return s.substring(i,j+1);
    }

}
```