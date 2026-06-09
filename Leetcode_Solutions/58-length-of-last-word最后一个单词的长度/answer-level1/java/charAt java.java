    class Solution {
        public int lengthOfLastWord(String s) {
            if (s.length() <= 0) return 0;
            int count = 0;
            int i = s.length();
            while ((i > 0) && (s.charAt(i-1) == ' ')) {
                i--;
            }
            for (; i > 0 ; i--) {
                if (s.charAt(i-1) == ' ') {
                    break;
                }
                count++;
            }
            return (count);
        }
    }