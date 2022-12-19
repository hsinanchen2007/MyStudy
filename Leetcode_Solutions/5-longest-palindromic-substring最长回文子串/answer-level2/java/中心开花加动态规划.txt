### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
       if(s.length()==0 || s==null)
        {
            return "";
        }
        int strlen=s.length();
        int maxEnd=0;
        int maxStart=0;
        int maxlen=0;
        boolean[][] dp=new boolean[strlen][strlen];
      for(int r=1;r<strlen;r++)
      {
        for(int l=0;l<r;l++)
        if(s.charAt(l)==s.charAt(r) && ((r-l<=2) || dp[l+1][r-1]))
        {
           dp[l][r]=true;
           if(r-l+1>maxlen)
           {
               maxlen=r-l+1;
               maxStart=l;
               maxEnd=r;
           }
        }
      }
        return s.substring(maxStart,maxEnd+1);
        
       
    
    }
}
```