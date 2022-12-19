### 解题思路
首先我们要寻找最长回文子串，那么就从最长子串开始判断；
假设字符串长度为k，那么判断长度为k的子串是不是回文串，是就返回，不是k--；
紧接着判断长度为k-1的子串中是否有回文串，有，就返回没有就继续k--；
直到k的长度为1，那么此时将直接返回首字符。
### 代码

```java
class Solution {
//最長子串
    public static String longestPalindrome(String s) {
        if (s == null ){
            return null;
        }
        if (s.equals("")){
            return "";
        }
        int k = s.length();
        while (k>0){
            for (int i = 0; i <=s.length()-k; i++) {
                int a = i;
                int b = i+k-1;
                while(a<=b && s.charAt(a) == s.charAt(b)){
                    a++;
                    b--;
                }
                if (a>b){
                    return s.substring(i,i+k);
                } 
            }
            k--;
        }
        return s.substring(0,1);
    }

}
```