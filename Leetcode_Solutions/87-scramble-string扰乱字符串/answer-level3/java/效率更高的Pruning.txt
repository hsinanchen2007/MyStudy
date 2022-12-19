```
public boolean isScramble(String s1, String s2) {
            if (s1.length() != s2.length()) {
                return false;
            }
            if (s1.equals(s2)) {
                return true;
            }
            if (!counter(s1,s2)){
                return false;
            }
            int len = s1.length();
            for (int i = 1; i < len; i++) {
                if (isScramble(s1.substring(0, i), s2.substring(0, i)) && isScramble(s1.substring(i, len), s2.substring(i, len))
//                        ||isScramble(s1.substring(len - i, len), s2.substring(len - i, len)) && isScramble(s1.substring(0, len - i), s2.substring(0, len - i))
                        || isScramble(s1.substring(0, i), s2.substring(len - i, len)) && isScramble(s1.substring(i, len), s2.substring(0, len - i))) {
                    return true;

                }
            }
            return false;
        }

        public boolean counter(String s1, String s2) {
            int res = 0;
            int len = s1.length();
            for (int i = 0; i < len; i++) {
                res = res ^ s1.charAt(i)^ s2.charAt(i);
            }
            return res == 0;
        }
```
解法常规，即是brute force+ pruning,相对其他解法，本题解pruning效率更高