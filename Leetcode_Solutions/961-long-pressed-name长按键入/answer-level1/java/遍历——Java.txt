思路：同时遍历name和typed，逐个取不重复字符，比较即可。
<br/><br/>
代码：
```
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        if (typed.length() < name.length()) {
            return false;
        }
        
        int i = 0;
        int j = 0;
        while (i < name.length() && j < typed.length()) {
            char n = name.charAt(i);
            char t = typed.charAt(j);

            if (n != t) {
                return false;
            }
            
            int cn = 0;
            while (i < name.length() && name.charAt(i) == n) {
                i++;
                cn++;
            }
            
            int ct = 0;
            while (j < typed.length() && typed.charAt(j) == n) {
                j++;
                ct++;
            }
            
            if (ct < cn) {
                return false;
            }
        }
        
        if (i != name.length() || j != typed.length()) {
            return false;
        }
        
        return true;
    }
}
```