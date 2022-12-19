    
    class Solution {
        public boolean isMatch(String s, String p) {
            if(p.isEmpty()) {         //可能s会比p先空
                return s.isEmpty();
            }
            if(p.length() >= 2 && p.charAt(1) == '*') {    //0次或者1次    (.*)这个表达式是通配的
                if(s.length() > 0 && (p.charAt(0) == '.' || p.charAt(0) == s.charAt(0)) ) {
                    return isMatch(s.substring(1), p) || isMatch(s, p.substring(2));
                }else {                                    //如果s为空或者 p.charAt(0) != s.charAt(0)
                    return isMatch(s, p.substring(2));
                }
            }else {
                if(s.length() > 0 && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.') ) {
                    return isMatch(s.substring(1), p.substring(1));
                }
            }
            return false;
        }

    }