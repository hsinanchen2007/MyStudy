这道题看完之后首先想到是会有很多if。。。。。
写了几个之后就不想写了还是用正则吧，赶紧搜索正则规则（手动狗头）
try一下就能解决溢出的问题了
```
import java.util.regex.*;

class Solution {
    final static Pattern pattern = Pattern.compile("[-+]??[0-9]++");
    public int myAtoi(String str) {
        String strTrim = str.trim();
        Matcher matcher = pattern.matcher(strTrim);
        if (matcher.lookingAt()) {
            String strNum = strTrim.substring(0, matcher.end());
            // 如果直接转32位int出现NFE那么就只要判断是Integer的最大值还是最小值就好了
            try {
                return Integer.parseInt(strNum);
            } catch (NumberFormatException nfe) {
                return strNum.charAt(0) == '-' ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
        }
        return 0;
    }
}
```