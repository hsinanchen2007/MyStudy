public static boolean CheckPermutation(String s1, String s2) {
        if (s1.length() != s2.length()){
            return false;
        }
        for (int i = 0; i < s1.length(); i++) {
            if (!s2.contains(String.valueOf(s1.charAt(i)))){
                return false;
            }
        }
        for (int i = 0; i < s2.length(); i++) {
            if (!s1.contains(String.valueOf(s2.charAt(i)))){
                return false;
            }
        }
        return true;
    }