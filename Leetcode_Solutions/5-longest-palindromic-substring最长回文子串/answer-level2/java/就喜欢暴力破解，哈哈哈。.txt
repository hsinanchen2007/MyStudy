就喜欢暴力破解，哈哈哈。   

     private Boolean isRight(String str) {
        for (int i = 0; i < str.length () / 2; i++) {
            if (str.charAt (i) != str.charAt (str.length () - i - 1)) {
                return false;
            }
        }
        return true;
    }

    public String longestPalindrome(String s) {
        String res = new String ();
        int len = 0;
        for (int i = 0; i < s.length (); i++) {
            for (int j = i; j < s.length (); j++) {
                if (len >= (j + 1 - i)) {
                    continue;
                }
                String tmpstr = s.substring (i,j + 1);
                if (isRight (tmpstr)) {
                    if (len < tmpstr.length ()) {
                        len = tmpstr.length ();
                        res = tmpstr;
                    }
                }
            }
        }
        return res;
    }