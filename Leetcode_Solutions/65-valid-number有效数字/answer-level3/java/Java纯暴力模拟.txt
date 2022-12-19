```
class Solution {
    public boolean isNumber(String s) {
        int i = 0;
        // 分别判断是否出现过了e . 数字
        boolean appearE = false;
        boolean appearPoint = false;
        boolean appearNum = false;
        // 去掉头部空格
        while (i<s.length()&&s.charAt(i) == ' ') {
            i++;
        }
        // 如果只有空格 false
        if (i == s.length())
            return false;
        s=s.substring(i);
        // 判断字符串开头是否合法
        if (!(s.startsWith("+") || s.startsWith("-") || s.charAt(0) == '.'|| s.charAt(0) >= '0' && s.charAt(0) <= '9')) {
            return false;
        }
        // 去掉开头的+-
        if (s.charAt(0) == '-' || s.charAt(0) == '+') {
            s = s.substring(1);
        }
        // 去掉开头的.,并标记出现过了.
        if(s.charAt(0)=='.'){
            s = s.substring(1);
            appearPoint=true;
        }
        // 去掉尾部空格
        i = s.length() - 1;
        while (i >= 0 && s.charAt(i) == ' ') {
            i--;
        }
        if (i == -1)
            return false;
        s = s.substring(0, i+1);
        i = 0;
        while (i < s.length()) {
            if (s.charAt(i) == 'e') {
                if (!appearE&&i<s.length()-1&&appearNum) //如果以前没出现过e并且e不是最后一个字符
                    appearE = true;
                else
                    return false;
                i++;
                if(s.charAt(i)=='+'||s.charAt(i)=='-'){ //对e后面可能+-号的处理，注意判断越界
                    i++;
                    if(i>=s.length())
                        return false;
                }
                continue;
            }
            if (s.charAt(i) == '.') {
                if (!appearPoint&&!appearE) //如果以前没出现过.并也没出现e（e后面不允许出现.）
                    appearPoint = true;
                else
                    return false;
                i++;
                continue;
            }
            if (s.charAt(i) < '0' || s.charAt(i) > '9')//出现非法字符，直接false
                return false;
            appearNum = true;   // 能到这都不return或continue， 肯定是数字了
            i++;
        }
        return true;
    }
}
```
