1. 考虑各种情况
```
import java.util.*;

class Solution {
    public boolean isNumber(String s) {
        boolean result = true;
        //去掉前面后面的空格
        int left = 0;
        while(left < s.length()) {
            if(s.charAt(left) == ' ') {
                left++;
            }else break;
        }
        s = s.substring(left);
        int right = s.length() - 1;
        while(right >= 0) {
            if(s.charAt(right) == ' ') {
                right--;
            }else break;
        }
        s = s.substring(0, right + 1);
        //字符串内没有字符，没有数字
        if(s.length() == 0)
            return false;
        //可以出现的字符跟字符出现的位置
        HashMap<Character, Integer> hashMap = new HashMap<>();
        hashMap.put('-', -1);
        hashMap.put('+', -1);
        hashMap.put('e', -1);
        hashMap.put('.', -1);
        for(int i = 0; i <= 9; i++) {
            hashMap.put((char)(i + '0'), -1);
        }


        for(int i = 0; i < s.length(); i++) {
            if(!hashMap.containsKey(s.charAt(i))) {
                result = false;
                break;
            }
            //正负符号只能出现的第一位或者前一位是e
            //正负符号不能出现在最后一位
            //正负符号的后一位要么是'.' 要么是数字
            if(s.charAt(i) == '-' || s.charAt(i) == '+') {
                if( (i != 0 && i - 1 != hashMap.get('e')) || i == s.length() - 1 || s.charAt(i+1) != '.' && (s.charAt(i + 1) < '0' || s.charAt(i + 1) > '9')) {
                    result = false;
                    break;
                } else {
                    hashMap.put(s.charAt(i), i);
                }
            }
            //之前不能出现过e
            //e不能作为第一位或者最后一位
            //它的前一位要么是数字，要么是'.'
            //它的后一位要么是数字，要么是正负符号
            if(s.charAt(i) == 'e') {
                if(hashMap.get('e') != -1 || i == 0 || i == s.length() - 1 || (s.charAt(i - 1) != '.' && s.charAt(i - 1) < '0' || s.charAt(i - 1) > '9')
                || (s.charAt(i + 1) != '-' && s.charAt(i + 1) != '+') && (s.charAt(i + 1) < '0' || s.charAt(i + 1) > '9')) {
                    result = false;
                    break;
                }else {
                    hashMap.put(s.charAt(i), i);
                }
            }
            //'.'之前不能出现
            //'.'不能出现在e后面
            //'.'的前后必须出现一次是数字
            if(s.charAt(i) == '.') {
                if(hashMap.get('.') != -1 || hashMap.get('e') != -1 || (i == 0 || s.charAt(i - 1) < '0' || s.charAt(i - 1) > '9')
                && (i == s.length() - 1 || s.charAt(i + 1) < '0' || s.charAt(i + 1) >'9')) {
                    result = false;
                    break;
                }else {
                    hashMap.put(s.charAt(i), i);
                }
            }

        }

        return result;
    }
}
```
2. 自动机
3. 