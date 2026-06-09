### 解题思路
1，特例，空字符串是有效的
2，数字和字母是有效的，需要过滤出来
3，判断回文字符串 

### 代码

```java
import java.lang.StringBuffer;
class Solution {
    public boolean isPalindrome(String s) {
         if (s.length() == 0) {
             return true;
         }
         
         StringBuffer sb = new StringBuffer();

         for (int i = 0; i < s.length(); i++) {
              if ((s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') || (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') || (s.charAt(i) >= '0' && s.charAt(i) <= '9')) {//数字字符
                  sb.append(String.valueOf(s.charAt(i)).toLowerCase());
         }
         }
        
         //debug
         //System.out.println(sb.toString());

         return isPal(sb.toString());

    }

    //验证是否是回文字符串
    private boolean isPal(String s) {
        //System.out.println(s+"lllttt");
        if (s.length() <= 1) {
            return true;
        }

        int i = 0;
        int j = s.length() - 1;

        while (i <= j) {
            //System.out.println(String.valueOf(s.charAt(i)));
            //System.out.println(String.valueOf(s.charAt(j)));
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        } 

        return true;
    }
}
```