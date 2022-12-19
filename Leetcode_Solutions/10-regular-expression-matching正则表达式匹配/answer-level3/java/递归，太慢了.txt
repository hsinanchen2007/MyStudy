### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isMatch(String s, String p) {

        if (s == null && p == null) {
            return true;
        }

        if (s == null && p != null) {
            return false;
        }

        if (s != null && p == null) {
            return false;
        }

        return doMatch(0 , 0 , s , p);
    }

    private boolean doMatch(int ss , int sp , String s , String p) {

        if (ss >= s.length() && sp >= p.length()) {
            return true;
        }

        if (ss >= s.length()) {
           
           if (p.charAt(sp) == '*') {
               return doMatch(ss , sp + 1 , s , p);
           }

           if (sp + 1 >= p.length()) {
               return false;
           }

           if (p.charAt(sp + 1) != '*') {
               return false;
           }

           return doMatch(ss , sp + 2 , s , p);
            
        }

        if (sp >= p.length()) {
            return false;
        }

        char sc = s.charAt(ss);
        char pc = p.charAt(sp);
        if (sp + 1 >= p.length() || p.charAt(sp + 1) != '*') {
            if (pc != '.' && sc != pc) {
                return false;
            }
            return doMatch(ss + 1 , sp + 1 , s , p);
        } else {
            if (pc != '.' && sc != pc) {
                return doMatch(ss , sp + 2 , s , p);
            } else {
                return doMatch(ss + 1 , sp , s , p) 
                || doMatch(ss + 1 , sp + 2 , s , p) 
                || doMatch(ss , sp + 2 , s , p);
            }
        }

    }
}
```