### 解题思路
1.长度为1的字符子串为回文字符串
2.长度为2的字符子串，当两个字符相同时为回文字符串
3.长度为3的字符串，当起始位置和结束位置字符相同时为回文字符串
4.长度为4的字符串，当起始位置和结束位置字符相同时且第2、3个位置字符也相同时为回文字符串
### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        if(s == null || s.length() == 0) return "" ;
        int n = s.length() ;
        boolean[][] isPalindrome = new boolean[n][n] ;
        char[] ss = s.toCharArray() ;
        String ans = "" ;
        for(int i = 0 ; i < n ; i++){
            isPalindrome[i][i] = true ;//长度为1，一定是回文子串，记为true
            ans = s.substring(i,i+1) ;
        }
        for(int i = 0 ; i < n - 1 ; i++){
            if(ss[i] == ss[i+1]){//长度为2时，两个字符相同，为回文子串，记为true
                isPalindrome[i][i+1] = true ;
                ans = s.substring(i,i+2) ;
            }
        }
        for(int j = 3 ; j <= n ; j++)//长度从3开始依次递增
            for(int i = 0 ; i + j - 1 < n ; i++){
                if(ss[i] == ss[i+j-1] && isPalindrome[i+1][i+j-2]){//始末位置字符相同且中间位置字符串为回文子串时，该字符串回文
                    isPalindrome[i][i+j-1] = true ;
                    if(j > ans.length()){
                        ans = s.substring(i,i+j) ;
                    }
                }
            }
        return ans ;

    }
}
```