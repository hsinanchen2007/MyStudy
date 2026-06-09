### 解题思路
//字符0-9所对应的十进制整数'0'对应48,'9'对应57
![image.png](https://pic.leetcode-cn.com/d5bb04595a871ea0294489158ba749060bb4b3677a33700a2dfdabf2b6f3bb21-image.png)


### 代码

```java
import java.util.regex.Matcher;
import java.util.regex.Pattern;
class Solution {

    public int myAtoi(String str) {
        boolean negative = false;
        boolean nextDigit = false;
        int ans = 0;
        for (int i = 0;i < str.length();i++){
            char c = str.charAt(i);
            //字符0-9所对应的十进制整数'0'对应48,'9'对应57
            if(nextDigit && (c < 48 || c > 57)){
                break;
            }
            if(c != ' '){
                if(c == '-'){
                    negative = true;       
                }else if(c == '+'){
                }else if(c >= 48 && c <= 57){
                    int digit = c - '0';
                    if (ans > (Integer.MAX_VALUE - digit) / 10) {
                        return negative? Integer.MIN_VALUE : Integer.MAX_VALUE;
                    }
                    ans = ans * 10 + digit;
                }else {
                    break;
                }
                nextDigit = true;
            }
        }
       return negative? -ans : ans;
    }
}
```