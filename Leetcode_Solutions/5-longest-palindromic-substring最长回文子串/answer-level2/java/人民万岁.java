```
class Solution {
    String ret = "" ;
    public String longestPalindrome(String s) {
        for (int k=0 ; k< s.length() ; k++) {
            expandFromMiddle(s,k,k) ;
            if (k!=s.length()-1)
                expandFromMiddle(s,k,k+1) ;
        }
        return ret ;
    }

    public void expandFromMiddle(String s,int i,int j) {
        while (i < s.length() && j < s.length() && i >= 0) {
            if (s.charAt(i) == s.charAt(j)) {
                if (ret.length() < (j - i + 1 ) )
                    ret = s.substring(i,j+1) ;
                i -- ;
                j ++ ;

            } else {
                return ;
            }
        }
    }
}
```
