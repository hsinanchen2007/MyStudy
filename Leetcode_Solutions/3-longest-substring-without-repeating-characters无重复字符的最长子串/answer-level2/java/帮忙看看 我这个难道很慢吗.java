public int lengthOfLongestSubstring(String s) {
        StringBuffer a = new StringBuffer();
        int result = 0;
        if (s.length()>Integer.MAX_VALUE){
            throw new IllegalArgumentException("too long");
        }
        if (s == "" || s.length() == 0){
            return  0;
        }
        for (int i = 0; i < s.split("").length; i++) {
            String s2 = s.split("")[i];
            if ((a.indexOf(s2)) < 0) {
                a.append(s2);
                if (i == s.split("").length-1 && result < a.length()){
                    result  = a.length();
                }
            }else{
                System.out.println(a.toString());
                if (a.length() > result) {
                    result = a.length();
                }
                a = new StringBuffer(a.substring(a.indexOf(s2)+1, a.length()));
                i--;
            }

        }
        return result;
    }