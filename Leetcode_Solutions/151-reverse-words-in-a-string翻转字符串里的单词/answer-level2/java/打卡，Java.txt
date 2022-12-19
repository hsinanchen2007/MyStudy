
    class Solution {
        public String reverseWords(String s) {
            s = s.trim();
            if(s.length() == 0) {
                return "";
            }
            String[] str = s.split(" ");
            StringBuilder sb = new StringBuilder();
            for(int i = str.length - 1;i >= 0;i--) {
                if(!"".equals(str[i])) {
                    sb.append(str[i] + " ");
                }
            }
            sb.deleteCharAt(sb.length() - 1);
            return sb.toString();
        }
    }