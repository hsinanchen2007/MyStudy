    // https://blog.csdn.net/pengwill97/article/details/80879387
    class Solution {
        public String longestPrefix(String s) {
            int len = s.length();
            long p = 367;
            long mod = 1000000007;
            long[] hash = new long[s.length()];
            long[] pow = new long[s.length()];
            for(int i = 0;i < hash.length;i++) {
                hash[i] = i == 0 ? s.charAt(0) : (hash[i - 1] * p + s.charAt(i)) % mod;
                pow[i] = i == 0 ? 1 : (pow[i - 1] * p) % mod;  // 每次pow时都要取模，这个很关键
            }
            for(int i = len - 1;i >= 1;i--) {
                int right = len - i;
                long h1 = hash[i - 1];
                long h2 = hash[len - 1] - hash[right - 1] * pow[len - right];
                h2 = (h2 % mod + mod) % mod;
                if(h1 == h2) {
                    return s.substring(0, i);
                }
            }
            return "";
        }
    }