### 解题思路
没啥思路，就是直接判断，这题测试用例简直超乎。。想象，被折磨很久了终于改出了一个可以过的版本，期待大神的答案。

### 代码

```java
class Solution {
    public boolean isNumber(String s) {
        if (s == null || s.length() == 0) return false;
        boolean hasNum = false;
        boolean hasE = false;
        boolean hasDot = false;
        String st = s.trim();
        int l = st.length();
        if (l == 0) return false;
        for (int i = 0; i < l; i++ ) {
            if (st.charAt(i) >= '0' && st.charAt(i) <= '9') {
                hasNum = true;
            } else if (st.charAt(i) == 'e' || st.charAt(i) == 'E') {
                if (!hasNum || i == l - 1 || hasE || i == 0) {
                    return false;
                }
                hasE = true;
            } else if (st.charAt(i) == '.') {
                if (hasE || hasDot) {
                    return false;
                }
                if (!hasNum && i == l - 1) {
                    return false;
                }
                hasDot = true;
            } else if (st.charAt(i) == '+' || st.charAt(i) == '-') {
                if (i > 0 && st.charAt(i - 1) != 'e' && st.charAt(i - 1) != 'E') {
                    return false;
                }
                if (i == l - 1) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
    
}
```