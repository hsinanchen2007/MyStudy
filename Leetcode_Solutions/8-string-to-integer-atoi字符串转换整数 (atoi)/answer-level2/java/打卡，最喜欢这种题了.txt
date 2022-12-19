    
    class Solution {
        public int myAtoi(String str) {
            String s = str.trim();
            int i = 0;
            boolean symbol = false;
            if(s.length() == 0) {
                return 0;
            }
            if(s.charAt(i) == '+' || s.charAt(i) == '-') {
                symbol = s.charAt(i) == '+' ? false : true;
                i++;
            }
            if(i == s.length() || !(s.charAt(i) >= '0' && s.charAt(i) <= '9')) {
                return 0;
            }
            long num = 0;
            while(i < s.length() && s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                if(num > Integer.MAX_VALUE) {
                    break;
                }
                num = num * 10 + (s.charAt(i) - '0');
                i++;
            }
            if(symbol) {  // 负号
                return -num < Integer.MIN_VALUE ? Integer.MIN_VALUE : (int)-num;
            }
            return num > Integer.MAX_VALUE ? Integer.MAX_VALUE : (int)num;
        }
    }