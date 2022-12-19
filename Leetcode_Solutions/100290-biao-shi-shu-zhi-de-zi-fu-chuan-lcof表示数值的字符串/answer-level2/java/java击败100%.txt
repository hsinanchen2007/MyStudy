debug要吐血了
```Java
class Solution {
    public boolean isNumber(String s) {
        s = s.trim();
        if (s.length() == 0) return false;
        int fu = 0; // 符号的数量
        int dotNum = 0; // 小数点的数量
        int eNum = 0; // e的数目

        for (int i = 0; i < s.length();i++) {
            char c = s.charAt(i);
            if (c <= '9' && c >= '0') {
                // 正常数字
            } else if (c == 'e' || c == 'E') {
                if (eNum > 0) return false; // e的数目太多
                if (i == 0 || i == s.length() - 1) return false; //e在最后一位
                eNum ++; // e的数目增加
                // fu = 0;
            } else if (c == '.') {
                // e后面需要是整数，小数点只能在前面
                if (eNum > 0) return false; // e后面只能是整数 3.4e3.4
                if (dotNum > 0) return false; //小数点的数目  3.2.1
                // .3e4  3.e4  3.  .3  .e
                if (s.length() == 1) return false; // 只有一个小数点
                // 第一位是小数点，后面一位不是数字
                if (i == 0 && (s.charAt(i + 1) > '9' || s.charAt(i + 1) < '0')) return false; 
                // 最后一位是小数点，前一位不是数字
                if (i == s.length() - 1 && (s.charAt(i - 1) > '9' || s.charAt(i - 1) < '0'))                      return false;
                dotNum ++;
            } else if (c == '+' || c == '-') {
                // +-45  +45e+
                if (s.length() == 1) return false; // 只有正负号
                if (i != 0) {
                    // 正负号不是第一位，就要判断前一位是不是e，如果是e，就要判断后面还有没有数字
                    if (i == s.length() - 1) return false;
                    if (s.charAt(i - 1) != 'e' && s.charAt(i - 1) != 'E') return false;
                    // 4-5
                } else {
                    // i == 0
                    if ((s.charAt(i + 1) < '0' || s.charAt(i + 1) > '9') && s.charAt(i + 1) != '.') return false;
                }
            } else {
                return false;
            }
            
        }
        return true;

        
    }
}
```
