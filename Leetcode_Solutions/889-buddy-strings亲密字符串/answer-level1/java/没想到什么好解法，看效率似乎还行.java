class Solution {
    public boolean buddyStrings(String A, String B) {
        if (A == null && B == null) {
            return false;
        }
        if ("".equals(A) && "".equals(B)) {
            return false;
        }
        if (A.length() != B.length()) {
            return false;
        }
        int diff = 0;
        char[] ar = A.toCharArray();
        char[] br = B.toCharArray();
        int key1 = 0;
        int key2 = 0;
        for (int i = 0; i < A.length(); i++) {
            if (ar[i] != br[i]) {
                diff++;
                if (diff == 1) {
                    key1 = i;
                } else if (diff == 2) {
                    key2 = i;
                } else {
                    return false;
                }
            }
        }
        if (diff == 0) {
            char temp = 'a';
            for (int i = 0; i < 26; i++) {
                if (A.indexOf(temp) != A.lastIndexOf(temp)) {
                    return true;
                }
                temp++;
            }
            return false;
        }
        if (diff == 2) {
            return ar[key1] == br[key2] && ar[key2] == br[key1];
        }
        return false;
    }
}