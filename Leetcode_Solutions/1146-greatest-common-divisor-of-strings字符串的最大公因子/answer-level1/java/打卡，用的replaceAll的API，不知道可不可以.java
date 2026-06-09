    
    class Solution {
        public String gcdOfStrings(String str1, String str2) {
            int len1 = str1.length(), len2 = str2.length();
            for(int i = Math.min(len1, len2);i >= 1;i--) {
                if(len1 % i + len2 % i == 0) {
                    String sub = str1.substring(0, i);
                    if(str1.replaceAll(sub, "").equals(str2.replaceAll(sub, ""))) {
                        return sub;
                    }
                }
            }
            return "";
        }
    }