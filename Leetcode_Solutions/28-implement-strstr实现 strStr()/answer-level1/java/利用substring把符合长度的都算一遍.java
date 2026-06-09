执行用时 :1 ms, 在所有 Java 提交中击败了99.33%的用户
内存消耗 :36.7 MB, 在所有 Java 提交中击败了78.83%的用户

    public int strStr(String haystack, String needle) {
        if (needle.length() > haystack.length()) {
            return -1;
        }
        if (haystack.equals(needle)) {
            return 0;
        }
        if ("".equals(needle)){
            return 0;

        }
        else {
            int l = needle.length();
            for (int i = 0; i < haystack.length(); i++) {
                if (haystack.length()-i < l){
                    return -1;
                }
                if(haystack.substring(i,i+l).equals(needle)){
                    return i;
                }
            }
            return -1;
        }
    }

